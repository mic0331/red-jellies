#include "stm32f4xx_hal.h"
#include "gpio.h"

void gpio_led_interrupt_init(void) {
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
	HAL_NVIC_SetPriority(EXTIx_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(EXTIx_IRQn);
}

void EXTIx_IRQHandler(void) {
	HAL_GPIO_EXTI_IRQHandler(BTN_PIN);
}
