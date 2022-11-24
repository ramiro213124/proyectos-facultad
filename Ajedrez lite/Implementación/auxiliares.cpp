#include "definiciones.h"
#include "auxiliares.h"
#include "ejercicios.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}

// TEST
vector<pair<int,int>> ordenarVectorPares(vector<pair<int,int>> &v) {
    sort(v.begin(), v.end());
//    v.erase(unique(v.begin(), v.end()), v.end());
    return v;
}

coordenada setCoord(int i, int j) {
    return make_pair(i,j);
}

tablero tableroActual ( posicion const &p ) {
    return p.first;
}

tablero inicializarTablero(){
    vector<casilla> fila(ANCHO_TABLERO, cVACIA);
    tablero out(ANCHO_TABLERO, fila);
    return out;
}

//Agregadas
casilla setCasilla(int i, int j) {
    return make_pair(i,j);
}

//************ EJERCICIO 1 ***************//

bool esJugadorValido (int j){
    return (j == NEGRO || j == BLANCO);
}
bool CasillasValidas (tablero t){
    int i = 0;
    int j = t.size();
    while (i < t.size() && j == ANCHO_TABLERO){
        j = 0;
        while (j < ANCHO_TABLERO &&
               ((t[i][j] == cVACIA)||(PEON <= t[i][j].first <= REY && BLANCO <= t[i][j].second <= NEGRO))){
            j++;
        }
        i++;
    }
    return i == ANCHO_TABLERO;
}

int aparicionesEnTablero(tablero t,pair<int,int> casilla){
    int contador = 0;
    for (int i = 0 ; i < ANCHO_TABLERO;i++){
        for (int j = 0; j < ANCHO_TABLERO;j++){
            if (t[i][j] == casilla){
                contador++;
            }
        }
    }
    return contador;
}

bool CantidadValidaPiezas (tablero t){
    vector <int> ListaCasillas;
    int jugador = BLANCO;
    while (jugador == BLANCO || jugador == NEGRO){
        int pieza = PEON;
        while (pieza <= REY){
            ListaCasillas.push_back(aparicionesEnTablero(t,setCasilla(pieza,jugador)));
            pieza ++;
        }
        jugador++;
    }
    return (ListaCasillas[0] <= ANCHO_TABLERO && ListaCasillas[4] <= ANCHO_TABLERO) &&
           (ListaCasillas[1] <= 2 && ListaCasillas[5] <= 2) &&
           (ListaCasillas[2] <= 2 + (ANCHO_TABLERO-ListaCasillas[0]) && ListaCasillas[6] <= 2 + (ANCHO_TABLERO-ListaCasillas[4])) &&
           (ListaCasillas[3] == 1 && ListaCasillas[7] == 1);
}

bool PeonesNoCoronados (tablero t){
    int i = 0;
    while (i < ANCHO_TABLERO && t[0][i] != cPEON_B && t[ANCHO_TABLERO - 1 ][i] != cPEON_N ){
        i ++;
    }
    return i == ANCHO_TABLERO;
}

//************ EJERCICIO 2 ***************//

bool CantidadPiezasAlInicio (tablero t){
    return  aparicionesEnTablero(t,setCasilla(TORRE,NEGRO)) == 2 &&
            aparicionesEnTablero(t,setCasilla(TORRE,BLANCO)) == 2 &&
            aparicionesEnTablero(t,setCasilla(ALFIL,NEGRO)) == 2 &&
            aparicionesEnTablero(t,setCasilla(ALFIL,BLANCO)) == 2 &&
            aparicionesEnTablero(t,setCasilla(PEON,NEGRO)) == ANCHO_TABLERO &&
            aparicionesEnTablero(t,setCasilla(PEON,BLANCO)) == ANCHO_TABLERO ;
}



