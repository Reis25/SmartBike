#include "setup.h"
#include "input.h"
#include "output.h"

#include <zephyr.h>
#include <misc/printk.h>
#include <shell/shell.h>

/*--------------------------\\------------------------------------*/
// Thread principal

// estados
typedef enum {
	Freando, Pedalando, Seta_Direita, Seta_Esquerda, Farois, Reiniciando
} state_t;

// eventos
typedef enum {
   Anterior, Proximo, Atual
} event_t;

// máquina de estados
typedef struct {
    state_t events[3];
    void (*action)(void);
} mstate_t;

mstate_t machine[] = {
	// Chama função de acao: {estado anterior, futuro, atual}, .action = acao executada
	{ .events = {, , }, .action = print_to_display},    
};

    // Structs do tipo input representando cada botão, ldr e reed switch
	input_t botao_seta_direita, botao_seta_esquerda, botao_freio;

    // Structs do tipo output representando cada led
    output_t led_seta_direita, led_seta_esquerda, led_freio, led_farol_traseiro, led_farol_dianteiro;

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


    u8_t state = 1; // os leds estão inicialmente apagados

	// Criando e definindo os leds
    led(&led_seta_direita, 		led_zero_PIN, led_zero_PORT, 	state);
    led(&led_seta_esquerda, 	led_one_PIN, led_one_PORT, 		state);
    led(&led_freio, 	        led_two_PIN, led_two_PORT, 		state);
    led(&led_farol_traseiro, 	led_three_PIN, led_three_PORT,  state);
    led(&led_farol_dianteiro, 	led_four_PIN, led_four_PORT,    state);

    printk("\n");

    // Criando e definindo os botões
    button(&botao_seta_direita,     SW0_PIN, SW0_PORT);
    button(&botao_seta_esquerda,	SW1_PIN, SW1_PORT);
    button(&botao_freio,	        SW2_PIN, SW2_PORT);

	
while (1) {
    /*
		if(event_changed) {      
            current_state = machine[current_state].events[current_event];           
        }
		machine[current_state].action();
		current_event = CURRENT;
    	event_changed = 0;		
		k_sleep(get_sleep_time());	
	    }
    */

   // no momento, to desconsiderando a maq de estados e multi-threading
    while(1) {       
        switch (botao_pressionado) { 
        case 0: // seta pra direita
            break;
        
        case 1: // seta pra esqueda
            break;

        case 2: // freio = para testes, aperta 1 vez acende, aperta novamente, apaga
            output_switch(led_freio);
            break;

        default:
            break;
        }
        botao_pressionado = -1;
	}
}

/*--------------------------\\------------------------------------*/

void action() {
    
}
