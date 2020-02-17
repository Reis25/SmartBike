#ifndef _LDR_H_
#define _LDR_H_

#include <device.h>

struct device *dev;
struct sensor_value lum;

// ajustar essa range
int ldr_min = 0;
int ldr_max = 1023;

// função que inicializa o LDR
void configure_ldr();

// função que recupera os dados do LDR
int get_ldr_data();

#endif