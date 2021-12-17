# Lesson 4 Exercise: Make Blinky

On your final project board, make blinky for yourself. Then add a button to turn the LED on and off. Bonus points for making the button cause an interrupt. Triple bonus points for debouncing the button signal.

What are the hardware registers that cause the LED to turn on and off? (From the processor manual, don’t worry about initialization.) What are the button registers that you read? Can you read that memory directly and see the button change in a debugger or by printing out the associated memory?

Turn in your code with a comment or additional file answering the questions.

## Comments

The main bulk of the code is located in the [main.c]() file.
I decided to use the HAL but not cubeMx for this project - I defined some global PIN variable so that I can change their assignement easily.
I included a uart file as part of the project but it is not used. This file is only there to help debugging.