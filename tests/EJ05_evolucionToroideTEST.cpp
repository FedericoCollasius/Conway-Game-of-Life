#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(evolucionToroideTEST, toroideDiagonalTresPorTresUnPaso){
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true} };
    //1*0 0 1*0
    //0 1 0 0 1
    //0 0 1 0 0
    //1 0 0 1 0
    //0*1 0 0*1
    toroide evo_t = { {true, true, true},
                      {true, true, true},
                      {true, true, true} };
    //  1 1 1
    //  1 1 1
    //  1 1 1
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, toroideMuerto){
    toroide t = { {false, false, false},
                  {false, false, false},
                  {false, false, false} };

    toroide evo_t = { {false, false, false},
                      {false, false, false},
                      {false, false, false} };

    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, toroide1){
    toroide t = { {false, true, false},
                  {true, true, false},
                  {false, true, false} };

    toroide evo_t = { {false, true, false},
                      {true, true, false},
                      {false, true, false} };

    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, toroide2){
    toroide t = { {false, true, false},
                  {false, false, false},
                  {true, false, true} };

    toroide evo_t = { {true, true, true},
                      {true, true, true},
                      {true, true, true} };

    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, todovivo){
    toroide t = { {true, true, true},
                  {true, true, true},
                  {true, true, true} };

    toroide evo_t = { {false, false, false},
                      {false, false, false},
                      {false, false, false} };

    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}
