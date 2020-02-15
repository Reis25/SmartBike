
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


int output_open(output_t *out, char *dev_label);


int output_configure(output_t *out, u32_t pin, int flags);

