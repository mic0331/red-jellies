# Lesson 4 Exercise: Make Blinky

On your final project board, make blinky for yourself. Then add a button to turn the LED on and off. Bonus points for making the button cause an interrupt. Triple bonus points for debouncing the button signal.

What are the hardware registers that cause the LED to turn on and off? (From the processor manual, don’t worry about initialization.) What are the button registers that you read? Can you read that memory directly and see the button change in a debugger or by printing out the associated memory?

Turn in your code with a comment or additional file answering the questions.

## Comments

In this project I am using interupts for both the GPIO and the Timer.
In order to handle the debouncing of the board button I am leveraging the timer with a frequency of 10Hz to confirm the state of the button action.
Finally I am using variable name in order to simplify the type of port and pin used by the different module. With this, each module (gpio, tim) can be easily used for other project.
I am also keeping the `main.c` as minimal as possible.