// Portas e Pinos dos leds
// 0 = seta direita
// 1 = seta esquerda
// 2 = freio
// 3 = farol traseiro
// 4 = farol dianteiro
#define led_zero_PORT LED0_GPIO_CONTROLLER
#define led_one_PORT LED1_GPIO_CONTROLLER
#define led_two_PORT LED2_GPIO_CONTROLLER
#define led_three_PORT LED3_GPIO_CONTROLLER
#define led_four_PORT LED4_GPIO_CONTROLLER

#define led_zero_PIN LED0_GPIO_PIN
#define led_one_PIN LED1_GPIO_PIN
#define led_two_PIN LED2_GPIO_PIN
#define led_three_PIN LED3_GPIO_PIN
#define led_four_PIN LED4_GPIO_PIN

// Portas e Pinos dos botões
// 0 = seta direita
// 1 = seta esqueda
// 2 = freio
#define SW0_PORT SW0_GPIO_CONTROLLER
#define SW1_PORT SW1_GPIO_CONTROLLER
#define SW2_PORT SW2_GPIO_CONTROLLER
#define SW3_PORT SW3_GPIO_CONTROLLER

#define SW0_PIN SW0_GPIO_PIN
#define SW1_PIN SW1_GPIO_PIN
#define SW2_PIN SW2_GPIO_PIN
#define SW3_PIN SW3_GPIO_PIN

// Flags de interrupções do GPIO
#define INTERRUPT GPIO_INT
#define FALLING_EDGE (GPIO_INT_EDGE | GPIO_INT_ACTIVE_LOW)
#define DEBOUNCE GPIO_INT_DEBOUNCE
#define PULL_UP GPIO_PUD_PULL_UP
#define SW_GPIO_FLAGS (INTERRUPT | FALLING_EDGE | DEBOUNCE | PULL_UP)

// Leitura do sinal do sensor

// PWM
#if defined(DT_ALIAS_PWM_LED0_PWMS_CONTROLLER) && defined(DT_ALIAS_PWM_LED0_PWMS_CHANNEL)
#define PWM_DRIVER	DT_ALIAS_PWM_LED0_PWMS_CONTROLLER
#define PWM_CHANNEL	DT_ALIAS_PWM_LED0_PWMS_CHANNEL
#ifdef DT_ALIAS_PWM_LED0_PWMS_FLAGS
#define PWM_FLAGS	DT_ALIAS_PWM_LED0_PWMS_FLAGS
#else
#define PWM_FLAGS	0
#endif
#else
#error "Choose supported PWM driver"
#endif

// PWM: microsegundos
#define MIN_PERIOD	(USEC_PER_SEC / 64U)
 
// PWM: microsegundos
#define MAX_PERIOD	USEC_PER_SEC

// Tempo de Sleep
#define SLEEP_TIME 500