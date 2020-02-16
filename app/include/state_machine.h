#ifndef _STATE_MACHINE_H_
#define _STATE_MACHINE_H_

#include "thread.h"
#include <device.h>
#include <gpio.h>

void state_machine();

void set_pedalando();

void set_freiando();

void set_alerta();

void set_reset();

int get_state();

#endif