#include "setup.h"
#include "input.h"

/*
 * funções retornarão:
 *  -> 0 se não houver erro
 *  -> valor negativo se houver
 */

// construtor 
void input_constructor(input_t *input, u32_t pin, char *port){
    int e = input_open(input, port);
    if(e = NULL){
        printk("Alerta: Botao para o PIN%d não inicializado.\n", pin);
        return;
    }
    input_configure(input, pin, GPIO_DIR_IN | SW_GPIO_FLAGS, button_pressed);
    printk("Botao em PIN%d inicializado.\n", pin);
}

void 

// Inicialização do dispositivo de entrada
int input_open(input_t *in, char *dev_label) {
    in->dev_label = dev_label;
    in->device = device_get_binding(in->dev_label);

    if(in->device == NULL){
        printk("input_open: ERRO na atribução do in->device\n");
        return -1;
    } else {
        printk("input_open: sem erros\n");
        return 0;
    }
}
// Configuração do dispositivo de entrada
int input_configure(input_t *in, u32_t pin, int flags, gpio_callback_handler_t cb) {
    int ret = gpio_pin_configure(in->device, in->pin, flags);
    ret += gpio_init_callback(&in->gpio_callback, cb, BIT(in->pin));
    ret += gpio_add_callback(in->device, &in->gpio_callback);
    ret += gpio_pin_enable_callback(in->device, in->pin);
    
    if (ret == 0) {
        printk("input_configure: sem erros\n");
        return 0;
    } else {
        printk("input_configure: ERRO\n");
        return -1;
    } 
}

// Fazendo leitura do sinal em um dispositivo de entrada
int input_read(input_t *in, u32_t *value) {
    int ret = gpio_pin_read(in->device, in->pin, value);
    
    if (ret == 0) {
        printk("input_read: sem erros\n");
        return 0;
    } else {
        printk("input_read: ERRO %d\n", ret);
        return -1;
    }
}

// Função para identificar qual botão foi pressionado
void button_pressed(struct device *btn, struct gpio_callback *cb, u32_t pins){
    if(pins & BIT(SW0_PIN)) {
        botao_pressionado = 0; 
        printk("Botao 0 (seta direita) pressionado em %d ciclos\n", k_cycle_get_32());
    } else if(pins & BIT(SW1_PIN)) {
        botao_pressionado = 1
        printk("Botao 1 (seta esquerda) pressionado em %d ciclos\n", k_cycle_get_32());
    } else  {
        botao_pressionado = 2;
        printk("Botao 2 (freio) pressionado em %d ciclos\n", k_cycle_get_32());
    }
}