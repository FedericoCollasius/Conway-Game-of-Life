#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(menorSuperficieVivaTEST, enunciado){
    toroide t = {
            {true, false, false, true},   // 1
            {false, false, false, false}, // 2
            {false, false, false, false}, // 3
            {true, true, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 6);
}

TEST(menorSuperficieVivaTEST, toroideGenerico){
    toroide t = {
            {false, false, false, false},   // 1
            {false, true, true, false}, // 2
            {false, true, true, false}, // 3
            {false, false, false, false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 4);
}

TEST(menorSuperficieVivaTEST, toroideGenerico2){
    toroide t = {
            {true, false, false, false,true},
            {false, false, false, false,false},   // 1
            {false, false, true, false,false}, // 2
            {false, false, false, false,false}, // 3
            {true, false, false, false,true}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 16);
}

TEST(menorSuperficieVivaTEST, toroideGenerico3){
    toroide t = {
            {false, false, false, false,false},
            {false, true, false, true,false},   // 1
            {false, false, true, false,false}, // 2
            {false, true, false, true,false}, // 3
            {false, false, false, false,false}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 9);
}

TEST(menorSuperficieVivaTEST, toroideGenerico4){
    toroide t = {
            {false, false, false, false,false},
            {false, false, false, false,false},   // 1
            {false, false, false, false,false}, // 2
            {false, false, false, false,false}, // 3
            {false, false, false, false,true}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 1);
}

TEST(menorSuperficieVivaTEST, toroideGenerico5){
    toroide t = {
            {false, false, false, false,true},
            {false, false, false, false,false},   // 1
            {false, false, false, false,false}, // 2
            {false, false, false, false,false}, // 3
            {false, false, false, false,true}};  // 4

    int res = menorSuperficieViva(t);
    EXPECT_EQ(res, 2);
}
