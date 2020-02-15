
#include <drivers/pwm.h>
#include <zephyr.h>
#include <device.h>
#include <gpio.h>
#include <misc/printk.h>
#include <shell/shell.h>

#include "setup.h"
#include "input.h"
#include "output.h"

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

/* in microseconds */
#define MIN_PERIOD	(USEC_PER_SEC / 64U)
 
/* in microseconds */
#define MAX_PERIOD	USEC_PER_SEC



/*--------------------------\\------------------------------------*/
// Thread principal

typedef enum {
	Freio, Pedalando, Reset, Led_Direito, Led_Esquerdo
	
} state_t;

typedef enum {
   Anterior, Proximo, Atual
} event_t;

typedef struct {
    state_t events[3];
    void (*action)(void);
} mstate_t;


mstate_t machine[] = {
	// Chama função de acao: {estado anterior, futuro, atual}, .action = acao executada
	{ .events = {, , }, .action = print_to_display},    

};

//Struct input representando os botões;
	input_t butn_Seta_Right, butn_Seta_Left, butn_break_Right, butn_break_Left;

// Structs do tipo input_t representando cada botão
    output_t led_Seta_Right, led_Seta_Left, led_Farol_Dianteiro, led_Farol_Traseiro;

// Inicializador Led
void led(output_t *led, u32_t pin, char *port, u8_t state){
    int e = output_open(led, port);
    if(e){
        printk("Alerta: Led para o PIN%d não inicializado.\n", pin);
        return;
    }
    output_configure(led, pin, GPIO_DIR_OUT);
    output_set(led, state);
    printk("Led em PIN%d inicializado.\n", pin);
}

// Inicializador Botão
void button(input_t *button, u32_t pin, char *port){
    int e = input_open(button, port);
    if(e){
        printk("Alerta: Botao para o PIN%d não inicializado.\n", pin);
        return;
    }
    input_configure(button, pin, GPIO_DIR_IN | SW_GPIO_FLAGS, button_pressed);
    printk("Botao em PIN%d inicializado.\n", pin);
}

// Função para botão pressionado
void button_pressed(struct device *btn, struct gpio_callback *cb, u32_t pins){
    if(pins & BIT(SW0_PIN)) {
        butt = 0; 
        printk("Botao 0 pressionado em %d ciclos\n", k_cycle_get_32());
    } else if(pins & BIT(SW1_PIN)) {
        output_pressed(&led_one);
         butt = 1;
        printk("Botao 1 pressionado em %d ciclos\n", k_cycle_get_32());
    } else if(pins & BIT(SW2_PIN)) {
        output_pressed(&led_two);
         butt = 2;
        printk("Botao 2 pressionado em %d ciclos\n", k_cycle_get_32());
    } else {
        output_pressed(&led_three);
         butt = 3;
        printk("Botao 3 pressionado em %d ciclos\n", k_cycle_get_32());
    }
}



void main(void) {

	printk("ECOM042.2019.2\n");
	printk("Embbebed System\n"); 
	printk("Smart Bike :)\n \n");

	// iniciar display;
	//init_display();	

	// iniciar sensor de luminosidade; 
	//init_accelerometer_sensor();
	
	//Inciar botoes configurados;
	//configure_buttons();

	//Iniciar bluetooth;


    u8_t state = 1; // Inicialmente apagados

	// Criando e definindo Leds
    led(&led_Seta_Right, 		led_zero_PIN, led_zero_PORT, 	state);
    led(&led_Seta_Left, 		led_one_PIN, led_one_PORT, 		state);
    led(&led_Farol_Dianteiro, 	led_two_PIN, led_two_PORT, 		state);
    led(&led_Farol_Traseiro, 	led_three_PIN, led_three_PORT,  state);

    printk("\n");

    // Criando e definindo botoes
    button(&led_Seta_Right,		 SW0_PIN, SW0_PORT);
    button(&led_Seta_Left,		 SW1_PIN, SW1_PORT);
    button(&butn_break_Right,	 SW2_PIN, SW2_PORT);
    button(&butn_break_Left, 	 SW3_PIN, SW3_PORT);

	
while (1) {
		if(event_changed) {      
            current_state = machine[current_state].events[current_event];           
        }
		machine[current_state].action();
		current_event = CURRENT;
    	event_changed = 0;		
		k_sleep(get_sleep_time());	
	}
}

/*--------------------------\\------------------------------------*/

void action() {

    

    // Estado inicial dos leds

    
    printk("Aguardando comandos ...\n");
    while(1) {

		printk("1\n");
        


      // Turn ON seta direita
        if(butt == 0){
		}

		// Turn ON seta esquerda
		if(butt == 1){
		}

		// Turn farol dianteiro		
		  if(butt == 2){
		}

		// turn farol traseiro 
		  if(butt == 3){
		}



	}

}
