#ifndef _THREAD_H_
#define _THREAD_H_

#include <device.h>
#include <gpio.h>
#include "state_machine.h"

extern const k_tid_t farol_id;
extern const k_tid_t sensor_id;

void farol_thread();

void sensor_thread();


#endif
