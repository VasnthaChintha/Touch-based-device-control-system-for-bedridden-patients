#include <lpc21xx.h>       // Include LPC2148 microcontroller register definitions
#include "delay.h"         // Include delay function declarations
#include "define.h"        // Include user-defined data types and common macros
#include "lcd_defines.h"   // Include LCD command and pin definitions
#include "lcd.h"           // Include LCD function declarations
// LCD COMMAND FUNCTION
void cmdLCD(unsigned char cmd)
{
	IOCLR0 = (1 << RS); // Clear the RS pin to select LCD command register (RS = 0)
	writeLCD(cmd); // Send the command to the LCD
}
// LCD DATA/COMMAND WRITE FUNCTION
void writeLCD(unsigned char data)
{
	IOCLR0 = (1 << RW); // Clear the RW pin to select LCD write operation (RW = 0)
	WRITEBYTE(IOPIN0, LCD_DATA, data); // Send the 8-bit data to the LCD data pins
	IOSET0 = (1 << EN); // Set the Enable pin HIGH to initiate data transfer
	delay_us(1); // Provide a short enable pulse delay
	IOCLR0 = (1 << EN); // Set the Enable pin LOW to complete data transfer
	delay_ms(2); // Wait for the LCD to complete the write operation
}
// LCD CHARACTER DISPLAY FUNCTION
 void charLCD(unsigned char ascii)
{
	IOSET0=(1<<RS); // Set the RS pin HIGH to select LCD data register (RS = 1)
	writeLCD(ascii); // Send the ASCII character to the LCD for display
} 
// LCD INITIALIZATION FUNCTION
void intialize_LCD(void)
{
	WRITEBYTE(IODIR0, LCD_DATA, 0xFF); // Configure all 8 LCD data pins as output
	IODIR0 |= (1 << RS);// Configure RS pin as output
	IODIR0 |= (1 << RW); // Configure RW pin as output
	IODIR0 |= (1 << EN); // Configure Enable pin as output
	delay_ms(15); // Wait for 15 ms to allow the LCD to power up
	cmdLCD(MODE_8BIT_LINE1); // Initialize LCD in 8-bit mode with 2-line display
	delay_ms(1); // Provide a short enable pulse delay
	cmdLCD(MODE_8BIT_LINE1); // Repeat initialization command for reliable LCD setup
	delay_ms(1); // Provide a short enable pulse delay
	cmdLCD(MODE_8BIT_LINE1); // Send initialization command once again
	cmdLCD(MODE_8BIT_LINE2); // Configure LCD for 8-bit mode and 2-line operation
	cmdLCD(DIS_ON_CUR_OFF); // Turn ON display and turn OFF cursor
	cmdLCD(CLEAR_LCD); // Clear all characters from the LCD display
	cmdLCD(SHIFT_CUR_RIGHT);  // Shift cursor position to the right after each character
}
// LCD STRING DISPLAY FUNCTION
void strLCD(signed char *str) 
{
	// Continue displaying characters until the null terminator is reached
	while(*str)
	{
		charLCD(*str); // Send the current character to the LCD
		str++; // Move the pointer to the next character in the string
	}
}
// LCD INTEGER DISPLAY FUNCTION
void intLCD(int n)
{
	int i=0;
	int a[10];
	if(n==0) // Check whether the input number is zero
	{
		charLCD('0'); // Display '0' on the LCD
	}
	else
	{
		// Extract each digit and store its ASCII value
		// Digits are stored in reverse order
		while(n)
		{
			a[i++]=(n%10)+48;
			n=n/10; // Remove the last digit from the number
		}
		// Display the extracted digits in the correct order
		for(--i;i>=0;i--)
		{
			charLCD(a[i]); // Send each ASCII digit to the LCD
		}
	}
}
