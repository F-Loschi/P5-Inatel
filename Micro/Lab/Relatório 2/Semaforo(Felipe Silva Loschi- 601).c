#include <stdio.h>
#include <unistd.h>  // Para a função sleep()

int main() {
    int estado = 0; // 0 = Verde, 1 = Amarelo, 2 = Vermelho

    while (1) { // Loop infinito simulando o semáforo
        if (estado == 0) {
            printf("Sinal Verde\n");
            sleep(12);
            estado = 1; // Vai para o Amarelo
        } 
        else if (estado == 1) {
            printf("Sinal Amarelo\n");
            sleep(3);
            estado = 2; // Vai para o Vermelho
        } 
        else if (estado == 2) {
            printf("Sinal Vermelho\n");
            sleep(15);
            estado = 0; // Volta para o Verde
        }
    }

    return 0;
}