bool piezasEnCoordenadas (tablero t){
    int i = 0;
    int j = ANCHO_TABLERO;
    vector <pair <int,int>> fila0 = {cTORRE_N,cVACIA,cALFIL_N,cVACIA,cREY_N,cALFIL_N,cVACIA,cTORRE_N};
    vector <pair <int,int>> fila7 = {cTORRE_B,cVACIA,cALFIL_B,cVACIA,cREY_B,cALFIL_B,cVACIA,cTORRE_B};
    while ( i < ANCHO_TABLERO/2 && j == ANCHO_TABLERO){
        j = 0;
        if (i == 0 && (t[i] == fila0 )&& t[ANCHO_TABLERO - 1 - i] == fila7 ){
            j = ANCHO_TABLERO;
        }
        if (i == 1){
            while (j < ANCHO_TABLERO && t[i][j] == cPEON_N && t[ANCHO_TABLERO - 1 - i][j] == cPEON_B){
                j++;
            }
        }
        if (i == 2 || i == 3){
            while (j < ANCHO_TABLERO && t[i][j] == cVACIA && t[ANCHO_TABLERO - 1 - i][j] == cVACIA){
                j++;
            }
        }
        i++;
    }
    return i == ANCHO_TABLERO/2;

}

//************ EJERCICIO 3 ***************//

bool estaEnRango(coordenada x){
    if(x.first >= 0 && x.first < ANCHO_TABLERO && x.second >= 0 && x.second < ANCHO_TABLERO){
        return true;
    } else{
        return false;
    }
}

vector<coordenada> atacadasRey (tablero t, coordenada x){
    vector<coordenada> res;
    coordenada aux1=x;
    coordenada aux2;
    aux2=make_pair(aux1.first-1,aux1.second-1);
    if(estaEnRango(aux2)){
        res.push_back(aux2);
    }
    aux2=make_pair(aux1.first-1, aux1.second);
    if(estaEnRango(aux2)){
        res.push_back(aux2);
    }
    aux2=make_pair(aux1.first-1,aux1.second+1);
    if(estaEnRango(aux2)){
        res.push_back(aux2);
    }
    aux2=make_pair(aux1.first,aux1.second-1);
    if(estaEnRango(aux2)){
        res.push_back(aux2);
    }
    aux2=make_pair(aux1.first,aux1.second+1);
    if(estaEnRango(aux2)){
        res.push_back(aux2);
    }
    aux2=make_pair(aux1.first+1,aux1.second-1);
    if(estaEnRango(aux2)){
        res.push_back(aux2);
    }
    aux2=make_pair(aux1.first+1,aux1.second);
    if(estaEnRango(aux2)){
        res.push_back(aux2);
    }
    aux2=make_pair(aux1.first+1,aux1.second+1);
    if(estaEnRango(aux2)){
        res.push_back(aux2);
    }
    return res;
}

vector<coordenada> atacadasPeonBlanco (tablero t, coordenada x){
    vector<coordenada> res;
    coordenada aux1=x;
    coordenada aux2;
    aux2=make_pair(aux1.first-1,aux1.second-1);
    if(estaEnRango(aux2)){
        res.push_back(aux2);
    }
    aux2=make_pair(aux1.first-1,aux1.second+1);
    if(estaEnRango(aux2)){
        res.push_back(aux2);
    }
    return res;
}

vector<coordenada> atacadasPeonNegro (tablero t, coordenada x){
    vector<coordenada> res;
    coordenada aux1=x;
    coordenada aux2;
    aux2=make_pair(aux1.first+1,aux1.second-1);
    if(estaEnRango(aux2)){
        res.push_back(aux2);
    }
    aux2=make_pair(aux1.first+1,aux1.second+1);
    if(estaEnRango(aux2)){
        res.push_back(aux2);
    }
    return res;
}

