#include <zephyr.h>
#include <drivers/sensor.h>
#include <device.h>
#include <stdio.h>
#include <sys/printk.h>

struct device *dev;
struct sensor_value intensity;

struct sensor_value attr = {
    .val1 = 127,
    .val2 = 0,
};

// esta função inicializa o dispositivo de entrada analógico
void analog_input_open (device *dev, char *dev_label);

// esta função lê os dados no dispositivo de entrada analógico
int analog_input_read (device *dev, struct sensor_value value);
