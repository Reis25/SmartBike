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
	input_t botao_seta_direita, botao_seta_esquerda, botao_freio, ldr_dianteiro, ldr_traseiro, reed_switch;

    // Structs do tipo output representando cada led
    output_t led_seta_direita, led_seta_esquerda, led_freio, led_farol_traseiro, led_farol_dianteiro;

    // aux
    bool piscarDireita, piscarEsquerda = false;
    unsigned long tempoAnt = 0;
    int cont = 0;

void piscar_seta (output_t *out) {
  unsigned long tempo = millis();
  if (piscarDireita || piscarEsquerda) {
    if (cont < 6) {
      if (tempo - tempoAnt >= 500) {
        tempoAnt = tempo;
        output_switch(&out);
        cont++;
      }
    } else {
      piscarDireita = false;
      piscarEsquerda = false;
      cont = 0;
    }
  }
}

void main(void) {

	printk("ECOM042.2019.2\n");
	printk("Embbebed System\n"); 
	printk("Smart Bike :)\n \n");

	// iniciar display;
	//init_display();	

    // os leds estão inicialmente apagados
    u8_t state = 1; 

	// criando e definindo os dispositivos de saída
    // leds
    output_constructor(&led_seta_direita, 		led_zero_PIN, led_zero_PORT, 	state);
    output_constructor(&led_seta_esquerda, 	    led_one_PIN, led_one_PORT, 		state);
    output_constructor(&led_freio, 	            led_two_PIN, led_two_PORT, 		state);
    output_constructor(&led_farol_traseiro, 	led_three_PIN, led_three_PORT,  state);
    output_constructor(&led_farol_dianteiro, 	led_four_PIN, led_four_PORT,    state);

    printk("\n");

    // criando e definindo os dispositivos de entrada
    // botões
    input_constructor(&botao_seta_direita,     SW0_PIN, SW0_PORT);
    input_constructor(&botao_seta_esquerda,	   SW1_PIN, SW1_PORT);
    input_constructor(&botao_freio,	           SW2_PIN, SW2_PORT);
    // ldr
    input_constructor(&ldr_dianteiro,    	   SW3_PIN, SW3_PORT);
    input_constructor(&ldr_traseiro,	       SW4_PIN, SW4_PORT);
    // reed switch
    input_constructor(&reed_switch,  	       SW5_PIN, SW5_PORT);
	
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
        // colocar seta pra direita e seta pra esquerda numa funcao
        // o codigo sera o mesmo
        switch (botao_pressionado) { 
        case 0: // seta pra direita
            printk("seta pra direita\n");
            piscarDireita = true;
            piscarEsquerda = false;
            output_set(&led_seta_esquerda, (u8_t) 0);
            break;
        
        case 1: // seta pra esqueda
            printk("seta pra esquerda\n");
            piscarEsquerda = true;   
            piscarDireita = false;         
            output_set(&led_seta_direita, (u8_t) 0);
            break;

        case 2: // freio
            printk("freio\n");
            // para testes, aperta 1 vez acende, aperta novamente, apaga
            output_switch(&led_freio);
            break;

        default:
            break;
        }
        botao_pressionado = -1;

        if (piscarDireita) piscar_seta(&led_seta_direita);
        if (piscarEsquerda) piscar_seta(&led_seta_esquerda);
        // atualizar_farois();
        // atualizar_display();
	}
}

/*--------------------------\\------------------------------------*/
void action() {
    
}
