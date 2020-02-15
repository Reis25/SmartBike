

#ifndef _INPUT_H_
#define _INPUT_H_

#include <device.h>
#include <gpio.h>

struct input {
    struct device *device;
    struct gpio_callback gpio_callback;
    char *dev_label;
    u32_t pin;
};

typedef struct input input_t;


// Essa função tem como objetivo iniciar o device do driver de entrada.
int input_open(input_t *in, char *dev_label);

// Essa função tem como objetivo configurar o pino de entrada.
int input_configure(input_t *in, u32_t pin, int flags, gpio_callback_handler_t cb);

// Essa função tem como objetivo fazer uma leitura do pino
int input_read(input_t *in, u32_t *state);