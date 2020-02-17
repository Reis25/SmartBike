#include "setup.h"
#include "farol.h"

void configure_pwm() {
    configure_ldr();

    pwm_dev = device_get_binding(PWM_DRIVER);

    if (!pwm_dev) {
		printk("configure_pwm: erro na inicialização %s!\n", PWM_DRIVER);
		return;
	}
}

void pwm_set() {
    int lum = get_ldr_data();
    double var = 1.0 * (pulse_max - pulse_min) / (ldr_max - sensibilidade);
    pwm_pulse = pulse_min + var * (lum - sensibilidade);

    pwm_pin_set_usec(pwm_dev, PWM_CHANNEL, PERIOD, pwm_pulse);
}