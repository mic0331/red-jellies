# Lesson 4 Exercise: Make Blinky

On your final project board, make blinky for yourself. Then add a button to turn the LED on and off. Bonus points for making the button cause an interrupt. Triple bonus points for debouncing the button signal.

What are the hardware registers that cause the LED to turn on and off? (From the processor manual, don’t worry about initialization.) What are the button registers that you read? Can you read that memory directly and see the button change in a debugger or by printing out the associated memory?

Turn in your code with a comment or additional file answering the questions.

## Comments

In this project I am using interupts for both the GPIO and the Timer. The [`main.c`](https://github.com/mic0331/red-jellies/blob/main/lesson-4/nucleo-F401RE-blinky_interrupt_debouncing/Src/main.c) file is kept as minimal as possible.

In order to handle the debouncing of the board button I am leveraging the timer with a frequency of 10Hz to confirm the state of the button action.

The code leverage global variable name in order to simplify the definition of the different peripherals used by the different module. With this, each module (gpio, tim) can be easily used for other project.

For reference I am also keeping the intial version of the code ([`mail.old.c`](https://github.com/mic0331/red-jellies/blob/main/lesson-4/nucleo-F401RE-blinky_interrupt_debouncing/Src/main.old.c)). This version was using a counter based approach. It was not working as expected and it was not properly implemented as a `while` loop was kept in the callback of the GPIO interrupt.
