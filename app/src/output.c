#include "output.h"
#include <gpio.h>

#include "setup.h"

/*
 * 50 is flicker fusion threshold. Modulated light will be perceived
 * as steady by our eyes when blinking rate is at least 50.
 */
#define PERIOD (USEC_PER_SEC / 50U)

/* in micro second */
#define FADESTEP	2000

/*
 * funções retornarão:
 *  -> 0 se não houver erro
 *  -> valor negativo se houver
 */

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

int output_set(output_t *out, u8_t value) {
    out->state = value;
    int ret = gpio_pin_write(out->device, out->pin, out->state); // pros leds, se der problema, usar gpio_pin_set(out->device, out->pin, out->state)

    if (ret == 0) {
        printk("output_set: sem erros\n");
        return 0;
    } else {
        printk("output_set: ERRO\n");
        return -1;
    }    
}

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

int led_blink(output_t *out) {
    u8_t value = (out->state) ? false : true; 
    return output_set(out, value);
}