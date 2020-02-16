#ifndef _INITIAL_SETTINGS_H_
#define _INITIAL_SETTINGS_H_

#include "output.h"
#include "input.h"

// Structs do tipo input representando cada botão, ldr e reed switch
input_t botao_seta_direita, botao_seta_esquerda, botao_freio, ldr_dianteiro, ldr_traseiro, reed_switch;

// Structs do tipo output representando cada led
output_t led_seta_direita, led_seta_esquerda, led_freio, led_farol_traseiro, led_farol_dianteiro;

void leds_configure();
void buttons_configure();
void sensors_configure();
void display_configure();

#endif