#include <stdio.h>
#include "stm32f4xx_hal.h"

#define BTN_PORT GPIOC
#define BTN_PIN  GPIO_PIN_13
#define LED_PORT GPIOA
#define LED_PIN  GPIO_PIN_5

const uint16_t confidenceThreshold = 50000;

void gpio_pc13_interrupt_init(void);

int main() {
	HAL_Init();
	gpio_pc13_interrupt_init();

	while (1) {

	}
}

void SysTick_Handler(void) {
	HAL_IncTick();
}

void gpio_pc13_interrupt_init(void) {
	GPIO_InitTypeDef GPIO_InitStruct = { 0 };
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOA_CLK_ENABLE();

	// Configure PC13
	GPIO_InitStruct.Pin = BTN_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(BTN_PORT, &GPIO_InitStruct);

	// Configure PA5
	GPIO_InitStruct.Pin = LED_PIN;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(LED_PORT, &GPIO_InitStruct);

	// Configure EXTI
	HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {

	char btnPressed = 0;
	uint16_t btnPressedConfidenceLevel = 0;
	uint16_t btnReleasedConfidenceLevel = 0;


	// if button is pressed
	//if (GPIO_Pin == BTN_PIN) {
		//if (/* button pressed variable is 0 */) {
			// Increase the bytton pressed confidence level
			// Toggle LEDs once button pressed confidence has passed the confidence level
			// Update the button pressed variable to 1
		//}
	//} else {
		//if (/* button pressed variable is 1 */) {
			// Increase the button released confidence level
			// Once the button release confidence level has been achieved
			// update the button pressed variable to 0
		//}
	//}

	// Software button Debouncing
	while (1) {
		if (GPIO_Pin == BTN_PIN) {
			if (btnPressed == 0) {
				if (btnPressedConfidenceLevel > confidenceThreshold) {
					if (GPIO_PIN_SET == HAL_GPIO_ReadPin(LED_PORT, LED_PIN)) {
						HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_RESET);
					} else {
						HAL_GPIO_WritePin(LED_PORT, LED_PIN, GPIO_PIN_SET);
					}
					btnPressed = 1;
					break;
				} else {
					// Increase the button pressed confidence level
					btnPressedConfidenceLevel++;
					btnReleasedConfidenceLevel = 0;
				}
			}
		} else {
			if (btnPressed == 1) {
				if (btnReleasedConfidenceLevel > confidenceThreshold) {
					btnPressed = 0;
					break;
				} else {
					// Increase the button pressed confidence level
					btnReleasedConfidenceLevel++;
					btnPressedConfidenceLevel = 0;

				}

			}
		}
	}
}

void EXTI15_10_IRQHandler(void) {
	HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_13);
}
