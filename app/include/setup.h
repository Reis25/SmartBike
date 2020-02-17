// Flags de interrupções do GPIO
#define INTERRUPT GPIO_INT
#define FALLING_EDGE (GPIO_INT_EDGE | GPIO_INT_ACTIVE_LOW)
#define DEBOUNCE GPIO_INT_DEBOUNCE
#define PULL_UP GPIO_PUD_PULL_UP
#define SW_GPIO_FLAGS (INTERRUPT | FALLING_EDGE | DEBOUNCE | PULL_UP)

// saída
// 1 = seta direita (led)
// 2 = seta esquerda (led)
// 3 = freio (led)
#define led_one_PORT LED1_GPIO_CONTROLLER
#define led_two_PORT LED2_GPIO_CONTROLLER
#define led_three_PORT LED3_GPIO_CONTROLLER

#define led_one_PIN LED1_GPIO_PIN
#define led_two_PIN LED2_GPIO_PIN
#define led_three_PIN LED3_GPIO_PIN

// entrada
// 0 = seta direita (botao)
// 1 = seta esqueda (botao)
// 2 = freio (botao)
// 3 = reed switch (botao)
// 4 = ldr 
#define SW0_PORT SW0_GPIO_CONTROLLER
#define SW1_PORT SW1_GPIO_CONTROLLER
#define SW2_PORT SW2_GPIO_CONTROLLER
#define SW3_PORT SW3_GPIO_CONTROLLER
#define SW4_PORT SW4_GPIO_CONTROLLER
#define SW5_PORT SW5_GPIO_CONTROLLER

#define SW0_PIN SW0_GPIO_PIN
#define SW1_PIN SW1_GPIO_PIN
#define SW2_PIN SW2_GPIO_PIN
#define SW3_PIN SW3_GPIO_PIN
#define SW4_PIN SW4_GPIO_PIN
#define SW5_PIN SW5_GPIO_PIN

// PWM
#define PWM_DRIVER	CONFIG_PWM_NRF5_SW_0_DEV_NAME
#define PWM_CHANNEL	LED0_GPIO_PIN
#define PWM_FLAGS	0

// outros defines
// pros leds
#define ON 1
#define OFF 0
// pro reed switch
// distancia percorrida em 1 volta do pneu
// considerando aro 26, cujo diâmetro é de 559mm = 0,559m
#define DIST_1VOLTA = PI * 0.559; // metros
// pro pwm
#define PERIOD (USEC_PER_SEC / 50)
// geral
#define SLEEP_TIME 500 //ms