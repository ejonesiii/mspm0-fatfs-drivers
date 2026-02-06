/*
 * Author: Evan Jones III
 * Initial Commit: 1/28/2026
 * Last Commit: 1/30/2026
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

#include "ti/driverlib/driverlib.h"

#ifndef FATFS_SOURCE_DRIVERS_SD_H_
#define FATFS_SOURCE_DRIVERS_SD_H_

/* Clock Settings */
#define SD_SLOW_SPEED   400000                  // Slow mode SPI clock speed. Used during card init. (Should be between 100 kHz and 400 kHz)
#define SD_FAST_SPEED   8000000                 // Fast mode SPI clock speed. Used during data transfer. (Should be between 1 MHz and 25 MHz, though the MSPM0 is limited to 16 MHz without the PLL)
//#define SD_CLK_SOURCE                           //TODO ACTUALLY ALLOW FOR DIFFERENT CLOCKS (CURRENTLY ONLY SUPPORTS SYSCLK WHICH LIMITS BAUD TO 16 MHz)

/* SPI Pinout Settings */
#define SD_SPI_PHY      SPI1                    // Selects which SPI PHY interface is used (0 to 2 on G3519)
#define SD_SPI_CS       DL_SPI_CHIP_SELECT_1    // Selects which CS pin is used (0 to 3 on G3519)

/* MMC/SD command */
#define CMD0    (0)         /* GO_IDLE_STATE */
#define CMD1    (1)         /* SEND_OP_COND (MMC) */
#define ACMD41  (0x80+41)   /* SEND_OP_COND (SDC) */
#define CMD8    (8)         /* SEND_IF_COND */
#define CMD9    (9)         /* SEND_CSD */
#define CMD10   (10)        /* SEND_CID */
#define CMD12   (12)        /* STOP_TRANSMISSION */
#define ACMD13  (0x80+13)   /* SD_STATUS (SDC) */
#define CMD16   (16)        /* SET_BLOCKLEN */
#define CMD17   (17)        /* READ_SINGLE_BLOCK */
#define CMD18   (18)        /* READ_MULTIPLE_BLOCK */
#define CMD23   (23)        /* SET_BLOCK_COUNT (MMC) */
#define ACMD23  (0x80+23)   /* SET_WR_BLK_ERASE_COUNT (SDC) */
#define CMD24   (24)        /* WRITE_BLOCK */
#define CMD25   (25)        /* WRITE_MULTIPLE_BLOCK */
#define CMD32   (32)        /* ERASE_ER_BLK_START */
#define CMD33   (33)        /* ERASE_ER_BLK_END */
#define CMD38   (38)        /* ERASE */
#define CMD55   (55)        /* APP_CMD */
#define CMD58   (58)        /* READ_OCR */

#endif /* FATFS_SOURCE_DRIVERS_SD_H_ */
