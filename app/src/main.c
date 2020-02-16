#include "setup.h"
#include "initial_settings.h"

// aux setas
int cont = 0;
s64_t tempoAnt = 0;
bool piscarDireita, piscarEsquerda = false;
// aux reed
int voltas = 0;
int estadoReed = 0;
s64_t tempoGasto = 0;
s64_t tempoInicial = 0;
int estadoAnteriorReed = 0;

void piscar_seta(output_t *out)
{
    s64_t tempo = k_uptime_get();
    if (piscarDireita || piscarEsquerda)
    {
        if (cont < 6)
        {
            if (tempo - tempoAnt >= 500)
            {
                tempoAnt = tempo;
                output_switch(&out);
                cont++;
            }
        }
        else
        {
            piscarDireita = false;
            piscarEsquerda = false;
            cont = 0;
        }
    }
}

void reedSwitch()
{
    input_read(&reed_switch, estadoReed);
    
    if (estadoReed > 0) 
    {
        if (estadoAnteriorReed != estadoReed)
        {
            estadoAnteriorReed = estadoReed;

            voltas++;
            float distTotal = voltas * (DIST_1VOLTA / 1000.0);

            s64_t t = k_uptime_get();
            s64_t tempoGastoM = (t - tempoInicial); // milisegundos
            tempoGasto = tempoGastoM / 1000.0;      // segundos
            tempoInicial = t;

            float velocInstantanea = 3.6 * (DIST_1VOLTA / tempoGasto); // 3,6*(m/s) = km/h

            // atualizar_display();
        }
    }
    else
    {
        estadoAnteriorReed = estadoReed;
    }
}

void main(void)
{

    printk("ECOM042.2019.2\n");
    printk("Embbebed System\n");
    printk("Smart Bike :)\n \n");

    leds_configure();
    buttons_configure();
    sensors_configure();
    display_configure();

    while (1)
    {
        // colocar seta pra direita e seta pra esquerda numa funcao
        // o codigo sera o mesmo
        switch (botao_pressionado)
        {
        case 0: // seta pra direita
            printk("seta pra direita\n");
            piscarDireita = true;
            piscarEsquerda = false;
            output_set(&led_seta_esquerda, OFF);
            break;

        case 1: // seta pra esqueda
            printk("seta pra esquerda\n");
            piscarEsquerda = true;
            piscarDireita = false;
            output_set(&led_seta_direita, OFF);
            break;

        case 2: // freio
            printk("freio\n");
            output_switch(&led_freio);
            break;

        default:
            break;
        }
        botao_pressionado = -1;

        if (piscarDireita)
            piscar_seta(&led_seta_direita);
        if (piscarEsquerda)
            piscar_seta(&led_seta_esquerda);
        // atualizar_farois();
        // atualizar_display();
    }
}
