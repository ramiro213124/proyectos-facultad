#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool posicionValida ( pair < tablero, int > const &p ) {
    bool resp = esJugadorValido(p.second)  && CasillasValidas(p.first) && CantidadValidaPiezas(p.first) && PeonesNoCoronados(p.first);
    return resp;
}

// EJERCICIO 2
bool posicionInicial ( posicion const &p ) {
    bool resp = (p.second == BLANCO) && CantidadPiezasAlInicio(p.first) && piezasEnCoordenadas(p.first);
    return resp;
}
// EJERCICIO 3
vector <coordenada> casillasAtacadas ( posicion const &p, int jugador ) {
    vector <coordenada> cA;
    tablero t=p.first;
    for(int i=0;i<ANCHO_TABLERO;i++){
        for(int j=0;j<ANCHO_TABLERO;j++){
            if(t[i][j].second==jugador){
                if((t[i][j]).first==REY){
                    for(int k=0;k<atacadasRey(t,setCoord(i,j)).size();k++){
                        cA.push_back(atacadasRey(t,setCoord(i,j))[k]);
                    }
                }
                if((t[i][j]).first==PEON && jugador==BLANCO){
                    for(int k=0;k<atacadasPeonBlanco(t,setCoord(i,j)).size();k++){
                        cA.push_back(atacadasPeonBlanco(t,setCoord(i,j))[k]);
                    }
                }
                if((t[i][j]).first==PEON && jugador==NEGRO){
                    for(int k=0;k<atacadasPeonNegro(t,setCoord(i,j)).size();k++){
                        cA.push_back(atacadasPeonNegro(t,setCoord(i,j))[k]);
                    }
                }
                if((t[i][j]).first==TORRE){
                    for(int k=0;k<atacadasTorre(t,setCoord(i,j)).size();k++){
                        cA.push_back(atacadasTorre(t,setCoord(i,j))[k]);
                    }
                }
                if((t[i][j]).first==ALFIL){
                    for(int k=0;k<atacadasAlfil(t,setCoord(i,j)).size();k++){
                        cA.push_back(atacadasAlfil(t,setCoord(i,j))[k]);
                    }
                }
            }
        }
    }
    eliminarRepetidosVecCoordenadas(cA);
    return cA;
}
// EJERCICIO 4
bool posicionSiguienteCorrecta ( posicion const &p1, posicion const &p2, coordenada o, coordenada d ) {
    bool resp = posicionsiguiente(p1,p2,o,d) &&  MovimientoyCapturaValida (p1, o, d);
    return resp;
}
// EJERCICIO 5
void ordenarTablero ( posicion &p ) {
    int l=0;
    int j=0;
    vector<casilla> aux;
    for(int i=0;i<ANCHO_TABLERO;i++){
        aux=p.first[i];
        sinVacios(aux);
        if(aux.size()!=0) {
            ordenarVecCasillas(aux);
            while (j< ANCHO_TABLERO) {
                if (p.first[i][j].first != 0 && p.first[i][j].second != 0) {
                    p.first[i][j] = aux[l];
                    l++;
                }
                j++;
            }
            l=0;
            j=0;
        }
    }
}

// EJERCICIO 6
bool finDeLaPartida ( posicion const &p, int &j ) {
    bool resp;
    if (esEmpate(p) || reyAhogado(p)){
        resp = true;
        j = 0;
    }
    if (JugadorEnJaqueMate(p)){
        resp = true;
        j = contrincante(p.second);
    }
    return resp;
}

// EJERCICIO 7
bool hayJaqueDescubierto ( posicion const &p ) {
        bool resp = false;
        for (int i = 0; i < ANCHO_TABLERO; i++) {
            for (int j = 0; j < ANCHO_TABLERO; j++) {
                if (p.first[i][j].second == p.second) {
                    if (p.first[i][j].second == p.second) {
                        vector<coordenada> s = SecuenciaDeMovPosiblesDePieza(p.first, setCoord(i, j));
                        for (int z = 0; z < s.size(); z++) {
                            posicion p2 = NuevaPMoviendoOaD(p, setCoord(i, j), setCoord(s[z].first, s[z].second));
                            if (posicionSiguienteCorrecta(p, p2, setCoord(i, j), setCoord(s[z].first, s[z].second)) &&
                                JugadorEnJaque(p2, p2.second)) {
                                resp = true;
                            }
                        }
                    }
                }
            }
        }
        return resp;
    }


// EJERCICIO 8
void ejecutarSecuenciaForzada ( posicion &p, secuencia s ) {
    for(int i=0;i<s.size();i++){
        NuevaPMoviendoOaDModificada(p,s[i].first,s[i].second);
        pair<coordenada,coordenada> par=unicaCoordenadaPosible(p);
        NuevaPMoviendoOaDModificada(p,par.first,par.second);
    }
}

// EJERCICIO 9
int seVieneElJaqueEn ( posicion const & p ) {
    int k = SeVieneJaque(p);
    return k;

}
