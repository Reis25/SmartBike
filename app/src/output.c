#include "setup.h"
#include "output.h"

/*
 * funções retornarão:
 *  -> 0 se não houver erro
 *  -> valor negativo se houver
 */

// construtor 
void output_constructor(output_t *out, u32_t pin, char *port, u8_t state){
    int e = output_open(out, port);
    if(e == NULL){
        printk("Alerta: Led para o PIN%d não inicializado.\n", pin);
        return;
    }
    output_configure(out, pin, GPIO_DIR_OUT);
    output_set(out, state);
    printk("Led em PIN%d inicializado.\n", pin);
}

// Inicialização do dispositivo de saída
int output_open(output_t *out, char *dev_label) {
    out->dev_label = dev_label;
    out->device = device_get_binding(out->dev_label);

    if(out->device == NULL){
        printk("output_open: sem erros\n");
        return 0;
    } else {
        printk("output_open: ERRO na atribução do out->device\n");
        return -1;
    }
}

// Configuração do dispositivo de saída
int output_configure(output_t *out, u32_t pin, int flags) {
    out->pin = pin;
    int ret = gpio_pin_configure(out->device, out->pin, flags);
    
    if (ret == 0) {
        printk("output_configure: sem erros\n");
        return 0;
    } else {
        printk("output_configure: ERRO %d\n", ret);
        return -1;
    }
}

// Mudança de estado de um dispositivo de saída
int output_set(output_t *out, u8_t value) {
    out->state = value;
    // pros leds, se der problema, usar gpio_pin_set(out->device, out->pin, out->state)
    int ret = gpio_pin_write(out->device, out->pin, out->state); 

    if (ret == 0) {
        printk("output_set: sem erros\n");
        return 0;
    } else {
        printk("output_set: ERRO\n");
        return -1;
    }    
}

// onde essa função vai ser usada?
int output_pressed(output_t *out) {
    out->state = (out->state) ? 0 : 1;
    int ret = gpio_pin_write(out->device, out->pin, out->state);

    if (ret == 0) {
        printk("output_pressed: sem erros\n");
        return 0;
    } else {
        printk("output_pressed: ERRO\n");
        return -1;
    } 
}

// LED: piscar
int output_switch(output_t *out) {
    u8_t value = (out->state) ? false : true; 
    return output_set (out, value);
}