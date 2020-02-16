#include "thread.h"

#define PEDALANDO 	0
#define FREIANDO 	1
#define ALERTA      2
#define RESET		3

void farol_thread(){

}

void void sensor_thread(){

}

K_THREAD_DEFINE(farol_id, STACKSIZE, farol_thread, NULL, NULL, NULL, PRIORITY, 0, K_NO_WAIT);
K_THREAD_DEFINE(sensor_id, STACKSIZE, sensor_thread, NULL, NULL, NULL, PRIORITY, 0, K_NO_WAIT);