vector<coordenada> atacadasTorre (tablero t, coordenada x){
    vector<coordenada> res;
    // Movimiento a la derecha
    coordenada aux=x;
    aux.second=x.second+1;
    while(estaEnRango(aux) && t[aux.first][aux.second]== cVACIA){
        res.push_back(aux);
        aux.second++;
    }
    if(estaEnRango(aux) && t[aux.first][aux.second]!=cVACIA ){
        res.push_back(aux);
    }
    // Movimiento a la izquierda
    coordenada aux2=x;
    aux2.second=x.second-1;
    while(estaEnRango(aux2) && t[aux2.first][aux2.second]== cVACIA ){
        res.push_back(aux2);
        aux2.second--;
    }
    if(estaEnRango(aux2) && t[aux2.first][aux2.second]!=cVACIA ){
        res.push_back(aux2);
    }

    // Movimiento hacia arriba
    coordenada aux3=x;
    aux3.first=x.first-1;
    while(estaEnRango(aux3) && t[aux3.first][aux3.second]== cVACIA){
        res.push_back(aux3);
        aux3.first--;
    }
    if(estaEnRango(aux3) && t[aux3.first][aux3.second]!=cVACIA){
        res.push_back(aux3);
    }

    // Movimiento hacia abajo
    coordenada aux4=x;
    aux4.first=x.first+1;
    while(estaEnRango(aux4) && t[aux4.first][aux4.second]== cVACIA){
        res.push_back(aux4);
        aux4.first++;
    }
    if( estaEnRango(aux4) && t[aux4.first][aux4.second]!=cVACIA){
        res.push_back(aux4);
    }
    return res;
}

vector<coordenada> atacadasAlfil (tablero t, coordenada x){
    vector<coordenada> res;
    // Movimiento a la diagonal derecha superior
    coordenada aux=x;
    aux.first=x.first-1;
    aux.second=x.second+1;
    while(estaEnRango(aux) && t[aux.first][aux.second]== cVACIA){
        res.push_back(aux);
        aux.first--;
        aux.second++;
    }
    if(estaEnRango(aux) && t[aux.first][aux.second]!=cVACIA ){
        res.push_back(aux);
    }
    // Movimiento a la diagnoal izquierda superior
    coordenada aux2=x;
    aux2.first=x.first-1;
    aux2.second=x.second-1;
    while(estaEnRango(aux2) && t[aux2.first][aux2.second]== cVACIA ){
        res.push_back(aux2);
        aux2.first--;
        aux2.second--;
    }
    if(estaEnRango(aux2) && t[aux2.first][aux2.second]!=cVACIA ){
        res.push_back(aux2);
    }

    // Movimiento hacia la diagonal izquierda inferior
    coordenada aux3=x;
    aux3.first=x.first+1;
    aux3.second=x.second-1;
    while(estaEnRango(aux3) && t[aux3.first][aux3.second]== cVACIA){
        res.push_back(aux3);
        aux3.first++;
        aux3.second--;
    }
    if(estaEnRango(aux3) && t[aux3.first][aux3.second]!=cVACIA){
        res.push_back(aux3);
    }

    // Movimiento hacia la diagonal derecha inferior
    coordenada aux4=x;
    aux4.first=x.first+1;
    aux4.second=x.second+1;
    while(estaEnRango(aux4) && t[aux4.first][aux4.second]== cVACIA){
        res.push_back(aux4);
        aux4.first++;
        aux4.second++;
    }
    if( estaEnRango(aux4) && t[aux4.first][aux4.second]!=cVACIA){
        res.push_back(aux4);
    }
    return res;
}
bool perteneceCoordenadaAVec(vector<coordenada>v, coordenada x){
    bool res=false;
    for(int i=0;i<v.size();i++){
        if(v[i]==x){
            res= true;
        }
    }
    return res;
}
void eliminarRepetidosVecCoordenadas (vector<coordenada> &v){
    vector<coordenada> res;
    for(int i=0;i<v.size();i++){
        if(!perteneceCoordenadaAVec(res,v[i])){
            res.push_back(v[i]);
        }
    }
    v.clear();
    for(int i=0;i<res.size();i++){
        v.push_back(res[i]);
    }
}

//************ EJERCICIO 4 ***************//

