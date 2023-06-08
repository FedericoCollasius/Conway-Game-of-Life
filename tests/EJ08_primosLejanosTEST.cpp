#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(primosLejanosTEST, toroideHorizontalPeriodico2){
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true, true, true, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, true, false, false},
            {false, false, true, false, false},
            {false, false, true, false, false},
            {false, false,false, false, false} };
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

/*TEST(primosLejanosTEST, toroideEvolucion){
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true} };

    toroide evo_t = { {true, true, true},
                      {true, true, true},
                      {true, true, true} };

    bool res = primosLejanos(evo_t, t);
    EXPECT_TRUE(res);
    res = primosLejanos(t, evo_t);
    EXPECT_TRUE(res);
}*/


TEST(primosLejanosTEST, unoMuertoUnoPeriodico){
    toroide t = {             {false, false, false, false, false},
                              {false, false, true, false, false},
                              {false, false, true, false, false},
                              {false, false, true, false, false},
                              {false, false,false, false, false} };

    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };

    bool res = primosLejanos(t, t2);
    EXPECT_FALSE(res);
    res = primosLejanos(t2, t);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, unoEsPeriodico){
    toroide t = {             {false, false, false, false, false},
                              {false, false, true, false, false},
                              {false, false, true, false, false},
                              {false, false, true, false, false},
                              {false, false,false, false, false} };

    toroide u = {
            {false, false, false, false, false},
            {false, true, false, false, false},
            {false, true, true, true, false},
            {false, false, false, true, false},
            {false, false,false, false, false} };

    bool res = primosLejanos(t, u);
    EXPECT_FALSE(res);
    res = primosLejanos(u, t);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, otroEsPeriodico) {
    toroide t = {{false, false, false, false, false},
                 {false, true,  false, false, false},
                 {false, true,  true,  true,  false},
                 {false, false, false, true,  false},
                 {false, false, false, false, false}};

    toroide u = {{false, false, false, false, false},
                 {false, false, true,  false, false},
                 {false, false, true,  false, false},
                 {false, false, true,  false, false},
                 {false, false, false, false, false}};

    bool res = primosLejanos(t, u);
    EXPECT_FALSE(res);
    res = primosLejanos(u, t);
    EXPECT_FALSE(res);
}


TEST(primosLejanosTEST, noSonPeriodicosYNoSonPrimosLejanos) {
    toroide t = {{false, false, false, false, false},
                 {true, true,  false, false, false},
                 {false, false,  true,  false,  false},
                 {false, false, false, true,  false},
                 {false, true, false, false, false}};

    toroide u = {{false, false, false, false, false},
                 {false, false, false,  false, false},
                 {false, true, false,  true, false},
                 {false, false, false,  false, false},
                 {false, false, false, false, false}};

    bool res = primosLejanos(t, u);
    EXPECT_FALSE(res);
    res = primosLejanos(u, t);
    EXPECT_FALSE(res);
}


TEST(primosLejanosTEST, noSonPeriodicosYSonPrimosLejanos) {
    toroide t = {{false, false, false, false, false},
                 {false, false,  true, false, false},
                 {false, true,  false,  true,  false},
                 {false, false, false, false,  false},
                 {false, false, false, false, false}};

    toroide u = {{false, false, false, false, false},
                 {false, false, true,  false, false},
                 {false, false, true,  false, false},
                 {false, false, false,  false, false},
                 {false, false, false, false, false}};

    bool res = primosLejanos(t, u);
    EXPECT_TRUE(res);
    res = primosLejanos(u, t);
    EXPECT_TRUE(res);
}