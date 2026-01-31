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

#include "fatfs/source/diskio.h"
#include "fatfs/source/ff.h"
#include "ti/driverlib/driverlib.h"
#include "fatfs/source/drivers/sd.h"
#include "fatfs/source/drivers/spi_wrapper.h"

/* Misc Functions */
/*
 * Delays the clock by specified number of ms
 *
 * ms: milliseconds to delay
 */
void delay_ms(unsigned int ms){
    unsigned int freq;
    freq = (unsigned int)DL_SYSCTL_getCurrentSYSOSCFreq();
    delay_cycles(freq/(1000*ms));
}


/* Main Functions */

/*
 * Initializes the SD card and returns the SD card status
 *
 * pdrv: Selects which drive to be used (Currently only supports single drive mode, so it will always be 0)
 */
DSTATUS disk_initialize (BYTE pdrv){
    // Only supports drive 0 (Single drive mode), so throw error if anything but 0
    if(pdrv!=0){
        return STA_NOINIT;
    }
    //Enable SPI interface
    spi_init();
    //Delay 10 ms to allow system to settle
    delay_ms(10);
    //TODO SEND 0xFF 10 TIMES TOTAL TO INIT THE SD CARD

    //TODO DETERMINE CARD TYPE (SDv2, SDv1, or MMC)

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



