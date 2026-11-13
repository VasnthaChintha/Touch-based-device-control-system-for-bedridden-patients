#include <lpc21xx.h>       // Include LPC2148 microcontroller register definitions
#include "define.h"        // Include user-defined data types and common macros
#include "kpm_defines.h"   // Include keypad matrix (KPM) configuration definitions
unsigned int kpmLUT[4][4]={{'1','2','3','+'},
                           {'4','5','6','-'},
                           {'7','8','9','*'},
                           {'*','0','#','/'}}; // Declares a 4x4 array to store keypad values

// KEYPAD MATRIX INITIALIZATION
void intialize_kpm(void)
{
	WRITEBYTE(IODIR1,ROW0,0xf); // Configure keypad row pins as output and column pins as input
}
// KEYPAD COLUMN SCANNING
int ColScan(void)
{
	if (((IOPIN1 >> COL0) & 15) < 15) // Read the four column pins and extract their status
  {
		return 0; // Return 0 if any column pin is LOW
  }
	else
  {
		return 1; // Return 1 if all column pins are HIGH
  }
}
// KEYPAD ROW SCANNING FUNCTION
int rowcheck(void)
{
	int rno;
	// Scan all four keypad rows one by one
	for (rno = 0; rno <= 3; rno++)
	{
		WRITENIBBLE(IOPIN1, ROW0, ~(1 << rno)); // Make the selected row LOW and keep the remaining rows HIGH
		if (ColScan() == 0) // Check whether any column pin goes LOW
		{
			break; // Exit the loop when a key press is detected
		}
	}
  WRITENIBBLE(IOPIN1, ROW0, 0x0); // Set all four row pins LOW after scanning
  return rno; // Return the detected row number
}
// KEYPAD COLUMN SCANNING FUNCTION
int colcheck(void)
{
	int cno;
  // Scan the keypad columns one by one
	for (cno = 0; cno < 3; cno++)
  {        
		if (STATUSBIT(IOPIN1, (COL0 + cno)) == 0) // Check whether the current column pin is LOW
		{
			break; // Exit the loop when a pressed key is detected
		}
	}
  return cno; // Return the detected column number
}
// KEYPAD SCANNING FUNCTION
int KeyScan(void)
{
	int rno, cno;
	int keyv;
	while (ColScan()); // Wait until a key is pressed    
	rno = rowcheck(); // Identify the row number of the pressed key
	cno = colcheck(); // Identify the column number of the pressed key
	keyv = kpmLUT[rno][cno]; // Retrieve the corresponding key value from the lookup table
	return keyv; // Return the detected key value	
}
