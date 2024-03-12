/*
CPSC 359 Assignment 3

Authors:
Zachary Kokot (UCID: 30115582)
Rainbow Peng (UCID: 30113718)
*/

#include "gpio.h"
#include "uart.h"

// Macros for the Latch(LAT), Data(DAT), and Clock(CLK) GPIO pin offsets.
#define LAT 9
#define DAT 10
#define CLK 11

// Macros for the read and write function codes for the RPi GPIO pins.
#define READ 0b000
#define WRITE 0b001

// Macro for the clock register.
#define CLO_REG 0x7E003004

// Array of pointers to all GPIO function select registers.
volatile unsigned int* gpfs[] = {GPFSEL0, GPFSEL1, GPFSEL2, GPFSEL3, GPFSEL4, GPFSEL5};

// Integer (treated as a bit string) to keep track of the current button state.
int current;

// Integer (treated as a bit string) to keep track of the previous button state.
int previous;

// Array of button names in the order they are read from the controller.
char buttonNames[16][20] = {"B","Y","Select","Start", "Joy-pad Up",
                            "Joy-pad Down", "Joy-pad Left", "Joy-pad Right", 
                            "A", "X", "Left Shoulder", "Right Shoulder"};

// Initializes a passed GPIO line with a passed function code.
void initGPIO(int line, int fCode)
{
    int funcSetReg = (line/10)%10; // Determines function set register.
    int maskShift = 3*(line%10); // Determines shift of bit mask.

    // Sets the function of the passed line.
    *(gpfs[funcSetReg]) = (*(gpfs[funcSetReg]) & - (0b111 << maskShift)) | (fCode << maskShift);
}

// Writes a value to the latch line.
void writeLatch(int value)
{
    // Sets pin 9 (latch) to 1.
    if(value)
        *GPSET0 = 1 << LAT;
    // Clears pin 9 to 0.
    else
        *GPCLR0 = 1 << LAT;
}

// Writes a value to the clock line.
void writeClock(int value)
{
    // Sets pin 11 (clock) 1.
    if(value)
        *GPSET0 = 1 << CLK;
    // Clears pin 11 to 0.
    else
        *GPCLR0 = 1 << CLK;
}

// Reads the value on the data line.
int readData()
{
    return((*GPLEV0 >> DAT) & 1);
}

// Waits for a time interval, in microseconds, passed as a parameter.
void wait(int muSec)
{
    unsigned *clo = (unsigned*)CLO_REG;
    unsigned c = *clo + muSec; // micro Secs

    while(c > *clo);
}

// Reads the current status of the buttons on the SNES controller.
int readSNES()
{
    // Initializing all buttons as pressed.
    int buttons = 0b0000000000000000;

    // Writes 1 to the clock and latch lines.
    writeClock(1);
    writeLatch(1);

    // Sleeps the core for 12 micro seconds with latch high
    // to signal to the SNES controller we wish to sample the buttons.
    wait(12);
    writeLatch(0);

    for(int i = 0; i < 16; i++)// Pulse loop (reading from the controller).
    {
        wait(6);
        writeClock(0); // Falling edge.
        wait(6);
        buttons = buttons | (readData() << i); // Read bit
        writeClock(1); // Rising edge(New cycle).
    }

    return buttons;
}

// Prints a string to the screen.
void printMessage(char *str) {
	uart_puts(str);
}

int main()
{
    // Initializing SNES lines.
    initGPIO(LAT, WRITE); // Set latch line to output.
    initGPIO(DAT, READ); // Set data line to input.
    initGPIO(CLK, WRITE); // Set clock line to output.

    // Print initialization message.
    printMessage("\n\nCreated by: Zachary Kokot and Rainbow Peng.\n\n");
    printMessage("Please press a button...\n\n");

    // Initializes previous button states and current button states to 1 (not pressed).
    previous = 0b1111111111111111;
    current = 0b1111111111111111;

    // Reads SNES controller state to initialize the buttons current state.
    // ands together 20 seperate values for the button states to remove
    // noise. (An attempt to fix the problem of bounce in the buttons.)
    for(int i = 0; i < 20; i++)
        current = current & readSNES();

    // Loops while the start button is not pressed.
    while((current >> 3) & 1)
    {
        // Stores current button state to be used to check for state change.
        previous = current;
        current = 0b1111111111111111;
        // Read SNES controller state to update current state.
        for(int i = 0; i < 20; i++)
            current = current & readSNES();

        // Checks if any of the button states have changed from not pressed to pressed.
        for(int i = 0; i < 16 ; i ++)
        {
            // If the button state has changed print a message indicating which button
            // was pressed and prompt user to press another.
            if(!(current >> (i) & 1) && i != 3 && (previous >> i & 1) != (current >> i & 1))
            {
                printMessage("You have pressed ");
                printMessage(buttonNames[i]);
                printMessage("\n");

                printMessage("\nPlease press a button...\n\n");
            }
        }       
    }

    // Once start has been pressed the loop exits and a program terminating message is printed.
    printMessage("Program is terminating...");

    return 0;
}
