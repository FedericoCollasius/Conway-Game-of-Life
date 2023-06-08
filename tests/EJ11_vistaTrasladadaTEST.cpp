#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(vistaTrasladadaTEST, muevoTerceraFilaParaArriba){
    toroide t1 = { 
                  {true, false, false}, // 1
                  {false, true, false}, // 2
                  {false, false, true}};// 3
    toroide t2 = { 
                  {false, false, true}, // 3
                  {true, false, false}, // 1
                  {false, true, false}};// 2

    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, DiagonalVsTodoTrue){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {true, true, true},
                  {true, true, true},
                  {true, true, true}}; 
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}

/*
1 0 1 0
0 0 0 0
1 1 0 0     0 1 1 0
1 1 1 1     1 1 1 1
            0 1 0 1
            0 0 0 0
*/

TEST(vistaTrasladadaTEST, esTraslacion){
    toroide t1 = {
            {true, false, true, false},
            {false, false, false, false},
            {true, true, false, false},
            {true, true, true, true}};
    toroide t2 = {
            {false, true, true, false},
            {true, true, true, true},
            {false, true, false, true},
            {false, false, false, false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, esTraslacionSalvoPorUnaFila){
    toroide t1 = {
            {true, false, true, false},
            {false, false, false, false},
            {true, true, false, false},
            {true, true, true, true}};
    toroide t2 = {
            {false, true, true, false},
            {true, true, true, true},
            {true, false, true, false},
            {false, false, false, false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}


TEST(vistaTrasladadaTEST, x2y3){
    toroide t1 = {
            {true, false, true},
            {false, false, false},
            {true, true, false},
            {true, true, true}};
    toroide t2 = {
            {false, false, false},
            {true, false, true},
            {true, true, true},
            {false, true, true}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST,TraslacionEnXeY) {
    toroide t1 = {
            {true,  false, false},
            {false, false, false},
            {false, true,  false}};
    toroide t2 = {
            {false, false, true},
            {false, true,  false},
            {false, false, false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST,mismoToroide) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, true,  false, false},
            {false, true,  false, true,  false},
            {false, false, true,  false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, true,  false, false},
            {false, true,  false, true,  false},
            {false, false, true,  false, false},
            {false, false, false, false, false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}