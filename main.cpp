#include "rainhas.h"
#include <iostream>

int main() {
    char tabuleiro[8][8] = {
        // Inicialize o tabuleiro com a configuração que deseja verificar
    };

    int resultado = verificar_tabuleiro(tabuleiro);
    if (resultado == 1) {
        std::cout << "A configuração é uma solução válida para o problema das 8 rainhas.\n";
    } else if (resultado == 0) {
        std::cout << "A configuração não é uma solução válida para o problema das 8 rainhas.\n";
    } else {
        std::cout << "A entrada não é válida.\n";
    }

    return 0;
}
