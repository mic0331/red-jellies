#include "stm32f4xx_hal.h"
#include "tim.h"


void tim_timebase_init(void) {
	_TIMx_CLK_ENABLE;

	TimHandle.Instance = TIMx;
	TimHandle.Init.Prescaler = 1600-1; // 16 000 000 / 1600 = 10000
	TimHandle.Init.Period = 1000 - 1; // 10000 / 1000 = 10Hz
	TimHandle.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
	TimHandle.Init.RepetitionCounter = 0;
	TimHandle.Init.CounterMode = TIM_COUNTERMODE_UP;
	TimHandle.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;

	HAL_TIM_Base_Init(&TimHandle);

	HAL_NVIC_SetPriority(TIMx_IRQn, 0, 0);
	HAL_NVIC_EnableIRQ(TIMx_IRQn);
}

void TIMx_IRQHandler(void) {
	HAL_TIM_IRQHandler(&TimHandle);
}