bool posicionsiguiente (posicion const p1, posicion const p2, coordenada o, coordenada d){
    int h = 0;
    int j;
    for(int i = 0 ; i < ANCHO_TABLERO; i++){
        j = 0;
        while (j < ANCHO_TABLERO){
            if (p1.first[i][j] == p2.first[i][j] && setCoord(i,j) != o && setCoord(i,j) != d ){
                h ++;
            }
            j++;
        }
    }

    if (p2.first[o.first][o.second] == cVACIA && p2.first[d.first][d.second] == p1.first[o.first][o.second] &&
            !(p1.first[o.first][o.second] == cPEON_B && (o.first == 1  && d.first == 0)) &&
            !(p1.first[o.first][o.second] == cPEON_N && (o.first == 6  && d.first == 7))){
        h = h + 2;
    }
    if (p1.first[o.first][o.second] == cPEON_B && p2.first[d.first][d.second] == cTORRE_B ){
        h = h + 2;
    }
    if (p1.first[o.first][o.second] == cPEON_N && p2.first[d.first][d.second] == cTORRE_N ){
        h = h + 2;
    }


        return h== pow(ANCHO_TABLERO, 2) ;
}


bool MovimientoyCapturaValida (posicion const p1, coordenada o, coordenada d) {
    return perteneceCoordenadaAVec(SecuenciaDeMovPosiblesDePieza(p1.first,o),d) &&
    p1.first[o.first][o.second].second != p1.first[d.first][d.second].second;
}
//************ EJERCICIO 5 ***************//

void sinVacios (vector<casilla> &v){
    vector<coordenada> res;
    for(int i=0;i<v.size();i++){
        if(v[i]!=cVACIA)
            res.push_back(v[i]);
    }
    v.clear();
    for(int i=0;i<res.size();i++){
        v.push_back(res[i]);
    }
}

void ordenarVecCasillas(vector<casilla>& v) {
    casilla aux;
    for(int i=0;i<(v.size()-1);i++){
        for(int j=0;j<(v.size()-1);j++){
            if(v[j].first>v[j+1].first){;
                aux=v[j+1];
                v[j+1]=v[j];
                v[j]=aux;
            }
        }
    }
}

//************ EJERCICIO 6 ***************//
int cantidadDePiezasEnTablero (tablero t){
    int res=0;
    for(int i=0;i<ANCHO_TABLERO;i++){
        for(int j=0;j<ANCHO_TABLERO;j++){
            if(t[i][j].first!=0){
                res++;
            }
        }
    }
    return res;
}

bool reyAhogado (posicion p){
    bool res=false;
    if (!JugadorEnJaque(p, p.second) && !MovimientoParaSalirDelJaque(p)){
        res=true;
    }
    return res;
}

bool soloDosReyes (posicion p){
    bool res=false;
    if(cantidadDePiezasEnTablero(p.first)==2){
        if (aparicionesEnTablero(p.first,setCoord(REY,1))==1 && aparicionesEnTablero(p.first,setCoord(REY,2))==1){
            res=true;
        }
    }
    return res;
}


bool esEmpate (posicion p){
    bool res=false;
    if(soloDosReyes(p)||reyAhogado(p)){
        res= true;
    }
    return res;
}

coordenada dondeEstaElRey (posicion const p, int jugador) {
    coordenada res;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if((p.first[i][j]).first==REY && p.first[i][j].second==jugador){
                res=setCoord(i,j);
            }
        }
    }
    return res;
}

int contrincante (int j){
    if (j== BLANCO){
        j = NEGRO;
    }
    else {
        j = BLANCO;
    }
    return j;
}

bool JugadorEnJaque (posicion const p,int jugador){
    bool resp = false;
    vector <coordenada> CoordenadasQueAtacaJ = casillasAtacadas(p,contrincante(jugador));
    if (perteneceCoordenadaAVec(CoordenadasQueAtacaJ,dondeEstaElRey(p,jugador))){
        resp = true;
    }
    return resp;
}

