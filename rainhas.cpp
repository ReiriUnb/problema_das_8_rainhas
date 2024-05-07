#include "rainhas.h"
#include <cmath>

// Função que verifica se uma rainha pode ser colocada em uma determinada posição do tabuleiro
bool pode_colocar_rainha(char tabuleiro[8][8], int linha, int coluna) {
    // Verifica se há uma rainha na mesma linha
    for (int i = 0; i < 8; ++i) {
        if (tabuleiro[linha][i] == '1') {
            return false;
        }
    }

    // Verifica se há uma rainha na mesma coluna
    for (int i = 0; i < 8; ++i) {
        if (tabuleiro[i][coluna] == '1') {
            return false;
        }
    }

    // Verifica se há uma rainha na diagonal principal (superior esquerda para inferior direita)
    for (int i = linha, j = coluna; i >= 0 && j >= 0; --i, --j) {
        if (tabuleiro[i][j] == '1') {
            return false;
        }
    }

    // Verifica se há uma rainha na diagonal secundária (superior direita para inferior esquerda)
    for (int i = linha, j = coluna; i >= 0 && j < 8; --i, ++j) {
        if (tabuleiro[i][j] == '1') {
            return false;
        }
    }

    return true;
}

// Função que verifica se o tabuleiro é uma solução válida para o problema das 8 rainhas
int verificar_tabuleiro(char tabuleiro[8][8]) {
    int num_rainhas = 0;

    // Verifica se o tabuleiro é válido
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (tabuleiro[i][j] != '0' && tabuleiro[i][j] != '1') {
                return -1; 
            }
            if (tabuleiro[i][j] == '1') {
                ++num_rainhas;
                if (!pode_colocar_rainha(tabuleiro, i, j)) {
                    return 0; 
                }
            }
        }
    }

    if (num_rainhas != 8) {
        return -1; 
    }

    return 1; 
}
