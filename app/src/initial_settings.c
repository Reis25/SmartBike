#include "setup.h"
#include "initial_settings.h"

void leds_configure() {
    output_constructor(&led_seta_direita, led_zero_PIN, led_zero_PORT, OFF);
    output_constructor(&led_seta_esquerda, led_one_PIN, led_one_PORT, OFF);
    output_constructor(&led_freio, led_two_PIN, led_two_PORT, OFF);
    output_constructor(&led_farol_traseiro, led_three_PIN, led_three_PORT, OFF);
    output_constructor(&led_farol_dianteiro, led_four_PIN, led_four_PORT, OFF);
}

void buttons_configure () {
    input_constructor(&botao_seta_direita, SW0_PIN, SW0_PORT);
    input_constructor(&botao_seta_esquerda, SW1_PIN, SW1_PORT);
    input_constructor(&botao_freio, SW2_PIN, SW2_PORT);
}

void sensors_configure() {
    input_constructor(&ldr_dianteiro, SW3_PIN, SW3_PORT);
    input_constructor(&ldr_traseiro, SW4_PIN, SW4_PORT);
    input_constructor(&reed_switch, SW5_PIN, SW5_PORT);
}

void display_configure() {
    // implementar
}
