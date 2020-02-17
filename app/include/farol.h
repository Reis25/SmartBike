#ifndef _FAROL_H_
#define _FAROL_H_

#include "ldr.h"
#include <pwm.h>
#include <device.h>

struct device *pwm_dev;
int pwm_pulse = 0;
int sensibilidade = 50; // ajustar esse valor depois

int pulse_min = 15;
int pulse_max = 100;

// função que inicializa o led pwm
void configure_pwm();

// função que muda o valor do led pwm
void pwm_set();

#endif