posicion NuevaPMoviendoOaD (posicion p, coordenada o, coordenada d){
    if(p.second==BLANCO && p.first[o.first][o.second]==make_pair(PEON,BLANCO) && o.first==1 && d.first==0){
        p.first[d.first][d.second] = make_pair(TORRE,BLANCO);
        p.first[o.first][o.second] = cVACIA;
        p.second = contrincante(p.second);
        return p;
    }
    if(p.second==NEGRO && p.first[o.first][o.second]==make_pair(PEON,NEGRO) && o.first==6 && d.first==7){
        p.first[d.first][d.second] = make_pair(TORRE,NEGRO);
        p.first[o.first][o.second] = cVACIA;
        p.second = contrincante(p.second);
        return p;
    }
    p.first[d.first][d.second] = p.first[o.first][o.second];
    p.first[o.first][o.second] = cVACIA;
    p.second = contrincante(p.second);
    return p;
}

bool MovimientoParaSalirDelJaque (posicion const p){
    bool resp = false;
     for (int i = 0 ; i < ANCHO_TABLERO ; i++) {
         for (int j = 0; j < ANCHO_TABLERO; j++) {
             if (p.first[i][j].second == p.second) {
                 vector<coordenada> s = SecuenciaDeMovPosiblesDePieza(p.first, setCoord(i, j));
                     for (int z = 0; z < s.size(); z++) {
                         posicion p2 = NuevaPMoviendoOaD(p, setCoord(i, j), setCoord(s[z].first,s[z].second));
                         if (posicionSiguienteCorrecta(p, p2, setCoord(i, j), setCoord(s[z].first,s[z].second)) &&
                             !JugadorEnJaque(p2, contrincante(p2.second))) {
                             resp = true;
                         }
                     }
                 }

         }
     }
     return resp;

}



bool JugadorEnJaqueMate (posicion const p){
    bool resp = JugadorEnJaque(p,p.second) && !MovimientoParaSalirDelJaque(p);
    return resp;
}



//************ EJERCICIO 8 ***************//
posicion NuevaPMoviendoOaDModificada (posicion &p, coordenada o, coordenada d){
    if(p.second==BLANCO && p.first[o.first][o.second]==make_pair(PEON,BLANCO) && o.first==1 && d.first==0){
        p.first[d.first][d.second] = make_pair(TORRE,BLANCO);
        p.first[o.first][o.second] = cVACIA;
        p.second = contrincante(p.second);
        return p;
    }
    if(p.second==NEGRO && p.first[o.first][o.second]==make_pair(PEON,NEGRO) && o.first==6 && d.first==7){
        p.first[d.first][d.second] = make_pair(TORRE,NEGRO);
        p.first[o.first][o.second] = cVACIA;
        p.second = contrincante(p.second);
        return p;
    }
    p.first[d.first][d.second] = p.first[o.first][o.second];
    p.first[o.first][o.second] = cVACIA;
    p.second = contrincante(p.second);
    return p;
}


pair<coordenada,coordenada> unicaCoordenadaPosible (posicion const p){
    pair<coordenada,coordenada> res={make_pair(-1,-1),make_pair(-1,-1)};
    for (int i = 0 ; i < ANCHO_TABLERO ; i++){
        for (int j = 0; j < ANCHO_TABLERO; j++) {
            if (p.first[i][j].second == p.second) {
                    vector<coordenada> s = SecuenciaDeMovPosiblesDePieza(p.first, setCoord(i, j));
                    for (int z = 0; z < s.size(); z++){
                        posicion p2 = NuevaPMoviendoOaD (p, make_pair(i,j), make_pair(s[z].first, s[z].second));
                        if (posicionSiguienteCorrecta(p,p2,setCoord(i,j), setCoord(s[z].first, s[z].second)) && !JugadorEnJaque(p2,contrincante(p2.second))){
                            res.first = make_pair(i,j);
                            res.second = make_pair(s[z].first, s[z].second);
                        }
                    }
            }
        }
    }
    return res;

}

//************ EJERCICIO 9 ***************//

