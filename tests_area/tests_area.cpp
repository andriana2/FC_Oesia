#include <gtest/gtest.h>
#include <memory>
#include <string>
#include <vector>

using namespace std;

bool check_area(string jugador_numero,float x_absoluta, float y_absoluta)
{
    bool portero = (jugador_numero == "1");
    bool defensa = (jugador_numero == "2" || jugador_numero == "3" || jugador_numero == "4" || jugador_numero == "5");
    bool mc = (jugador_numero == "6" || jugador_numero == "7" || jugador_numero == "8");
    bool delantero = (jugador_numero == "9" || jugador_numero == "10" || jugador_numero == "11");

    if (portero)
    {
        //if ((x_absoluta < 13 && x_absoluta > 8) && (y_absoluta < 47 && y_absoluta > 33))
        if ((x_absoluta < 20 && x_absoluta > 12) && (y_absoluta < 47 && y_absoluta > 33))
        {
            return true;
        }
    }
    else if (defensa)
    {
        if ((x_absoluta < 60 && x_absoluta > 20) && (y_absoluta < 74 && y_absoluta > 6))
        {
            return true;
        }
    }
    else if (mc)
    {
        if ((x_absoluta < 90 && x_absoluta > 30) && (y_absoluta < 74 && y_absoluta > 6))
        {
            return true;
        }
    }
    else if (delantero)
    {
        if ((x_absoluta < 112 && x_absoluta > 40) && (y_absoluta < 74 && y_absoluta > 6))
        {
            return true;
        }
    }
    return false;
}


// Test para verificar las áreas del portero
TEST(CheckAreaTest, Portero) {
    // Casos positivos
    EXPECT_TRUE(check_area("1", 18, 40));
    
    // Casos negativos
    EXPECT_FALSE(check_area("1", 60, 40));
  
}

// Test para verificar las áreas del defensa
TEST(CheckAreaTest, Defensa) {
    // Casos positivos
    EXPECT_TRUE(check_area("2", 30, 40));
    EXPECT_TRUE(check_area("3", 30, 40));
    EXPECT_TRUE(check_area("4", 30, 40));
    EXPECT_TRUE(check_area("5", 30, 40));
    
    // Casos negativos
    EXPECT_FALSE(check_area("2", 70, 40));
    EXPECT_FALSE(check_area("3", 70, 40));
    EXPECT_FALSE(check_area("4", 70, 40));
    EXPECT_FALSE(check_area("5", 70, 40));
}

// Test para verificar las áreas del mediocampista
TEST(CheckAreaTest, Mediocampista) {
    // Casos positivos
    EXPECT_TRUE(check_area("6", 60, 40));
    EXPECT_TRUE(check_area("7", 60, 40));
    EXPECT_TRUE(check_area("8", 60, 40));
    
    // Casos negativos
    EXPECT_FALSE(check_area("6", 90, 40));
    EXPECT_FALSE(check_area("7", 90, 40));
    EXPECT_FALSE(check_area("8", 90, 40));
    EXPECT_FALSE(check_area("6", 90, 40));
}

// Test para verificar las áreas del delantero
TEST(CheckAreaTest, Delantero) {
    // Casos positivos
    EXPECT_TRUE(check_area("9", 90, 40));
    EXPECT_TRUE(check_area("10", 90, 40));
    EXPECT_TRUE(check_area("11", 90, 40));
    
    // Casos negativos
    EXPECT_FALSE(check_area("9", 20, 40));
    EXPECT_FALSE(check_area("10", 20, 40));
    EXPECT_FALSE(check_area("11", 20, 40));
    EXPECT_FALSE(check_area("9", 20, 40));
}

