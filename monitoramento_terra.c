#include <stdio.h>
#include <math.h>
#include <unistd.h>  // Para usar a função sleep

#define PI 3.14159265359
#define RAIO 10        // Raio da órbita
#define VELOCIDADE 1   // Velocidade angular em radianos por segundo
#define LIMITE_PERIGO 5 // Distância crítica para perigo

int main() {
    double angulo = 0;  // Posição angular inicial (em radianos)
    int tempo_total = 0; // Tempo total decorrido em segundos
    int terra_em_perigo = 0; // Estado da Terra (0 = seguro, 1 = perigo)

    while (1) {
   		   // Calcula as coordenadas x e y do objeto
    	double x = RAIO * cos(angulo);
        double y = RAIO * sin(angulo);
        
        // Calcula a distância do objeto ao centro (0,0)
        double distancia = sqrt(x * x + y * y);

        // Atualiza o tempo total decorrido
        tempo_total += 3;

        // Após 15 segundos, a Terra entra em perigo
        if (tempo_total >= 15) {
            terra_em_perigo = 1;
        }

        // Imprime a posição do objeto
        printf("Posição do objeto: (%.2f, %.2f)\n", x, y);
        
        // Verifica o estado da Terra e imprime a mensagem correspondente
        if (terra_em_perigo) {
            printf("ALERTA: A Terra está em perigo!\n");
            printf("Maringá em perigo. Está na trajetória!\n");
        } else if (distancia < LIMITE_PERIGO) {
            printf("PERIGO: Muito perto da Terra!\n");
        } else {
            printf("Situação segura.\n");
        }

        // Atualiza o ângulo para a próxima posição
        angulo += VELOCIDADE * 3;  // Atualiza para a posição após 3 segundos

        // Pausa o programa por 3 segundos
        sleep(3);
    }
    return 0;
}