vector <coordenada> SecuenciaDeMovPosiblesDePieza (tablero t, coordenada o){
    vector<coordenada> res;
    int pieza = t[o.first][o.second].first;
    int jugador = t[o.first][o.second].second;
    if(pieza==REY){
        vector <coordenada> AtacadasRey = atacadasRey (t, o);
        for (int i = 0; i < AtacadasRey.size(); i++){
            if (t[AtacadasRey[i].first][AtacadasRey[i].second] == cVACIA || t[AtacadasRey[i].first][AtacadasRey[i].second].second != jugador){
                res.push_back(AtacadasRey[i]);
            }
        }

    }
    if(pieza==PEON && jugador==BLANCO){
        if (estaEnRango(setCoord(o.first-1,o.second)) && t[o.first-1][o.second] == cVACIA){
            res.push_back(setCoord(o.first-1,o.second));
        }
        if (estaEnRango(setCoord(o.first-1,o.second-1)) && t[o.first-1][o.second-1].second == NEGRO){
            res.push_back(setCoord(o.first-1,o.second-1));
        }
        if (estaEnRango(setCoord(o.first-1,o.second+1)) && t[o.first-1][o.second+1].second == NEGRO){
            res.push_back(setCoord(o.first-1,o.second+1));
        }

    }
    if(pieza==PEON && jugador==NEGRO){
        if (estaEnRango(setCoord(o.first+1,o.second)) && t[o.first+1][o.second] == cVACIA){
            res.push_back(setCoord(o.first+1,o.second));
        }
        if (estaEnRango(setCoord(o.first+1,o.second-1)) && t[o.first+1][o.second-1].second == BLANCO){
            res.push_back(setCoord(o.first+1,o.second-1));
        }
        if (estaEnRango(setCoord(o.first+1,o.second+1)) && t[o.first+1][o.second+1].second == BLANCO){
            res.push_back(setCoord(o.first+1,o.second+1));
        }
    }
    if(pieza==TORRE){
        vector <coordenada> AtacadasTorre = atacadasTorre (t, o);
        for (int i = 0; i < AtacadasTorre.size(); i++){
            if (t[AtacadasTorre[i].first][AtacadasTorre[i].second] == cVACIA || t[AtacadasTorre[i].first][AtacadasTorre[i].second].second != jugador){
                res.push_back(AtacadasTorre[i]);
            }
        }
    }
    if(pieza==ALFIL) {
        vector <coordenada> AtacadasAlfil = atacadasAlfil (t, o);
        for (int i = 0; i < AtacadasAlfil.size(); i++){
            if (t[AtacadasAlfil[i].first][AtacadasAlfil[i].second] == cVACIA || t[AtacadasAlfil[i].first][AtacadasAlfil[i].second].second != jugador){
                res.push_back(AtacadasAlfil[i]);
            }
        }

    }
    return res;
}

