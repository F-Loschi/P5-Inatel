#include <iostream>

using namespace std;

/**
 * Função que analisa um array de 5 números inteiros e calcula:
 * - Quantidade de números pares
 * - Quantidade de números ímpares
 * - Quantidade de números positivos
 * - Quantidade de números negativos
 *
 * @param valores Array de inteiros contendo 5 números
 */
void identifica(int valores[]){
    int pares = 0, impares = 0, positivos = 0, negativos = 0;

    // Percorre o array para contar a quantidade de pares e ímpares
    for (int j = 0; j < 5; j++) {
        if (valores[j] % 2 == 0)
            pares++;
        else
            impares++;
    }

    // Percorre o array para contar a quantidade de positivos e negativos
    for (int h = 0; h < 5; h++) {
        if (valores[h] >= 0)
            positivos++;
        else
            negativos++;
    }

    // Exibe os resultados
    cout << "Quantidade de numeros pares: " << pares << endl;
    cout << "Quantidade de numeros impares: " << impares << endl;
    cout << "Quantidade de numeros positivos: " << positivos << endl;
    cout << "Quantidade de numeros negativos: " << negativos << endl;
}

int main(){
    int n, j = 0; // 'n' armazena o número de conjuntos de 5 números a serem lidos
    cin >> n; // Lê a quantidade de conjuntos de números que o usuário deseja inserir
    int valores[5]; // Array para armazenar 5 números inteiros

    // Loop para ler 'n' conjuntos de 5 números cada
    for (j = 0; j < n; j++) {
        // Lê 5 números e armazena no array
        for (int i = 0; i < 5; i++) {
            cin >> valores[i];
        }
        // Chama a função para analisar os números lidos
        identifica(valores);
    }

    return 0;
}
