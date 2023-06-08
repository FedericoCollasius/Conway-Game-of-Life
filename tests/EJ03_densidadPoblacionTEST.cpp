#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(densidadPoblacionTEST, toroideDiagonal){
    vector<bool> a = { true, true, true, true };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 1.0, 0.01);
}

TEST(densidadPoblacionTEST, toroideMuerto){
    vector<bool> a = { false, false, false, false };
    toroide t = { a, a, a, a, a };
    EXPECT_NEAR(densidadPoblacion(t), 0.0, 0.01);
}

TEST(densidadPoblacionTEST, toroideNormal){
    toroide t = {
            {true, false, true},
            {false, true, true},
            {false, true, true},
            {true, false, false},
            {false, true, false},
            {false, false, true}};

    EXPECT_NEAR(densidadPoblacion(t), 0.5, 0.01);
}

TEST(densidadPoblacionTEST, toroide033){
    toroide t = {
            {false, false, false},
            {false, true, false},
            {false, true, true},
            {true, false, false},
            {false, true, false},
            {false, false, true}};

    EXPECT_NEAR(densidadPoblacion(t), 0.33, 0.01);
}