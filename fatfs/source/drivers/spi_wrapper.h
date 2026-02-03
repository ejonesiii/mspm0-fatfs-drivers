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

#ifndef FATFS_SOURCE_DRIVERS_SPI_WRAPPER_H_
#define FATFS_SOURCE_DRIVERS_SPI_WRAPPER_H_

int spi_set_baud(unsigned int baud);
int spi_init_clk(unsigned int baud);
int spi_init(void);

#endif /* FATFS_SOURCE_DRIVERS_SPI_WRAPPER_H_ */
