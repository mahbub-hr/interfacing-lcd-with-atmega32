# interfacing-lcd-with-atmega32
This demo code shows how to print a string to a LCD using atmega32 microcontroller. _lcd.h_ contains the low level code for interacting with atmega32 microcontroller.

## To Run 
First, install winavr on your computer. Then,
On command line:

 make all = Make software.

 make clean = Clean out built project files.

 make coff = Convert ELF to AVR COFF.

 make extcoff = Convert ELF to AVR Extended COFF.

 make program = Download the hex file to the device, using avrdude.
                Please customize the avrdude settings below first!

 make debug = Start either simulavr or avarice as specified for debugging, 
              with avr-gdb or avr-insight as the front end for debugging.

 make filename.s = Just compile filename.c into the assembler code only.

 make filename.i = Create a preprocessed source file for use in submitting
                   bug reports to the GCC project.

 To rebuild project do "make clean" then "make all".
