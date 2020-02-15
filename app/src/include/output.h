#ifndef _OUTPUT_H_
#define _OUTPUT_H_
#endif

#include <device.h>
#include <gpio.h>


struct output {
    struct device *device;
    char *dev_label;
    u32_t pin;
    u8_t state;
};

typedef struct output output_t;

// Essa função tem como objetivo iniciar o device do driver de saída.
int output_open(output_t *out, char *dev_label);

// Essa função tem como objetivo configurar o pino de saída.
int output_configure(output_t *out, u32_t pin, int flags);

// Essa função tem como objetivo configurar a mudança de estado de um dispositivo de saída
int output_set(output_t *out, u8_t value);

// ?
int output_pressed(output_t *out);

// LED: piscar
int output_switch(output_t *out);