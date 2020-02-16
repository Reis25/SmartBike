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

void thread()
{
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
    }
    return 0;
}

void action() {
    
}