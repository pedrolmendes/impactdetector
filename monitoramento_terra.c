#include <stdio.h>
#include <math.h>
#include <unistd.h>  // Para usar a fun��o sleep

#define PI 3.14159265359
#define RAIO 10        // Raio da �rbita
#define VELOCIDADE 1   // Velocidade angular em radianos por segundo
#define LIMITE_PERIGO 5 // Dist�ncia cr�tica para perigo

int main() {
    double angulo = 0;  // Posi��o angular inicial (em radianos)
    int tempo_total = 0; // Tempo total decorrido em segundos
    int terra_em_perigo = 0; // Estado da Terra (0 = seguro, 1 = perigo)

    while (1) {
   		   // Calcula as coordenadas x e y do objeto
    	double x = RAIO * cos(angulo);
        double y = RAIO * sin(angulo);
        
        // Calcula a dist�ncia do objeto ao centro (0,0)
        double distancia = sqrt(x * x + y * y);

        // Atualiza o tempo total decorrido
        tempo_total += 3;

        // Ap�s 15 segundos, a Terra entra em perigo
        if (tempo_total >= 15) {
            terra_em_perigo = 1;
        }

        // Imprime a posi��o do objeto
        printf("Posi��o do objeto: (%.2f, %.2f)\n", x, y);
        
        // Verifica o estado da Terra e imprime a mensagem correspondente
        if (terra_em_perigo) {
            printf("ALERTA: A Terra est� em perigo!\n");
            printf("Maring� em perigo. Est� na trajet�ria!\n");
        } else if (distancia < LIMITE_PERIGO) {
            printf("PERIGO: Muito perto da Terra!\n");
        } else {
            printf("Situa��o segura.\n");
        }

        // Atualiza o �ngulo para a pr�xima posi��o
        angulo += VELOCIDADE * 3;  // Atualiza para a posi��o ap�s 3 segundos

        // Pausa o programa por 3 segundos
        sleep(3);
    }
    return 0;
}

