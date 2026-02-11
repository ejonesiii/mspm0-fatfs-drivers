/*
 * Author: Evan Jones III
 * Initial Commit: 1/22/2026
 * Last Commit: 1/28/2026
 *
 * Drivers for the MSPM0 necessary to use the FatFS library.
 * Library assumes the use of the MSPM0 driverlib to create an SPI interface named "SPI_SD"
 *
 * This work is covered under the MIT License
 * For license information, refer to the license file
 *
 * Written using Code Composer Studio v12.
 * No AI was used in the creation of this code.
 */
#include <stdint.h>
#include "fatfs/source/diskio.h"
#include "fatfs/source/ff.h"
#include "ti/driverlib/driverlib.h"
#include "fatfs/source/drivers/sd.h"
#include "fatfs/source/drivers/spi_wrapper.h"

/* Defines */
#define DEV_MMC     0                                                   // Map MMC/SD card to physical drive 0


/* Misc Functions */
/*
 * Delays the clock by specified number of ms
 * ms: milliseconds to delay
 */
void delay_ms(unsigned int ms){
    unsigned int freq;
    freq = (unsigned int)DL_SYSCTL_getCurrentSYSOSCFreq();
    delay_cycles(freq/(1000*ms));
}

/*
 * Send a command to the SD Card
 * cmd: The command to be sent
 * arg: Any arguments to be sent with the command
 */
static BYTE send_cmd(BYTE cmd, DWORD arg){
    BYTE crc, res, n;                                               // CRC, result, and number of loop variables

    // Check to see if command is SDC specific
    if (cmd & 0x80) {                                               // If command is ACMDx (SDC command), send CMD55 first with no arg
        cmd &= 0x7F;                                                // Flip Bit 7 to be zero
        res = send_cmd(CMD55, 0);                                   // Send CMD55
        if (res > 1) return res;                                    // If return is not 0 or 1, break and return error
    }

    // Send command
    DL_SPI_transmitDataBlocking8(SD_SPI_PHY,(uint8_t)cmd);          // Send command first
    DL_SPI_transmitDataBlocking32(SD_SPI_PHY,(uint32_t)arg);        // Transmit argument second
    crc = 0x01;                                                     // CRC-16 isn't checked in SPI mode, so send dummy in most cases
    if (cmd == CMD0) crc = 0x95;                                    // Valid CRC for CMD0(0)
    if (cmd == CMD8) crc = 0x87;                                    // Valid CRC for CMD8(0x1AA)
    DL_SPI_transmitDataBlocking8(SD_SPI_PHY,(uint8_t)crc);          // Transmit CRC

    // Wait for response
    if(cmd==CMD12){                                                 // If CMD12, simply discard first byte
        DL_SPI_transmitDataBlocking8(SD_SPI_PHY,0xFF);              // Send 0xFF to SPI buffer (Keep POCI HIGH)
        DL_SPI_receiveDataBlocking8(SD_SPI_PHY);                    // Receive byte
    }
    n = 10;
    do{                                                             // Wait 10 bytes for a response
        DL_SPI_transmitDataBlocking8(SD_SPI_PHY,0xFF);              // Send 0xFF to SPI buffer (Keep POCI HIGH)
        res = (BYTE)DL_SPI_receiveDataBlocking8(SD_SPI_PHY);        // Receive byte
    }
    while((res&0x80)&&--n);                                         // Check to see if byte is valid (Will start with 0b0xxx xxxx)
    return res;
}


/* Main Functions */

/*
 * Initializes the SD card and returns the SD card status
 * pdrv: Selects which drive to be used (Currently only supports single drive mode, so it should always be 0)
 */
DSTATUS disk_initialize (BYTE pdrv){
    char i;
    // Only supports drive 0 (Single drive mode), so throw error if anything but 0
    if(pdrv!=0){
        return STA_NOINIT;
    }
    // Enable SPI interface
    spi_init();

    // Delay 10 ms to allow system to settle
    delay_ms(10);

    // Send 0xFF 10 times total to init the SD card
    DL_SPI_setRepeatTransmit(SD_SPI_PHY,9);                         // Set SPI to transmit 10 times
    DL_SPI_transmitDataBlocking8(SD_SPI_PHY,0xFF);                  // Send 0xFF to SPI buffer
    DL_SPI_setRepeatTransmit(SD_SPI_PHY,0);                         // Disable repeat transmit

    //TODO Determine card type (SDv2, SDv1, or MMC)
    DL_SPI_transmitDataBlocking8(SD_SPI_PHY,CMD0);
    if(DL_SPI_receiveDataBlocking8(SD_SPI_PHY)==1){

    }

    //TODO REPORT BACK CARD TYPE IF CONNECTION SUCCESSFUL AND CHANGE TO HIGH SPEED MODE (8 MHz to 25 MHz)

}

DSTATUS disk_status (BYTE pdrv){

}

DRESULT disk_read (BYTE pdrv, BYTE* buff, LBA_t sector, UINT count){

}

DRESULT disk_write (BYTE pdrv, const BYTE* buff, LBA_t sector, UINT count){

}

DRESULT disk_ioctl (BYTE pdrv, BYTE cmd, void* buff){

}



