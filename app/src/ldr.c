#include "ldr.h"

void configure_ldr() {
    dev = device_get_binding ("LDR0");

    if (dev == NULL) {
        printk("configure_ldr: LDR0 não inicializado\n");
        return;
    }
}

int get_ldr_data() {
    if (dev == NULL) {
        configure_ldr();
    }

    // realiza uma amostragem e armazena o resulta no buffer interno
    int r = sensor_sample_fetch_chan(dev, SENSOR_CHAN_LIGHT);
    
    if (ret < 0) {
        printk("get_ldr_data: amostra não obtida\n");
        return -1;
    }

    // lê o buffer, "realiza compensações" e armazena em s_value
    sensor_channel_get(dev, SENSOR_CHAN_LIGHT, &lum);

    if (ret < 0) {
        printk("get_ldr_data: leitura não realizada\n");
        return -1;
    }

	printk("get_ldr_data: lum reading: %d\n", lum.val1);
    return lum.val1;
}