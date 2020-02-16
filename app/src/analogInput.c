#include "include/analogInput.h"

#include <device.h>
#include <sys/printk.h>

void analog_input_open (device *dev, char *dev_label) {
    *dev = device_get_binding(dev_label);

    if(dev->device == NULL){
        printk("open_sensor: ERRO na atribução do device\n");
        return -1;
    } else {
        printk("open_sensor: sem erros\n");
        return 0;
    }
}

int analog_input_read (device *dev, struct sensor_value value) {
    if (sensor_sample_fetch(dev)) {
        printk("sensor_sample fetch failed\n");
        return -1;
	}
    
    sensor_channel_get(dev, SENSOR_CHAN_LIGHT, &value);
    printk("ambient light intensity %d", value.val1);

    return value.val1;
}