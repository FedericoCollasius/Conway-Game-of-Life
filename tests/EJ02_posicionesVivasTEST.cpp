#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(posicionesVivasTEST, toroideDiagonalVivas){
    toroide t = { 
	{true, false, false},
	{false, true, false},
	{false, false, true},
	{true, false, false},
	{false, true, false},
	{false, false, true}};

    vector<posicion> vivas = {mp(0,0), mp(1,1), mp(2,2), mp(3, 0), mp(4, 1), mp(5, 2)};
    vector<posicion> res = posicionesVivas(t);
    EXPECT_EQ(ordenar(vivas), ordenar(res));
}

TEST(posicionesVivasTEST, toroideMuerto){
    toroide t = {
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false},
            {false, false, false}};

    vector<posicion> vivas = {};
    vector<posicion> res = posicionesVivas(t);
    EXPECT_EQ(ordenar(vivas), ordenar(res));
}

TEST(posicionesVivasTEST, todoVivo){
    toroide t = {
            {true, true, true},
            {true, true, true},
            {true, true, true},
            };

    vector<posicion> vivas = {mp(0,0), mp(0,1), mp(0,2), mp(1,0), mp(1,1), mp(1,2), mp(2,0), mp(2,1), mp(2,2)};
    vector<posicion> res = posicionesVivas(t);
    EXPECT_EQ(ordenar(vivas), ordenar(res));
}

