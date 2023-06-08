//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);
int filas(toroide t);
int columnas(toroide t);
bool esRectangulo(rectangulo t);
bool esToroide(toroide t);
bool estaViva(toroide t, int f, int c);
int cantidadVivas(toroide t);
int superficieTotal(toroide t);
bool estaVivo(toroide t);
int enCuantosTicksMuere(toroide t);
bool elUltimoesIgualat(vector<toroide> ts, toroide t);
int modToroide(int n, int i);
bool esFilaTrasladada(vector<bool> original, vector<bool> traslacion, int &x);
toroide toroideConFilasYColumnasIntercambiadas(toroide t);
vector<bool> correrUnaPos(vector<bool> v);
bool debeVivir(toroide t, int f, int c);
int vecinosVivos(toroide t,int f,int c);
int filaToroide(toroide t, int f);
int columnaToroide(toroide t, int c);
bool vivaToroide(toroide t, int f, int c);
bool vecinaViva(toroide t, int f, int c, int i, int j);
toroide unaEvolucion(toroide &t);
vector<pair<int,int>> dimensionesValidasParaRectangulo(toroide t, int vivas);
int minimaDimension(vector<pair<int,int>> v);
bool contieneATodasLasVivas(toroide t, int f, int c, int vivas);
rectangulo armarRectangulo(toroide t, int i, int j, int f, int c);
vector<rectangulo> subAreasDelToroide(toroide t, int f, int c);
vector <toroide> secuenciasTraslacionesdeT(toroide t);
toroide trasladarToroide(toroide t, int x, int y);
//bool esTraslacionXHorizontal(vector<bool> f, vector<bool> p, int x);
//vector<bool> moverXposicionesHorizontales(vector<bool> f, int x);
vector<bool> moverUnaPos(vector<bool> &fila);
vector<bool> moverXposicionesHorizontales(vector<bool> fila, int x);
bool esTraslacionXHorizontal(vector<bool> filaT, vector<bool> filaU, int x);
bool esFilaTrasladada(vector<bool> original, vector<bool> traslacion, int &x);
int tamanio(toroide t, int i);
int sizeSecuenciaToroide(vector<toroide> ts);

#endif //REUNIONESREMOTAS_AUXILIARES_H