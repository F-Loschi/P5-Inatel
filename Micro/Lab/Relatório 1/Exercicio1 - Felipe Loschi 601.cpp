#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int unidades; // Variável para armazenar a quantidade de unidades compradas
    float preco;  // Variável para armazenar o preço total da compra

    // Solicita ao usuário que informe quantas unidades deseja comprar
    cout << "Quantas unidades voce vai comprar?" << endl;
    cin >> unidades;

    // Define a saída dos números com duas casas decimais
    cout << fixed << setprecision(2);

    // Aplica desconto caso a compra seja de 12 ou mais unidades
    if (unidades >= 12) {
        preco = unidades * 0.65; // Preço unitário reduzido para 0.65
    } else {
        preco = unidades * 0.80; // Preço unitário normal de 0.80
    }

    // Exibe o valor total da compra
    cout << "O total e de " << preco << endl;

    return 0;
}
