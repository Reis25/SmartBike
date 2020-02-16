#include "state_machine.h"

/* Possible States */
static enum {PEDALANDO, FREIANDO, ALERTA, RESET} state = PEDALANDO;

/* Message struct */
struct data_item_type {
    u32_t data1;       // pedalando
    u32_t data2;       // freiando
    u32_t data3;		// alerta
	u32_t data4;	   // reset
};

K_MSGQ_DEFINE(my_msgq, sizeof(struct data_item_type), 10, 4);

/* State Machine */
void state_machine() {
	/* Reading message queue for state update */
    struct data_item_type package = { 0 };	
    k_msgq_get(&my_msgq, &package, K_FOREVER);

	/* State Update */
    switch (state) {
        case PEDALANDO:
            printk("[STATE MACHINE] Actual state: PEDALANDO.\n");
            if (package.data2) {
				state = FREIANDO ;
				printk("[STATE CHANGE] PEDALANDO -> FREIANDO\n");
            } else if(package.data3) {
				state = ALERTA;
				printk("[STATE CHANGE] PEDALANDO -> ALERTA\n");
            } else if(package.data4) {
				state = RESET;
				printk("PEDALANDO -> RESET\n");
			}else
			{
				printk("PEDALANDO -> PEDALANDO\n");
			}
			
            break;
        case FREIANDO:
            printk("[STATE MACHINE] Actual state: FREIANDO.\n");
            if (package.data1) {
				state = PEDALANDO;
				printk("[STATE CHANGE] FREIANDO -> PEDALANDO\n");
            } else if(package.data3) {
				state = ALERTA;
				printk("[STATE CHANGE] FREIANDO -> ALERTA\n");
            } else if(package.data2) {
				state = FREIANDO;
				printk("FREIANDO -> FREIANDO\n");
            }else if (package.data4)
			{
				state = RESET;
				printk("FREIANDO -> RESET\n");
			}
			
            break;
        case ALERTA:
          printk("[STATE MACHINE] Actual state: ALERTA.\n");
            if (package.data1) {
				state = PEDALANDO;
				printk("[STATE CHANGE] ALERTA -> PEDALANDO\n");
            } else if(package.data3) {
				state = ALERTA;
				printk("[STATE CHANGE] ALERTA -> ALERTA\n");
            } else if(package.data2) {
				state = FREIANDO;
				printk("ALERTA -> FREIANDO\n");
            }else if (package.data4)
			{
				state = RESET;
				printk("ALERTA -> RESET\n");
			}
            break;

		 case RESET:
           printk("[STATE MACHINE] Actual state: RESET.\n");
            if (package.data1) {
				state = PEDALANDO;
				printk("[STATE CHANGE] RESET -> PEDALANDO\n");
            } 
            break;


        default:
			printk("default\n");
            break;
    }
}


void set_pedalando(){
    struct data_item_type package;
	package.data1 = 1;  
	package.data2 = 0; 
	package.data3 = 0;
	package.data4 = 0;

	while (k_msgq_put(&my_msgq, &package, K_NO_WAIT) != 0) {
		/* Message queue is full: purge old data & try again */
		k_msgq_purge(&my_msgq);
	}
}


void set_freiando(){
    struct data_item_type package;
	package.data1 = 0;
	package.data2 = 1;
	package.data3 = 0;
	package.data4 = 0;

	while (k_msgq_put(&my_msgq, &package, K_NO_WAIT) != 0) {
		/* Message queue is full: purge old data & try again */
		k_msgq_purge(&my_msgq);
	}
}


void set_alerta(){
    struct data_item_type package;
	package.data1 = 0;
	package.data2 = 0;
	package.data3 = 1;
	package.data4 = 0;
	
	while (k_msgq_put(&my_msgq, &package, K_NO_WAIT) != 0) {
		/* Message queue is full: purge old data & try again */
		k_msgq_purge(&my_msgq);
	}
}

void set_reset(){
    struct data_item_type package;
	package.data1 = 0;
	package.data2 = 0;
	package.data3 = 0;
	package.data4 = 1;
	
	while (k_msgq_put(&my_msgq, &package, K_NO_WAIT) != 0) {
		/* Message queue is full: purge old data & try again */
		k_msgq_purge(&my_msgq);
	}
}

int get_state() {
	return state;
}