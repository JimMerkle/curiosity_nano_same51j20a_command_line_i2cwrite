/*******************************************************************************
  Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This file contains the "main" function for a project.

  Description:
    This file contains the "main" function for a project.  The
    "main" function calls the "SYS_Initialize" function to initialize the state
    machines of all modules in the system
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stddef.h>                     // Defines NULL
#include <stdbool.h>                    // Defines true
#include <stdlib.h>                     // Defines EXIT_FAILURE
#include <stdio.h>
#include <stdint.h>
#include "definitions.h"                // SYS function prototypes
#include "command_line.h"

// Implement a getchar function, needed for Command Line
// If character available, return character, else return EOF
int __io_getchar(void) {
    uint8_t data;
    if(SERCOM5_USART_ReadCountGet()) {
        // We have data
        SERCOM5_USART_Read(&data, sizeof(data));
        return data;
    } else return EOF;
} // __io_getchar())



// *****************************************************************************
// *****************************************************************************
// Section: Main Entry Point
// *****************************************************************************
// *****************************************************************************

int main ( void )
{
    /* Initialize all modules */
    SYS_Initialize ( NULL );
    SYSTICK_TimerStart();
    //-------------------------------------------------------
    // Before we start TC0, reconfigure the period
    /* TC0 is configured within the clock configurator to use GCLK2 (1 MHz) */
    /* Configure TC0 timer period */
    TC0_REGS->COUNT32.TC_CC[0U] = 0xFFFFFFFFU;
    /* Clear all interrupt flags */
    TC0_REGS->COUNT32.TC_INTFLAG = (uint8_t)TC_INTFLAG_Msk;
    while((TC0_REGS->COUNT32.TC_SYNCBUSY) != 0U)
    { /* Wait for Write Synchronization */ }
    TC0_TimerStart(); // microsecond counter
    
    // Initialize Command Line
    cl_setup();

    while ( true )
    {
        /* Maintain state machines of all polled MPLAB Harmony modules. */
        //SYS_Tasks ( ); // No tasks at this time
        cl_loop();              // Check for character, if available, process it
        SYSTICK_DelayMs(50);    // Slow things down a bit
    }

    /* Execution should not come here during normal operation */

    return ( EXIT_FAILURE );
}


/*******************************************************************************
 End of File
*/

