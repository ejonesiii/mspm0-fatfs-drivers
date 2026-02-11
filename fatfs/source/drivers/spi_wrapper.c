/*
 * Author: Evan Jones III
 * Initial Commit: 1/28/2026
 * Last Commit: 1/28/2026
 *
 * Functions to initialize and operate the SPI interface on the MSPM0 using driverlib
 * Library assumes the use of the MSPM0 driverlib to create an SPI interface named "SPI_SD"
 *
 * This work is covered under the MIT License
 * For license information, refer to the license file
 *
 * Written using Code Composer Studio v12.
 * No AI was used in the creation of this code.
 */

#include "ti/driverlib/driverlib.h"
#include "fatfs/source/drivers/sd.h"

// Create a configuration struct to be referenced by the functions
DL_SPI_Config SPI_SD;
DL_SPI_ClockConfig SPI_SD_CLK;

/*
 * Set the clock speed of the SPI Interface to slow mode
 * baud: The desired baud rate
 */
int spi_set_baud(unsigned int baud){
    unsigned int freq, div;
    freq = (unsigned int)DL_SYSCTL_getCurrentSYSOSCFreq();      // Retrieve the system clock frequency
    div = (freq/(2*baud))-1;                                    // Calculate the division ratio for the clock divider
    DL_SPI_setBitRateSerialClockDivider(SD_SPI_PHY, div);       // Set baud rate using divider
    return 0;
}

/*
 * Initialize the SPI clock
 * baud: The desired baud rate
 */
int spi_init_clk(unsigned int baud){
    SPI_SD_CLK.clockSel = DL_SPI_CLOCK_BUSCLK;                  // Set clock to the BUSCLK for maximum clock rate
    SPI_SD_CLK.divideRatio = DL_SPI_CLOCK_DIVIDE_RATIO_1;       // No clock division
    DL_SPI_setClockConfig(SD_SPI_PHY,&SPI_SD_CLK);              // Config the clock
    return spi_set_baud(baud);                                  // Set the baud rate of the clock
}

/*
 * Initialize the SPI interface
 */
int spi_init(void){
    // Turn on SPI interface
    DL_SPI_enablePower(SD_SPI_PHY);

    // Initialize the configuration struct
    SPI_SD.bitOrder = DL_SPI_BIT_ORDER_MSB_FIRST;               // SD uses MSB first
    SPI_SD.dataSize = DL_SPI_DATA_SIZE_8;                       // 8-bit/1-byte transmissions
    SPI_SD.frameFormat = DL_SPI_FRAME_FORMAT_MOTO4_POL0_PHA0;   // SD uses the motorola frame format with phase and polarity set to 0
    SPI_SD.mode = DL_SPI_MODE_CONTROLLER;                       // Set to controller
    SPI_SD.parity = DL_SPI_PARITY_NONE;                         // No parity bits
    SPI_SD.chipSelectPin = SD_SPI_CS;                           // CS pin select (Configured in sd.h)

    // Initialize SPI clock in slow clock mode
    spi_init_clk(SD_SLOW_SPEED);

    // Initialize the actual interface
    DL_SPI_init(SD_SPI_PHY,&SPI_SD);

    // Set up the interrupt
    DL_SPI_setFIFOThreshold(SD_SPI_PHY, DL_SPI_RX_FIFO_LEVEL_1_2_FULL, DL_SPI_TX_FIFO_LEVEL_1_2_EMPTY);

    // Enable the interface
    DL_SPI_enable(SD_SPI_PHY);
    return 0;
}

int spi_dma_tx(){
    //TODO: Init DMA process

    //TODO: Point to data being transmitted

    //TODO: Reset DMA when done
}

int spi_dma_rx(){

}

int spi_tx_block(){
    //TODO: Add command information to be transmitted to SD card

    //TODO: Call SPI DMA Tx function

    //TODO: Error handling?
    return 0;
}

int spi_rx_block(){
    //TODO: Add command information to be transmitted to SD card

    //TODO: Call SPI DMA Rx function

    //TODO: Error handling?
    return 0;
}




