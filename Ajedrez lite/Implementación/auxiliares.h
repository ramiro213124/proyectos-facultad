//


#ifndef AJEDREZLITE_AUXILIARES_H
#define AJEDREZLITE_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);

vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v);
tablero inicializarTablero();
coordenada setCoord(int i, int j);
tablero tableroActual ( posicion const &p );

casilla setCasilla(int i, int j);


#endif //AJEDREZLITE_AUXILIARES_H
//Ex 1
bool esJugadorValido (int j);
bool CasillasValidas (tablero t);
bool CantidadValidaPiezas (tablero t);
int aparicionesEnTablero(tablero t,coordenada c);
bool PeonesNoCoronados (tablero t);

//Ex 2
bool CantidadPiezasAlInicio(tablero t);
bool piezasEnCoordenadas (tablero t);
bool posicionsiguiente (posicion const p1, posicion const p2, coordenada o, coordenada d);
bool MovimientoyCapturaValida (posicion const p1, coordenada o, coordenada d);


//Ex 3
bool estaEnRango(coordenada x);
vector<coordenada> atacadasRey (tablero t, coordenada x);
vector<coordenada> atacadasPeonBlanco (tablero t, coordenada x);
vector<coordenada> atacadasPeonNegro (tablero t, coordenada x);
vector<coordenada> atacadasTorre (tablero t, coordenada x);
vector<coordenada> atacadasAlfil (tablero t, coordenada x);


//Ex 4

bool perteneceCoordenadaAVec(vector<coordenada>v, coordenada x);
void eliminarRepetidosVecCoordenadas (vector<coordenada> &v);

//Ex 5
void ordenarVecCasillas(vector<casilla>& v);
void sinVacios (vector<casilla> &v);

//Ex 6
bool JugadorEnJaqueMate (posicion const p);
bool MovimientoParaSalirDelJaque (posicion const p);
posicion NuevaPMoviendoOaD (posicion p, coordenada o, coordenada d);
bool JugadorEnJaque (posicion const p,int jugador);
int contrincante (int j);
bool esEmpate (posicion p);
coordenada dondeEstaElRey (posicion const p, int j);
bool reyAhogado (posicion p);

//Ex 8
pair<coordenada,coordenada> unicaCoordenadaPosible (posicion const p);
posicion NuevaPMoviendoOaDModificada (posicion &p, coordenada o, coordenada d);

//Ex 9
vector <coordenada> SecuenciaDeMovPosiblesDePieza (tablero t, coordenada o);
int SeVieneJaque (posicion p);
bool esMovimientoUtil (posicion p, posicion p2);
vector <coordenada> SecuenciaDeAreaNoAtacadaDelRey (posicion p, coordenada o,int j);