int SeVieneJaque (posicion p) {
    int k = 0;
    vector<posicion> PosicionesPosibles1;
    vector<posicion> PosicionesPosibles2;

    for (int i = 0; i < ANCHO_TABLERO; i++) {
        for (int j = 0; j < ANCHO_TABLERO; j++) {
            if (p.first[i][j].second == p.second) {
                vector<coordenada> s = SecuenciaDeMovPosiblesDePieza(p.first, setCoord(i, j));
                for (int z = 0; z < s.size(); z++) {
                    posicion p2 = NuevaPMoviendoOaD(p, setCoord(i, j), setCoord(s[z].first, s[z].second));
                    if (!esEmpate(p2) && !reyAhogado(p2) && esMovimientoUtil(p,p2) ) {
                        if (JugadorEnJaqueMate(p2)) {
                            k = 1;
                        } else {
                            posicion pNueva = p;
                            coordenada o = setCoord(i, j);
                            coordenada d = setCoord(s[z].first, s[z].second);
                            secuencia f = {{o, d}};
                            ejecutarSecuenciaForzada(pNueva, f);
                            PosicionesPosibles1.push_back(pNueva);
                        }
                    }
                }
            }
        }
    }
    if (k == 0) {
        int pos = 0;
        while (pos < PosicionesPosibles1.size()) {
            posicion pi = PosicionesPosibles1[pos];
            for (int i = 0; i < ANCHO_TABLERO; i++) {
                for (int j = 0; j < ANCHO_TABLERO; j++) {
                    if (pi.first[i][j].second == pi.second ) {
                        vector<coordenada> s = SecuenciaDeMovPosiblesDePieza(pi.first,  setCoord(i, j));
                        for (int z = 0; z < s.size(); z++) {
                            posicion p2 = NuevaPMoviendoOaD(pi, setCoord(i, j), setCoord(s[z].first, s[z].second));
                            if (!esEmpate(p2) && !reyAhogado(p2) && esMovimientoUtil(pi,p2)) {
                                if (JugadorEnJaqueMate(p2)) {
                                    k = 2;
                                } else {
                                    posicion pNueva = pi;
                                    coordenada o = setCoord(i, j);
                                    coordenada d = setCoord(s[z].first, s[z].second);
                                    secuencia f = {{o, d}};
                                    ejecutarSecuenciaForzada(pNueva, f);
                                    PosicionesPosibles2.push_back(pNueva);
                                }
                            }
                        }
                    }
                }
            }
            pos++;
        }
    }
    if (k == 0) {
        int pos = 0;
        while (pos < PosicionesPosibles2.size()) {
            posicion pi = PosicionesPosibles2[pos];
            for (int i = 0; i < ANCHO_TABLERO; i++) {
                for (int j = 0; j < ANCHO_TABLERO; j++) {
                    if (pi.first[i][j].second == pi.second ) {
                        vector<coordenada> s = SecuenciaDeMovPosiblesDePieza(pi.first,  setCoord(i, j));
                        for (int z = 0; z < s.size(); z++) {
                            posicion p2 = NuevaPMoviendoOaD(pi, setCoord(i, j), setCoord(s[z].first, s[z].second));
                            if (!esEmpate(p2) && !reyAhogado(p2) && esMovimientoUtil(pi,p2)) {
                                if (JugadorEnJaqueMate(p2)) {
                                    k = 3;
                                }
                            }
                        }
                    }
                }
            }
            pos++;
        }
    }
    return k;
}

bool esMovimientoUtil (posicion p, posicion p2){
    int jugadorQueAtaca = p.second;
    bool res = false;
    int PosicionesReyAntes = 0;
    int PosicionesReyDespues = 0;
    coordenada coordenadaRey = dondeEstaElRey(p,contrincante(jugadorQueAtaca));

    vector <coordenada> MovimientosRey = SecuenciaDeMovPosiblesDePieza(p2.first,coordenadaRey);
    vector <coordenada> MovimientosReyAntes = SecuenciaDeMovPosiblesDePieza(p.first,coordenadaRey);

    vector <coordenada> MovimientosReyValidos;
    for (int i = 0 ; i < MovimientosRey.size();i++) {
        if (!perteneceCoordenadaAVec(casillasAtacadas(p2, jugadorQueAtaca), MovimientosRey[i])) {
            MovimientosReyValidos.push_back(MovimientosRey[i]);
        }
    }
    for (int j = 0 ; j < MovimientosRey.size();j++) {
        if (perteneceCoordenadaAVec(casillasAtacadas(p2, jugadorQueAtaca), MovimientosRey[j])) {
            PosicionesReyDespues ++;
        }
    }
    for (int j = 0 ; j < MovimientosReyAntes.size();j++) {
        if (perteneceCoordenadaAVec(casillasAtacadas(p, jugadorQueAtaca), MovimientosRey[j])) {
            PosicionesReyAntes ++;
        }
    }

    if (casillasAtacadas(p, jugadorQueAtaca).size() < casillasAtacadas(p2, jugadorQueAtaca).size() || JugadorEnJaque(p2,contrincante(jugadorQueAtaca)) || PosicionesReyDespues > PosicionesReyAntes){
        res = true;
    }
    return res &&  MovimientosReyValidos.size() <= 1;
}
