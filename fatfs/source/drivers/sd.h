/*
 * Author: Evan Jones III
 * Initial Commit: 1/28/2026
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

#ifndef FATFS_SOURCE_DRIVERS_SD_H_
#define FATFS_SOURCE_DRIVERS_SD_H_

#define SD_SLOW_SPEED   400000      // Slow mode SPI clock speed (used during card init. Should be between 100 kHz and 400 kHz)
#define SD_FAST_SPEED   8000000     // Fast mode SPI clock speed (used during data transfer. Should be between 1 MHz and 25 MHz)

#define SD_SPI_PHY      1           // Selects which SPI PHY interface is used
#define SPI_CS          1           // Selects which CS pin is used (0 to 3)

#endif /* FATFS_SOURCE_DRIVERS_SD_H_ */
