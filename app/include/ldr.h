#ifndef _LDR_H_
#define _LDR_H_

#include <device.h>

struct device *dev;
struct sensor_value lum;

// função que inicializa o LDR
void configure_ldr();

// função que recupera os dados do LDR
int get_ldr_data();

#endif