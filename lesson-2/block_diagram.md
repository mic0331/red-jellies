# Lesson 2 Assignments

## Exercise 2.1: Idea Project Diagram

Make a block diagram describing an embedded system you’d like to have or make. Be imaginative. Reality does not apply here.

## Assignment Submission

The below hardware block diagram is a refined version of the one in the [porevious submission](https://github.com/mic0331/red-jellies/blob/main/lesson-1/README.md). The main change concern the power supply part and the selection of the specific MCA that will be used for the project.

Smart fume extractor can automatically detects bad air quality, activate the fan at a speed that corresponds to the level of particulates. Automatically power on/off the device. They can record the time of execution of the device and predict a replacement cycle for the fume filter. Finally they can display the total execution time and a percentage of the filter saturation on a simple display.

![Screenshot 2021-12-03 at 05 31 10](https://user-images.githubusercontent.com/2216608/144546077-b962da71-23d3-44ce-85db-4e14057f83e3.png)

## Exercise 2.2: Read mbed code, make diagram

* Go to mbed platforms https://os.mbed.com/platforms/
* Select any platform (hint: search for a processor similar to the one you are considering
for your final project)
* Read through the platform page
* Add to Mbed Compiler (button on right)
* Load a simple sounding template
* Create a block diagram for this program, briefly explain why you chose the platform
and template you did, be prepared to talk about this board in Live Class

## Assignment Submission

**Selected Platform**: NUCLEO-F401RE using a STM32F401RET6 microcontroller ([Docs](https://os.mbed.com/platforms/ST-Nucleo-F401RE/))

**Selected Template**: STM32_ADC_InternalChannels (ADC Internal Temperature Sensor reading example)

The below hardware block diagram shows the components of the board that are used by this program:

![Screenshot 2021-12-03 at 06 34 40](https://user-images.githubusercontent.com/2216608/144550976-63093313-a193-4035-b38d-a948083e2a56.png)

I choose this particular platform for its flexibility, ease of prototyping and it's relatively low cost.
