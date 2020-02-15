#include <device.h>
#include <gpio.h>

#ifndef _INPUT_H_
#define _INPUT_H_
#endif

struct input {
    struct device *device;
    struct gpio_callback gpio_callback;
    char *dev_label;
    u32_t pin;
};

int botao_pressionado = -1;

typedef struct input input_t;

// construtor do botão
void input_constructor(input_t *input, u32_t pin, char *port);

// construtor do ldr
void ldr(output_t *led, u32_t pin, char *port, u8_t state);

// Essa função tem como objetivo iniciar o device do driver de entrada.
int input_open(input_t *in, char *dev_label);

// Essa função tem como objetivo configurar o pino de entrada.
int input_configure(input_t *in, u32_t pin, int flags, gpio_callback_handler_t cb);

// Essa função tem como objetivo fazer uma leitura do pino
int input_read(input_t *in, u32_t *state);

// Função para identificar qual botão foi pressionado
void button_pressed(struct device *btn, struct gpio_callback *cb, u32_t pins);

