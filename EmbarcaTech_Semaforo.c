#include <stdio.h>
#include "pico/stdlib.h"

#define RED_LED 13
#define YELLOW_LED 12
#define GREEN_LED 11

// Estado inicial do semáforo (0 = vermelho, 1 = amarelo, 2 = verde)
int estado = 0;

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Apaga todos os LEDs antes de mudar o estado
    gpio_put(RED_LED, 0);
    gpio_put(YELLOW_LED, 0);
    gpio_put(GREEN_LED, 0);

    // Alterna o estado do semáforo
    if (estado == 0) {
        gpio_put(RED_LED, 1);  // Liga o vermelho
        printf("Sinal VERMELHO - Pare!\n");
    } else if (estado == 1) {
        gpio_put(YELLOW_LED, 1);  // Liga o amarelo
        printf("Sinal AMARELO - Atenção!\n");
    } else {
        gpio_put(GREEN_LED, 1);  // Liga o verde
        printf("Sinal VERDE - Siga!\n");
    }

    // Alterna o estado (0 -> 1 -> 2 -> 0)
    estado = (estado + 1) % 3;

    return true;  // Mantém o temporizador rodando
}

int main() {
    stdio_init_all();

    // Inicializa os LEDs como saída
    gpio_init(RED_LED);
    gpio_set_dir(RED_LED, GPIO_OUT);
    
    gpio_init(YELLOW_LED);
    gpio_set_dir(YELLOW_LED, GPIO_OUT);
    
    gpio_init(GREEN_LED);
    gpio_set_dir(GREEN_LED, GPIO_OUT);

    // Inicia o temporizador para mudar o semáforo a cada 3 segundos (3000ms)
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal: imprime mensagens na serial a cada 1 segundo
    while (1) {
        printf("Sistema rodando...\n");
        sleep_ms(1000);
    }

    return 0;
}
