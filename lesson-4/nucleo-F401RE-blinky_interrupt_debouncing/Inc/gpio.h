#define BTN_PORT GPIOC
#define BTN_PIN  GPIO_PIN_13
#define LED_PORT GPIOA
#define LED_PIN  GPIO_PIN_5
#define EXTIx_IRQHandler EXTI15_10_IRQHandler
#define EXTIx_IRQn EXTI15_10_IRQn

void gpio_led_interrupt_init(void);
