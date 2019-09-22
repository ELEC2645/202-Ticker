/* 
 
2645_Ticker
 
Sample code from ELEC2645
 
Demonstrates how to use a ticker to generate a periodic timer interrupt
 
(c) Craig A. Evans, University of Leeds, Jan 2016
 
*/ 
 
#include "mbed.h"
 
// Create objects for ticker and red LED
Ticker ticker;
DigitalOut red_led(LED_RED); // TODO
 
// flag - must be volatile as changes within ISR
// g_ prefix makes it easier to distinguish it as global
volatile int g_timer_flag = 0;
 
// function prototypes
void timer_isr();
 
int main()
{
    // set-up the ticker so that the ISR it is called every 0.5 seconds
    ticker.attach(&timer_isr,0.5);
    // the on-board RGB LED is a common anode - writing a 1 to the pin will turn the LED OFF
    red_led = 1;
 
    while (1) {
 
        // check if flag is set i.e. interrupt has occured
        if (g_timer_flag) {
            g_timer_flag = 0;  // if it has, clear the flag
 
            // send message over serial port - can observe in CoolTerm etc.
            printf("Tick \n");
            // DO TASK HERE
    
        }
 
        // put the MCU to sleep until an interrupt wakes it up
        sleep();
 
    }
}
 
// time-triggered interrupt
void timer_isr()
{
    g_timer_flag = 1;   // set flag in ISR
}