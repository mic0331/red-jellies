#include <stdio.h>
#include "stm32f4xx_hal.h"
#include "tim.h"
#include "gpio.h"
#include <stdbool.h>

bool state = true;

int main() {
	HAL_Init();
	tim_timebase_init();
	gpio_led_interrupt_init();

	while (1) {

	}
}

void SysTick_Handler(void) {
	HAL_IncTick();
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	if (GPIO_Pin == BTN_PIN && state == true) {
		// Start the TIM Base generation in interrupt mode
		HAL_TIM_Base_Start_IT(&TimHandle);
		state = false;
	} else {
		__NOP();
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	UNUSED(htim);
	if (HAL_GPIO_ReadPin(BTN_PORT, BTN_PIN) == GPIO_PIN_RESET) {
		HAL_GPIO_TogglePin(LED_PORT, LED_PIN);
		state = true;
		HAL_TIM_Base_Stop_IT(&TimHandle);
	}
}

