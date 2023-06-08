#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool toroideValido(vector<vector<bool>> const &t) {
    bool resp = false;
    int sizeT = t.size();
    if(sizeT != 0 && esToroide(t))
        return true;
    return resp;
}

// EJERCICIO 2
vector<posicion> posicionesVivas(toroide const &t) {
    vector<posicion> vivos;
    int sizeT = t.size();
    int sizeT0 = t[0].size();
    for(int i=0; i<sizeT; i++){
        for(int j=0; j<sizeT0; j++){
            if(estaViva(t, i, j)){
                posicion p;
                p.first=i;
                p.second=j;
                vivos.push_back(p);}
        }
    }
    return vivos;
}

// EJERCICIO 3
float densidadPoblacion(toroide const &t) {
    float resp = -1;
    resp = (float (cantidadVivas(t))/float (superficieTotal(t)));
    return resp;
}

// EJERCICIO 4
bool evolucionDePosicion(toroide const &t, posicion x) {
    bool resp = false;
    if(debeVivir(t,x.first,x.second))
        resp=true;
    return resp;
}

// EJERCICIO 5
void evolucionToroide(toroide &t){
    toroide t0=t;
    for(int i=0; i<filas(t); i++){
        for(int j=0; j<columnas(t); j++){
            if(debeVivir(t0,i,j)){
                t[i][j]=true;
            } else {
                t[i][j]=false;
            }
        }
    }
}

// EJERCICIO 6
toroide evolucionMultiple(toroide const &t, int K) {
    toroide tk=t;
    for(int i=0; i<K; i++){
        unaEvolucion(tk);
    }
    return tk;
}

// EJERCICIO 7
bool esPeriodico(toroide const &t, int &p){
    int p0=p;
    bool resp = true;
    toroide t0=t;
    toroide t1 = unaEvolucion(t0);
    vector<toroide> ts(1,t1);
    p=0;
    //Metemos en ts las evoluciones de t0
    for(int k=0; k<sizeSecuenciaToroide(ts); k++){
        if(elUltimoesIgualat(ts,t)){
            p=k+1;
            resp = true;
        }
        else {
            if (!estaVivo(ts[k])) {
                resp = false;
            }
            else {
                ts.push_back(unaEvolucion(ts[k]));}
        }
    }
    if(!resp){
        p=p0;
    }
    return resp;
}



// EJERCICIO 8
bool primosLejanos(toroide const &t, toroide const &u) {
    bool resp = false;
    toroide t0 = t;
    toroide u0 = u;
    int p=0; int q=0;
    if(esPeriodico(t,p) && esPeriodico(u,q)){
        unaEvolucion(t0);
        unaEvolucion(u0);
        for(int i=0; i<p; i++){
            resp = resp || (unaEvolucion(t0)==u);
        }
        for(int i=0; i<q; i++){
            resp = resp || (unaEvolucion(u0)==t);
        }
    }
    if(esPeriodico(t,p) && !esPeriodico(u,q)){
        for(int i=0; i<p || estaVivo(u0); i++){
            resp = resp || (unaEvolucion(t0)==u || unaEvolucion(u0)==t);
        }
    }
    if(esPeriodico(u,q) && !esPeriodico(t,p)){
        for(int i=0; i<q || estaVivo(t0); i++){
            resp = resp || (unaEvolucion(u0)==t || unaEvolucion(t0)==u);
        }
    }
    if(!esPeriodico(t,p) && !esPeriodico(u,q)){
        while(estaVivo(t0) || estaVivo(u0)){
            if (unaEvolucion(t0)==u){
                resp = true;
            } else {
                if (unaEvolucion(u0)==t){
                    resp = true;
                }
            }
        }
    }
    return resp;
}

// EJERCICIO 9
int seleccionNatural(vector <toroide> ts) {
    int indiceSobreviviente=0;
    int sizeTS = ts.size();
    for(int i=0; i<sizeTS; i++){
        if(enCuantosTicksMuere(ts[indiceSobreviviente])< enCuantosTicksMuere(ts[i])){
            indiceSobreviviente = i;
        }
    }
    return indiceSobreviviente;
}

// EJERCICIO 10
toroide fusionar(toroide const &t, toroide const &u) {
    toroide out;
    int sizeT0 = t[0].size();
    vector <bool> v(sizeT0,false);
    int sizeT = t.size();
    for(int i=0; i<sizeT; i++){
        out.push_back(v);
    }
    for(int i=0; i<sizeT; i++){
        for(int j=0; j<sizeT0; j++){
            if(estaViva(t, i, j) && estaViva(u, i, j)){
                out[i][j]=true;}
        }
    }
    return out;
}

// EJERCICIO 11
bool vistaTrasladada(toroide const &t, toroide const &u) {
    bool resp = false;
    int sizeU = u.size();
    int sizeT = t.size();
    for (int i = 0; i < sizeU && !resp; i++) {
        int x = 0;
        if (esFilaTrasladada(t[0], u[i], x)) {
            resp = true;
            int traslacionX = x;
            for (int j = 1; j < sizeT; j++) {
                resp = resp && esTraslacionXHorizontal(t[j], u[modToroide(j + i, filas(u))], traslacionX);
            }
        }
    }
    return resp;
}


// EJERCICIO 12
int menorSuperficieViva(toroide const &t) {
    int resp = -1;
    vector <toroide> todasTraslacionesToroide = secuenciasTraslacionesdeT(t);
    int vivas = cantidadVivas(t);
    vector<pair<int,int>> posiblesCandidatosRectangulo = dimensionesValidasParaRectangulo(t,vivas);
    vector<pair<int,int>> posiblesResultadosRectangulo;
    int sizePosiblesCandidatosRectangulo = posiblesCandidatosRectangulo.size();
    int sizeTodasTraslacionesToroide = todasTraslacionesToroide.size();
    for(int i = 0; i < sizeTodasTraslacionesToroide; i++) {
        for (int j = 0; j < sizePosiblesCandidatosRectangulo; j++) {
            if (contieneATodasLasVivas(todasTraslacionesToroide[i], posiblesCandidatosRectangulo[j].first,posiblesCandidatosRectangulo[j].second,vivas)) {
                posiblesResultadosRectangulo.push_back(posiblesCandidatosRectangulo[j]);
            }
        }
    }
    resp = minimaDimension(posiblesResultadosRectangulo);
    return resp;
}