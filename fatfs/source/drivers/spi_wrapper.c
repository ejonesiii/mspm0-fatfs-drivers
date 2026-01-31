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
 */
int spi_set_clk(unsigned int clk){

}

/*
 * Initialize the SPI interface
 */
int spi_init(void){
    // Initialize the configuration struct
    SPI_SD.bitOrder = DL_SPI_BIT_ORDER_MSB_FIRST;               // SD uses MSB first
    SPI_SD.dataSize = DL_SPI_DATA_SIZE_8;                       // 8-bit/1-byte transmissions
    SPI_SD.frameFormat = DL_SPI_FRAME_FORMAT_MOTO4_POL0_PHA0;   // SD uses the motorola frame format with phase and polarity set to 0
    SPI_SD.mode = DL_SPI_MODE_CONTROLLER;                       // Set to controller
    SPI_SD.parity = DL_SPI_PARITY_NONE;                         // No parity bits
    SPI_SD.chipSelectPin = SD_SPI_CS;                           // CS pin select (Configured in sd.h)

    // Initialize SPI clock in slow clock mode
    spi_set_clk(SD_SLOW_SPEED);
    return 0;
}



