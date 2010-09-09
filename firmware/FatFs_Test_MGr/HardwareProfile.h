#ifndef HARDWARE_PROFILE_H
#define HARDWARE_PROFILE_H

    /*******************************************************************/
    /******** USB stack hardware selection options *********************/
    /*******************************************************************/
    //This section is the set of definitions required by the MCHPFSUSB
    //  framework.  These definitions tell the firmware what mode it is
    //  running in, and where it can find the results to some information
    //  that the stack needs.
    //These definitions are required by every application developed with
    //  this revision of the MCHPFSUSB framework.  Please review each
    //  option carefully and determine which options are desired/required
    //  for your application.

    //#define USE_SELF_POWER_SENSE_IO
    #define tris_self_power     TRISAbits.TRISA2    // Input
    #define self_power          1

    //#define USE_USB_BUS_SENSE_IO
    #define tris_usb_bus_sense  TRISBbits.TRISB5    // Input
    #define USB_BUS_SENSE       1

    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/
    /******** Application specific definitions *************************/
    /*******************************************************************/
    /*******************************************************************/
    /*******************************************************************/

    #define GetSystemClock()            80000000UL
    #define GetPeripheralClock()        (GetSystemClock())
    #define GetInstructionClock()       (GetSystemClock())

    /** LED ************************************************************/
    #define mInitAllLEDs()      LATE = 0xFFF0; TRISE = 0xFFF0;

    #define mLED_1              LATEbits.LATE0
    #define mGetLED_1()         mLED_1
    #define mLED_1_On()         mLED_1 = 0;
    #define mLED_1_Off()        mLED_1 = 1;
    #define mLED_1_Toggle()     mLED_1 = !mLED_1;

    /** SWITCH *********************************************************/
    #define mInitSwitch2()      TRISEbits.TRISE7=1;
    #define mInitAllSwitches()  mInitSwitch2()
    #define sw2                 PORTEbits.RE7

#endif  //HARDWARE_PROFILE_H
