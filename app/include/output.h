#ifndef _OUTPUT_H_
#define _OUTPUT_H_

#include <device.h>
#include <gpio.h>

struct output {
    struct device *device;
    char *dev_label;
    u32_t pin;
    u8_t state;
};

typedef struct output output_t;

// construtor do dispositivo de saída
void output_constructor(output_t *out, u32_t pin, char *label, u8_t state);

// Essa função tem como objetivo iniciar o dispositivo de saída
int output_open(output_t *out, char *dev_label);

// Essa função tem como objetivo configurar o pino de saída
int output_configure(output_t *out, u32_t pin, int flags);

// Essa função tem como objetivo configurar a mudança de estado de um dispositivo de saída
int output_set(output_t *out, u8_t value);

// ?
int output_pressed(output_t *out);

// Essa função tem como objetivo dar um "toggle" no estado do dispositivo
void output_switch(output_t *out);

#endif