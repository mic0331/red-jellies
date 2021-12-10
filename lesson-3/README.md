# Lesson 3 Assignments

## Exercise 3a: Investigate Project Board

Look at the documents for the board you are considering for your final project (or any ST
Discovery Board), draw the hardware block diagram for the board. For peripherals, note the
communication paths (SPI, I2C, etc).

Look at the datasheet for the processor and other documents. Answer these questions:
* What kind of processor is it?
* How much Flash and RAM does it have? Any other memory types?
* Does it have any special peripherals? (List 3-5 that you noted as being interesting.)
* Does it have a floating point unit?
* If it has an ADC, what are the features?

## Assignment Submission

The board I decided to use is the Nucleo-F401RE - it contains everything needed for rapid prototyping.

![image](https://user-images.githubusercontent.com/2216608/145589678-e08de34a-7b85-4c2b-aecc-df6269e073e8.png)

### What kind of processor is it?

The processor is an STM32F411xC serie - ARM Cortex M4

### How much Flash and RAM does it have? Any other memory types?

Flash : 512 Kb
SRam : 128 Kb

### Does it have any special peripherals? (List 3-5 that you noted as being interesting.)

The board contain all the typical peripherals SPI, I2C, UART, PWM and SMBUS

### Does it have a floating point unit?

The corted M4 features a Floating point unit (FPU) single precision which supports all Arm single-precision data-rpocessing instructions and data types.

### If it has an ADC, what are the features?

The IC is equiped with a 12-bit analog-to-digital converter embeded and shares across up to 16 channels.
It can perform single-shot or scan mode.
The ADC can be served by the DMA.
The ADC can be triggered by serveral timers.

## Exercise 3b: SPI Flash Test Code

Unfortunately, the SPI Flash we need to test the Key-Value storage system is on backorder. Create a small simulator so you can test the KV code.

Here is the SPI Flash information. https://www.digikey.com/en/products/detail/winbond-electronics/W25Q80DVSNIG-TR/5154948

We are going to use ST’s Standard Peripheral Flash Driver so here is the header file: https://drive.google.com/file/d/12dw-pZiKiK1vi4gv49W1x6np5uzCH_cV/view?usp=sharing

Your assignment is to create a small module that compiles runs on your computer that implements your flash simulator. You will also need a main file to test out your simulator. Important notes: You don’t need a full Flash simulator, only what is necessary to test the KV code. You aren’t writing the KV code, only testing it. You do not need to use CPPUTest or other unit test framework. If you are writing more than 50 lines of code, you are going in the wrong direction.

## Assignment Submission

See the code in the respository - I took a very simplistic approach using a memory block instead of a file.
I also simplified the page access to it's minimal behavior just to express what and how the IC can be used.
