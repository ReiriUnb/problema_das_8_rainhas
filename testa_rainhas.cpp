#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "rainhas.h"

TEST_CASE("Verifica tabuleiro válido") {
    char tabuleiro[8][8] = {
        {'0', '1', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '1', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0', '0', '0', '0'}
    };
    REQUIRE(verificar_tabuleiro(tabuleiro) == 1);
}
//merda
