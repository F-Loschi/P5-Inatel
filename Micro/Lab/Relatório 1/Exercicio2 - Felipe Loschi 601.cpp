#include <iostream>
using namespace std;

int main() {
    int numero; // Variável para armazenar o número digitado pelo usuário
    int i;      // Variável de controle do loop
    int resto;  // Variável para armazenar o resto da divisão

    // Solicita um número entre 0 e 50 até que o usuário insira um valor válido
    do {
        cout << "Digite um numero entre 0 e 50" << endl;
        cin >> numero;
    } while (numero < 0 or numero > 50);

    // Percorre todos os números menores que o número digitado
    for (i = numero - 1; i > 0; i--) { // Evita divisão por zero
        resto = numero % i; // Calcula o resto da divisão
        cout << "O resto da divisao de " << numero << " por " << i << " e " << resto << endl;
    }

    return 0;
}
