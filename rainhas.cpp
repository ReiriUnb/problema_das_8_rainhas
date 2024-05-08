#include "rainhas.h"
#include <cmath>

bool pode_colocar_rainha(char tabuleiro[8][8], int linha, int coluna) {
    for (int i = 0; i < 8; ++i) {
        if (tabuleiro[linha][i] == '1') {
            return false;
        }
    }

    for (int i = 0; i < 8; ++i) {
        if (tabuleiro[i][coluna] == '1') {
            return false;
        }
    }

    for (int i = linha, j = coluna; i >= 0 && j >= 0; --i, --j) {
        if (tabuleiro[i][j] == '1') {
            return false;
        }
    }

    for (int i = linha, j = coluna; i >= 0 && j < 8; --i, ++j) {
        if (tabuleiro[i][j] == '1') {
            return false;
        }
    }

    return true;
}

int verificar_tabuleiro(char tabuleiro[8][8]) {
    int num_rainhas = 0;

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tabuleiro[i][j] != '0' && tabuleiro[i][j] != '1') {
                return -1; // Entrada inválida
            }
            if (tabuleiro[i][j] == '1') {
                ++num_rainhas;
                // Verifica se a rainha está atacando outra rainha
                for (int k = 0; k < 8; ++k) {
                    if ((k != j && tabuleiro[i][k] == '1') || // Ataque na mesma linha
                        (k != i && tabuleiro[k][j] == '1')) { // Ataque na mesma coluna
                        return 0;
                    }
                }
                for (int k = 1; k < 8; ++k) {
                    if ((i+k < 8 && j+k < 8 && tabuleiro[i+k][j+k] == '1') || // Ataque na diagonal principal
                        (i-k >= 0 && j-k >= 0 && tabuleiro[i-k][j-k] == '1') || // Ataque na diagonal principal
                        (i+k < 8 && j-k >= 0 && tabuleiro[i+k][j-k] == '1') || // Ataque na diagonal secundária
                        (i-k >= 0 && j+k < 8 && tabuleiro[i-k][j+k] == '1')) { // Ataque na diagonal secundária
                        return 0;
                    }
                }
            }
        }
    }

    if (num_rainhas != 8) {
        return -1; // Não há exatamente 8 rainhas
    }

    return 1; // É uma solução válida
}
