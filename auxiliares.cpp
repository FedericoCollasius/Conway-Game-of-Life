#include "definiciones.h"
#include "auxiliares.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}

vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}

int filas(toroide t){
    return t.size();
}

int columnas(toroide t){
    int col = 0;
    if(filas(t)>0){
        col = t[0].size();
    }
    return col;
}

bool esRectangulo(rectangulo t){
    bool result=true;
    int sizeT0 = t[0].size();
    if(filas(t)>0 && columnas(t)>0){
        for(int i=0; i<filas(t); i++){
            result = result && sizeT0==tamanio(t,i);
        }
    } else {
        result = false;
    }
    return result;
}

int tamanio(toroide t, int i){
    return t[i].size();
}

bool esToroide(toroide t){
    return(esRectangulo(t) && filas(t)>=3 && columnas(t)>=3);
}

bool estaViva(toroide t, int f, int c) {
    return t[f][c];
}

int cantidadVivas(toroide t){
    int result=0;
    for(int i=0; i<filas(t); i++){
        for(int j=0; j<columnas(t); j++){
            if(estaViva(t, i, j)){
                result++;}
        }
    }
    return result;
}

int superficieTotal(toroide t){
    return filas(t)*columnas(t);
}

bool estaVivo(toroide t){
    bool result=false;
    int sizeT = t.size();
    int sizeT0 = t[0].size();
    for(int i=0; i<sizeT; i++){
        for(int j=0; j<sizeT0; j++){
            result = result || estaViva(t, i, j);
        }
    }
    return result;
}

int enCuantosTicksMuere(toroide t){
    int res = 0;
    while(estaVivo(t)){
        unaEvolucion(t);
        res++;
    }
    return res;
}

bool elUltimoesIgualat(vector<toroide> ts, toroide t){
    bool resp = false;
    int sizeTs = ts.size();
    if (ts[sizeTs-1] == t)
        resp = true;
    return resp;
}

bool esFilaTrasladada(vector<bool> original, vector<bool> traslacion, int &x){
    bool resp=false; int sizeOriginal = original.size();
    for(int i=0; i<sizeOriginal; i++){
        if(original==traslacion){
            resp=true;
        }
        else {
            moverUnaPos(original);
            x++;
        }
    }
    return resp;
}

vector<bool> moverUnaPos(vector<bool> &fila){
    vector<bool> f0 = fila;
    int sizeFila = fila.size();
    for (int i=0; i<sizeFila; i++){
        fila[i]=f0[modToroide(i-1,sizeFila)];
    }
    return fila;
}

bool esTraslacionXHorizontal(vector<bool> filaT, vector<bool> filaU, int x){
    return filaU == moverXposicionesHorizontales(filaT,x);
}

vector<bool> moverXposicionesHorizontales(vector<bool> fila, int x){
    for(int i=0; i<x; i++){
        fila = moverUnaPos(fila);
    }
    return fila;
}

toroide toroideConFilasYColumnasIntercambiadas(toroide t){
    vector<bool> f(filas(t),false);
    toroide t0(columnas(t),f);
    for(int i=0; i<columnas(t); i++){
        for(int j=0; j<filas(t); j++){
            t0[i][j]=t[j][i];
        }
    }
    return t0;
}



int modToroide(int n, int i) {
    int result = 0;
    if (n > 0 && i > 0) {
        result = n % i;
    } else {
        if (n < 0 && i > 0) {
            while (n < 0) {
                n = n + i;
            }
            result = n;
        }
    }
    return result;
}

bool debeVivir(toroide t,int f, int c){
    bool result = false;
    if(estaViva(t, f, c)){
        if(vecinosVivos(t,f,c) == 2 || vecinosVivos(t,f,c) == 3){
            result= true;
        } else {
            result= false;
        }
    } else {
        if(vecinosVivos(t,f,c) == 3){
            result= true;
        } else {
            result= false;
        }
    }
    return result;
}

int vecinosVivos(toroide t, int f, int c) {
    int result = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i != 0 || j != 0) && vecinaViva(t, f, c, i, j)) {
                result++;
            }
        }
    }
    return result;
}

bool vecinaViva(toroide t, int f, int c, int i, int j) {
    return vivaToroide(t,f+i,c+j);
}

bool vivaToroide(toroide t, int f, int c) {
    return estaViva(t,filaToroide(t,f),columnaToroide(t,c));
}

int filaToroide(toroide t, int f) {
    return modToroide(f, filas(t));
}

int columnaToroide(toroide t, int c){
    return modToroide(c, columnas(t));
}

toroide unaEvolucion(toroide &t){
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
    return t;
}

int minimaDimension(vector<pair<int,int>> v){ //De una secuencia de dimeniones de rectangulos devuelve la más chica.
    int minPos=0;
    int sizeV =  v.size();
    for(int i = 0; i < sizeV; i++){
        if(v[i].first*v[i].second <= v[minPos].first*v[minPos].second){
            minPos = i;
        }
    }
    return v[minPos].first*v[minPos].second;
}

vector <toroide> secuenciasTraslacionesdeT(toroide t){ // secuencia con todas las traslaciones del toroide t.
    vector<toroide> ts;
    for(int x = 0; x < filas(t); x++){
        for(int y = 0; y < columnas(t); y++){
            ts.push_back(trasladarToroide(t,x,y));
        }
    }
    return ts;
}

toroide trasladarToroide(toroide t, int x, int y){ // traslada x posiciones horizontalmente e y posiciones verticalmente al toroide t.
    toroide out = t;
    for(int i = 0; i < filas(t); i++){
        for(int j = 0; j < columnas(t); j++){
            out[modToroide(i+x,filas(t))][modToroide(j+y,columnas(t))] = t[i][j];
        }
    }
    return out;
}

vector<pair<int,int>> dimensionesValidasParaRectangulo(toroide t, int vivas){ //devuelve la secuencia de dimensiones que podrían contener a las vivas.
    vector<pair<int,int>> resp;
    for(int i = 1; i <= filas(t); i++){
        for(int j = 1; j <= columnas(t); j++){
            if (i*j>= vivas){
                resp.push_back(make_pair(i,j));
            }
        }
    }
    return resp;
}

bool contieneATodasLasVivas(toroide t, int f, int c, int vivas) { //devuelve si hay algun rectangulo con dimensiones f y c en el toroide t que contenga a todas las vivas.
    bool resp = false;
    vector<rectangulo> secuenciaDeRectangulos= subAreasDelToroide(t,f,c);
    int sizeSecuenciaDeRectangulos = secuenciaDeRectangulos.size();
    for(int i = 0; i < sizeSecuenciaDeRectangulos; i++){
        if(cantidadVivas(secuenciaDeRectangulos[i]) == vivas){
            resp = true;
        }
    }
    return resp;
}

vector<rectangulo> subAreasDelToroide(toroide t, int f, int c){ //secuencia con rectangulos del toroide t de dimension f y c.
    vector<rectangulo> resp;
    rectangulo temp;
    for(int i = 0; i < filas(t)-f; i++){
        for(int j = 0; j < columnas(t)-c; j++){
            temp = armarRectangulo(t,i,j,f,c);
            resp.push_back(temp);
        }
    }
    return resp;
}

rectangulo armarRectangulo(toroide t, int i, int j, int f, int c) { // arma un rectangulo del toroide con dimension f y c.
    vector<bool> base(c,false);
    rectangulo out(f,base);
    for(int k = 0; k < f; k++){
        for(int l = 0; l < c; l++){
                    out[k][l] = t[k+i][l+j];
        }
    }
    return out;
}


int sizeSecuenciaToroide(vector<toroide> ts){
    return ts.size();
}