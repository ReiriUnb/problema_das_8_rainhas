#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainhas.h"

TEST_CASE("Verifica tabuleiro válido") {
    char tabuleiro[8][8] = {
        // ... preencha o tabuleiro com uma configuração de teste
    };
    REQUIRE(verificar_tabuleiro(tabuleiro) == 1);
}
