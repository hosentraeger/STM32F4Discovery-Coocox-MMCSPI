STM32F4Discovery-Coocox-MMCSPI
==============================
This CooCox project connects a SD card to the STM32F4-Discovery board via SPI.

pin connections:

 * PC4 = CS
 * PC5 = CD (card detect)
 * PA5 = SCK
 * PA6 = MISO
 * PA7 = MOSI
 *



 * SD Card
 * ----------\	9
 *           |	1			CS
 *           |	2			MOSI
 *           |	3			GND
 *           |  4			VDD
 *           |  5			SCK
 *           |  6			GND
 *           |  7/8			MISO
 *------------
 *
 *
 * micro SD
 *
 *     |-\
 * --\ |  \--
 *    V     |	1			./.
 *          |	2			CS
 *          |	3			MOSI
 *          |	4			VDD
 *          |	5			SCK
 *          |	6			GND
 *          |	7			MISO
 *          |	8			./.
 *----------
