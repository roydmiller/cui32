# Introduction #

If you are new to the CUI32, please see the following...
  * StickOS BASIC User's Guide:  http://www.cpustick.com/stickos.htm
  * Getting started with StickOS: http://www.cpustick.com/examples.htm and in text format:  http://www.cpustick.com/text.htm
  * Other examples will be posted in the downloads and source repositories on this website - feel free to contribute your own!

For those interested in using the CUI32 in a classroom or other prototyping context requiring the board to be re-usable for multiple projects, please note that if you put standard 0.1" male headers on the board, then most of Seeed Studio's "Electronic Brick" modules will plug right into the CUI32's analog pin triplets, as will Phidgets analog sensors - these both use pinouts that are compatible with the CUI32.

  * Electronic Bricks (various sensors, sound in/out, relays, etc.): http://www.seeedstudio.com/depot/index.php?main_page=advanced_search_result&search_in_description=1&keyword=brick&x=0&y=0&search_in_description=0
    * All the 3-pin devices should work fine - just use the [Half buckled 3-wire cable](http://www.seeedstudio.com/depot/electronic-brick-half-buckled-3-wire-cable-p-488.html?cPath=48_57) to plug them into the CUI32.

  * Phidgets sensors (many of their analog sensors also use the 3-pin wires): http://www.phidgets.com/products.php?category=1
    * You may need to trim some plastic off their included cables, and you should make sure the sensors can work on 3.3V (most can).


These types of things allow very simple plugging in of sensors and actuators, no soldering needed for reconfiguring prototypes, etc.  Note that you have to connect either 3.3V or 5V to all of the "V+" pins (the middle pins of each of the analog input pin triplets) by using a jumper or small piece of wire on the V+ selector (located next to the footprint for the USB host connector).




# Details #

For advanced users - How to use the CUI32 `BootLoader`


The CUI32 ships with a custom version of Microchip's HID `BootLoader` installed. When your CUI32 is turned on or reset, it first starts running the `BootLoader` code, which checks to see if it should wait for an upload of new firmware from the host computer, or skip immediately to running the StickOS (or whatever firmware you have installed).  There are three things the `BootLoader` checks for - if any one of these is true then it will enter the `BootLoader`:

  * PROG button held down during powerup (this is the **normal method** - you can just hold the PROG down while pushing RESET, make sure to let go of the PROG button last)
  * FLASH memory other than the `BootLoader` is blank (it was erased somehow)
  * Software Key has correct value (a host computer could set this flag and then issue a soft-reset command to allow firmware updates without needing to push a button)

If any of these are true, the CUI32 will jump into `BootLoader` mode (and the STATUS LED will start flashing much quicker than StickOS' "heartbeat"). If none of them are true, then it jumps to the beginning of your normal firmware (StickOS or whatever), and starts executing it.  In `BootLoader` mode, the CUI32 will talk to your computer as a generic HID device - this means you do not need to install any drivers on the PC side.  The windows program for uploading new firmware to the CUI32 is the Microchip HID `Bootloader` application - this comes with Microchip's USB framework ( http://www.microchip.com/usb/ ), or you can directly download v2.6 of this program here:

http://code.google.com/p/cui32/downloads/detail?name=MicrochipHIDBootLoader2.6a.zip

Once you have your CUI32 in the `BootLoader` mode, you run this program on your PC, and then you can send the new .HEX file you want to use down to the CUI32. Once you're done programming, you can either reset the CUI32 by pressing and releasing the RESET button, or manually by removing power (unplugging the USB cable) and rebooting the board.  The CUI32 will then run the new firmware you just programmed (until you re-program it via this procedure again).

There are instructions for how to do this on OS X or Linux here (the only difference is the host program on your computer used to update the CUI32 firmware is a command-line utility called "ubw32"):
http://www.paintyourdragon.com/uc/ubw32/index.html