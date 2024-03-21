#include "gpio.h"
#include "uart.h"
#include "framebuffer.h"

void printf(char *str) {
	uart_puts(str);
}



int main()
{
    init_framebuffer(); // You can use framebuffer, width, height and pitch variables available in framebuffer.h
    
    // Draw a (Green) pixel at coordinates (10,10)
    drawPixel(10,10,0xFF00FF00);

    // Print a message to the UART.
    printf("we printed a green pixel on the screen!!\n");
    
    return 0;
}
