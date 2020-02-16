// Flags de interrupções do GPIO
#define INTERRUPT GPIO_INT
#define FALLING_EDGE (GPIO_INT_EDGE | GPIO_INT_ACTIVE_LOW)
#define DEBOUNCE GPIO_INT_DEBOUNCE
#define PULL_UP GPIO_PUD_PULL_UP
#define SW_GPIO_FLAGS (INTERRUPT | FALLING_EDGE | DEBOUNCE | PULL_UP)

// saída
// 0 = seta direita (led)
// 1 = seta esquerda (led)
// 2 = freio (led)
// 3 = farol traseiro (led)
// 4 = farol dianteiro (led)
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

// entrada
// 0 = seta direita (botao)
// 1 = seta esqueda (botao)
// 2 = freio (botao)
// 3 = ldr dianteiro
// 4 = ldr traseiro
// 5 = reed switch
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

// ldr
/* pinos analogicos
PIN # Signal Name = NRF52832 Functions
1 # A0 = P0.03 / AIN1
2 # A1 = P0.04 / AIN2
3 # A2 = P0.28 / AIN4
4 # A3 = P0.29 / AIN5
5 # A4 = P0.30 / AIN6
6 # A5 = P0.31 / AIN7
*/

// reed switch

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