#include "../definiciones.h"
#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
# include <utility>

using namespace std;

TEST(casillasAtacadasTEST, atacadasDelJugadorActual) {
	tablero t = {
            {cVACIA, cREY_N, cVACIA, cALFIL_N, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
	posicion p = make_pair(t, BLANCO);

	int j = BLANCO;

	vector<coordenada> esperado = { 
		make_pair(6,3), make_pair(5,3), make_pair(5,4), make_pair(5,5), make_pair(6,5), make_pair(7,5), make_pair(7,4), make_pair(7,3), //Rey Blanco en (6,4)
		make_pair(3,4), make_pair(3,6)	//Peon Blanco en (4,5)
	};

	
	vector<coordenada> atacadas = casillasAtacadas(p, j);
	EXPECT_EQ(ordenarVectorPares(esperado), ordenarVectorPares(atacadas));
}

TEST(casillasAtacadasTEST, atacadasDelContrincante) {
	tablero t = {
            {cVACIA, cREY_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_B, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
    };
	posicion p = make_pair(t, BLANCO);

	int j = NEGRO;

	vector<coordenada> esperado = {
		make_pair(0,0), make_pair(0,2), make_pair(1,0), make_pair(1,1), make_pair(1,2), //Rey Negro en (0,1)
		make_pair(4,5), make_pair(4,7) //Peon Negro en (3,6)

	};

	vector<coordenada> atacadas = casillasAtacadas(p, j);
	EXPECT_EQ(ordenarVectorPares(esperado), ordenarVectorPares(atacadas));
}

TEST(casillasAtacadasTEST, atacadasJugadorAcutalTorre) {
    tablero t = {
            {cVACIA, cREY_N, cVACIA, cALFIL_N, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cPEON_N, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B},
    };
    posicion p = make_pair(t, BLANCO);

    int j = BLANCO;

    vector<coordenada> esperado = {
            //Rey Blanco en (6,4)
            make_pair(6,3), make_pair(5,3), make_pair(5,4), make_pair(5,5), make_pair(6,5),
            make_pair(7,5), make_pair(7,4), make_pair(7,3),
            //Torre Blanca en (7,7) sin las repetidas por el Rey
            make_pair(7,0), make_pair(7,1), make_pair(7,2), make_pair(7,6), make_pair(0,7), make_pair(1,7), make_pair(2,7)
            , make_pair(3,7), make_pair(4,7), make_pair(5,7), make_pair(6,7)
    };

    vector<coordenada> atacadas = casillasAtacadas(p, j);
    EXPECT_EQ(ordenarVectorPares(esperado), ordenarVectorPares(atacadas));
}

TEST(casillasAtacadasTEST, atacadasJugadorAcutalAlfil) {
    tablero t = {
            {cVACIA, cREY_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cALFIL_N, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cREY_B, cVACIA, cVACIA, cVACIA},
            {cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cVACIA, cTORRE_B},
    };
    posicion p = make_pair(t, NEGRO);

    int j = NEGRO;

    vector<coordenada> esperado = {
            //Rey Negro en (0,1)
            make_pair(0,0), make_pair(0,2), make_pair(1,0), make_pair(1,1), make_pair(1,2),
            //Alfil Negro en (2,0) sin las repetidas hechas por el rey que esta cerca
            make_pair(3,1), make_pair(4,2), make_pair(5,3), make_pair(6,4)
    };

    vector<coordenada> atacadas = casillasAtacadas(p, j);
    EXPECT_EQ(ordenarVectorPares(esperado), ordenarVectorPares(atacadas));
}