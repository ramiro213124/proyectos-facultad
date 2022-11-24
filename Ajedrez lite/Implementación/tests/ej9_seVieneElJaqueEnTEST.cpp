#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
# include <utility>

using namespace std;
TEST(seVieneElJaqueEnTEST, hayMateEn2) {
    tablero t = { // tablero de ejercicio 17 del TPE
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA},
            {cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B},
    };
    posicion p = make_pair(t,BLANCO);

    int K_esperado = 2;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}

TEST(seVieneElJaqueEnTEST, hayMateEn3) {
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B},
    };
    posicion p = make_pair(t,BLANCO);

    int K_esperado = 3;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}
TEST(seVieneElJaqueEnTEST, hayMateEn1) {
    tablero t = {
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cTORRE_B, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t,BLANCO);

    int K_esperado = 1;

    EXPECT_EQ(K_esperado, seVieneElJaqueEn(p));
}
