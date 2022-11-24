#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
# include <utility>

using namespace std;

TEST(ejecutarSecuenciaForzadaTEST, secuenciaForzada) {
	tablero t = {	// Figura 5 del enunciado del TPE
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cTORRE_B},
    };
    posicion p = make_pair(t, BLANCO);
    secuencia s = {
    	make_pair(make_pair(6,3),make_pair(6,6)), make_pair(make_pair(4,7),make_pair(3,7)),
    	make_pair(make_pair(3,7),make_pair(2,7)), make_pair(make_pair(1,2),make_pair(0,2))
    };

    tablero t_fin = {	
            {cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA},
            {cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA, cTORRE_B},
    };
    posicion p_fin = make_pair(t_fin, BLANCO);

    ejecutarSecuenciaForzada(p, s);
    EXPECT_EQ(p_fin, p);
}

TEST(ejecutarSecuenciaForzadaTEST, secuenciaForzadaDePeon) {
    tablero t = {
            {cVACIA, cPEON_N, cVACIA, cVACIA, cVACIA, cTORRE_B, cPEON_N, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cTORRE_B, cREY_B, cVACIA, cVACIA, cVACIA},
    };
    posicion p = make_pair(t, BLANCO);
    secuencia s = {
            make_pair(make_pair(7,3),make_pair(6,3)), make_pair(make_pair(6,3),make_pair(5,3)),
            make_pair(make_pair(5,3),make_pair(4,3)), make_pair(make_pair(4,3),make_pair(3,3)),
            make_pair(make_pair(3,3),make_pair(2,3)), make_pair(make_pair(2,3),make_pair(1,3)),
            make_pair(make_pair(1,3),make_pair(0,3))
    };

    tablero t_fin = {
            {cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cTORRE_B, cPEON_N, cREY_N},
            {cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cTORRE_N, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA},
    };
    posicion p_fin = make_pair(t_fin, BLANCO);

    ejecutarSecuenciaForzada(p, s);
    EXPECT_EQ(p_fin, p);
}