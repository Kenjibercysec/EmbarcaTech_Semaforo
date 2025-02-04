# EmbarcaTech_Semaforo

Este projeto implementa um sistema de semáforo utilizando a plataforma Raspberry Pi Pico. O firmware controla LEDs que simulam as luzes de um semáforo (vermelho, amarelo e verde) e é desenvolvido utilizando o Pico SDK e CMake para compilação.

## Sumário
- [Descrição](#descrição)
- [Funcionalidades](#funcionalidades)
- [Estrutura do Projeto](#estrutura-do-projeto)
- [Detalhes do Código](#detalhes-do-código)
  - [Configuração dos Pinos](#configuração-dos-pinos)
  - [Implementação do Controle do Semáforo](#implementação-do-controle-do-semafóro)
  - [Loop Principal](#loop-principal)
- [Aprendizados](#aprendizados)
- [Guia de Utilização](#guia-de-utilização)
- [Licença](#licença)

## Descrição
O EmbarcaTech_Semaforo é um firmware que simula o funcionamento de um semáforo, controlando três LEDs que representam as luzes vermelha, amarela e verde. O sistema segue a sequência típica de um semáforo, alternando entre os estados com temporizações definidas.

## Funcionalidades
- Controle sequencial dos LEDs para simular um semáforo.
- Utilização do Pico SDK com CMake para desenvolvimento e compilação.

## Estrutura do Projeto
A estrutura do repositório é apresentada abaixo:

```bash
EmbarcaTech_Semaforo/
├── .vscode/
├── CMakeFiles/
├── pico-sdk/
├── .gitignore
├── CMakeLists.txt
├── EmbarcaTech_Semaforo.c
├── blink.pio
├── diagram.json
├── pico_sdk_import.cmake
└── wokwi.toml
```

# Detalhes do Código
## Configuração dos Pinos
No arquivo EmbarcaTech_Semaforo.c, os pinos são definidos da seguinte forma:
```
#define LED_RED 13     // LED Vermelho em GP13
#define LED_YELLOW 12  // LED Amarelo em GP12
#define LED_GREEN 11   // LED Verde em GP11
```

# Implementação do Controle do Semáforo
## A função control_traffic_lights gerencia a sequência do semáforo:
```
void control_traffic_lights() {
    gpio_put(LED_RED, 1);
    sleep_ms(5000);  // Vermelho aceso por 5 segundos
    gpio_put(LED_RED, 0);
    gpio_put(LED_YELLOW, 1);
    sleep_ms(2000);  // Amarelo aceso por 2 segundos
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 1);
    sleep_ms(5000);  // Verde aceso por 5 segundos
    gpio_put(LED_GREEN, 0);
}
```
# Loop Principal
## No main(), o loop infinito chama a função control_traffic_lights para manter o ciclo do semáforo:
```
int main() {
    // Configuração dos pinos como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Loop principal
    while (true) {
        control_traffic_lights();
    }
    return 0;
}
```
## Aprendizados
- Controle de LEDs para simular o funcionamento de um semáforo.
- Utilização de temporizações para alternar entre os estados do semáforo.
- Desenvolvimento de firmware utilizando o Pico SDK e CMake.

## Guia de Utilização

### Pré-requisitos
- **Hardware**: Raspberry Pi Pico ou dispositivo compatível.
- **Software**:
  - [Raspberry Pi Pico SDK](https://github.com/raspberrypi/pico-sdk)
  - [CMake](https://cmake.org/)
  - Ferramenta de upload/flash (por exemplo, picotool)

### Passos para Compilação e Upload

1. **Clonar o repositório**:
   ```bash
   git clone https://github.com/Kenjibercysec/EmbarcaTech_Semaforo.git
   cd EmbarcaTech_Semaforo
   ```

2. **Configurar o ambiente**:

Verifique se o Pico SDK está instalado e se o arquivo `pico_sdk_import.cmake` aponta para o caminho correto.

### Criar o diretório de build e compilar

```
mkdir build
cd build
cmake ..
make
```
## Upload do Firmware

Conecte o Raspberry Pi Pico em modo bootloader e copie o arquivo `.uf2` gerado para o dispositivo.

## Teste

Observe o funcionamento dos LEDs conectados aos pinos GP11, GP12 e GP13, que devem simular o comportamento de um semáforo.

