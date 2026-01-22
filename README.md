# MSPM0 FatFS

An attempt to make a general implementation of FatFS for the MSPM0. Very much a work in progress and not functional as of now. For more information please visit [my website](https://jerc-alaska.com/blog/msp-m0_fatfs/)

## Pinout in my main.c example
|Function|MSPM0G3519 Port/Pin|
|---|---|
|POCI (Peripheral Out, Controller In)|PB7 (Pin 41)|
|PICO (Peripheral In, Controller Out)|PB8 (Pin 42)|
|SCLK (Serial Clock)|PB31 (Pin 32)|
|CS (Chip Select)|PB12 (Pin 46)|

*Please note that the use of PICO and POCI is standard in MSPM0 TI documentation, and will be reflected in this post.

## License
Works not explicitly covered by another license are covered by the MIT copyright license. For more information, see the LICENSE file.


