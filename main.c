#include <stm32f4xx.h>
#include "ff.h"

/*
 * PC4 = CS					pink
 * PC5 = CD (card detect)	<none>
 * PA5 = SCK				orange
 * PA6 = MISO				white
 * PA7 = MOSI				gray
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
 */

int printf ( char * s )
{
	return ( 0 );
};

void Delay (__IO uint32_t nCount)
{
	while(nCount--)
	{
	}
}

unsigned long get_fattime ( )
{
	return ( 0 );
};

/**
 * @brief  This function handles SysTick Handler.
 * @param  None
 * @retval None
 */

static uint8_t toggle = 0;
void SysTick_Handler(void)
{
	disk_timerproc ( );
};

int main ( )
{
	FATFS FatFs;
	FIL fil;
	FRESULT res;

	SystemInit ( );

	if ( SysTick_Config ( SystemCoreClock / 2 / 100 ) ) // period 1/100 sec = 10msec
	{
		/* Capture error */
		while ( 1 );
	}

	while ( 1 )
	{
		char buffer[6];

		printf ( "Mounting volume...");
		res = f_mount ( &FatFs, "", 1 ); // mount the drive
		if ( res )
		{
			printf ( "error occured!\n" );
			while ( 1 );
		}
		printf ( "success!\n");

		printf ( "Opening file: \"hello.txt\"...");
		res = f_open ( &fil, "hello.txt", FA_OPEN_EXISTING | FA_WRITE | FA_READ ); // open existing file in read and write mode
		if ( res )
		{
			printf ( "error occured!\n" );
			while ( 1 );
		}
		printf ( "success!\n" );

		f_gets ( buffer, 6, &fil );

		printf ( "I read: \"" );
		printf ( buffer );
		printf ( "\"\n" );

		f_puts ( buffer, &fil );

		f_close ( &fil ); // close the file
		f_mount ( 0, "", 1 ); // unmount the drive

		Delay ( 50000 );
	}
	return ( 0 );
}
