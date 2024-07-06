#include <gtest/gtest.h>
#include <string>

using namespace std;

bool check_area(string jugador_numero, float x_absoluta, float y_absoluta)
{

    // PORTEROS
    bool portero = (jugador_numero == "1");
    // DEFENSAS
    bool defensa2 = (jugador_numero == "2");
    bool defensa3 = (jugador_numero == "3");
    bool defensa4 = (jugador_numero == "4");
    bool defensa5 = (jugador_numero == "5");
    // MEDIOCAMPISTAS
    bool mc1 = (jugador_numero == "6");
    bool mc2 = (jugador_numero == "7");
    bool mc3 = (jugador_numero == "8");
    // DELANTEROS
    bool delantero1 = (jugador_numero == "9");
    bool delantero2 = (jugador_numero == "10");
    bool delantero3 = (jugador_numero == "11");

    if (portero)
    {
        if ((x_absoluta < 18 && x_absoluta > 8) && (y_absoluta < 47 && y_absoluta > 33))
        {
            return true;
        }
    }
    else if (defensa2)
    {
        if ((x_absoluta < 55 && x_absoluta > 8) && (y_absoluta < 74 && y_absoluta > 50))
        {
            return true;
        }
    }
    else if (defensa3)
    {
        if ((x_absoluta < 55 && x_absoluta > 8) && (y_absoluta < 60 && y_absoluta > 40))
        {
            return true;
        }
    }
    else if (defensa4)
    {
        if ((x_absoluta < 55 && x_absoluta > 8) && (y_absoluta < 40 && y_absoluta > 22))
        {
            return true;
        }
    }
    else if (defensa5)
    {
        if ((x_absoluta < 55 && x_absoluta > 8) && (y_absoluta < 22 && y_absoluta > 8))
        {
            return true;
        }
    }
    else if (mc1)
    {
        if ((x_absoluta < 80 && x_absoluta > 30) && (y_absoluta < 60 && y_absoluta > 40))
        {
            return true;
        }
    }
    else if (mc2)
    {
        if ((x_absoluta < 80 && x_absoluta > 30) && (y_absoluta < 40 && y_absoluta > 20))
        {
            return true;
        }
    }
    else if (mc3)
    {
        if ((x_absoluta < 80 && x_absoluta > 30) && (y_absoluta < 60 && y_absoluta > 20))
        {
            return true;
        }
    }
    else if (delantero1)
    {
        if ((x_absoluta < 112 && x_absoluta > 45) && (y_absoluta < 40 && y_absoluta > 8))
        {
            return true;
        }
    }
    else if (delantero2)
    {
        if ((x_absoluta < 112 && x_absoluta > 45) && (y_absoluta < 74 && y_absoluta > 40))
        {
            return true;
        }
    }
    else if (delantero3)
    {
        if ((x_absoluta < 112 && x_absoluta > 45) && (y_absoluta < 74 && y_absoluta > 6))
        {
            return true;
        }
    }
    return false;
}

int movimientos_jugador(string jugador_numero, float balon_distancia, float x_absoluta, float y_absoluta)
{
    // PORTEROS
    bool portero = (jugador_numero == "1");
    // DEFENSAS
    bool defensa2 = (jugador_numero == "2");
    bool defensa3 = (jugador_numero == "3");
    bool defensa4 = (jugador_numero == "4");
    bool defensa5 = (jugador_numero == "5");
    // MEDIOCAMPISTAS
    bool mc1 = (jugador_numero == "6");
    bool mc2 = (jugador_numero == "7");
    bool mc3 = (jugador_numero == "8");
    // DELANTEROS
    bool delantero1 = (jugador_numero == "9");
    bool delantero2 = (jugador_numero == "10");
    bool delantero3 = (jugador_numero == "11");

    if (check_area(jugador_numero, x_absoluta, y_absoluta))
    {

        if (portero)
        {
            if (balon_distancia >= 40)
                return 10;
            else if (balon_distancia < 40 && balon_distancia >= 20)
                return 0;
            else if (balon_distancia < 20 && balon_distancia >= 1)
                return 80;
            else // balon_distancia < 1
                return -1;
        }
        else if (defensa2)
        {
            if (balon_distancia >= 40)
                return 10;
            else if (balon_distancia < 40 && balon_distancia >= 20)
                return 0;
            else if (balon_distancia < 20 && balon_distancia >= 1)
                return 80;
            else // balon_distancia < 1
                return -1;
        }
        else if (defensa3)
        {
            if (balon_distancia >= 40)
                return 10;
            else if (balon_distancia < 40 && balon_distancia >= 20)
                return 0;
            else if (balon_distancia < 20 && balon_distancia >= 1)
                return 80;
            else // balon_distancia < 1
                return -1;
        }
        else if (defensa4)
        {
            if (balon_distancia >= 40)
                return 10;
            else if (balon_distancia < 40 && balon_distancia >= 20)
                return 0;
            else if (balon_distancia < 20 && balon_distancia >= 1)
                return 80;
            else // balon_distancia < 1
                return -1;
        }
        else if (defensa5)
        {
            if (balon_distancia >= 40)
                return 10;
            else if (balon_distancia < 40 && balon_distancia >= 20)
                return 0;
            else if (balon_distancia < 20 && balon_distancia >= 1)
                return 80;
            else // balon_distancia < 1
                return -1;
        }
        else if (mc1)
        {
            if (balon_distancia >= 30)
                return 10;
            else if (balon_distancia < 30 && balon_distancia >= 10)
                return 0;
            else if (balon_distancia < 10 && balon_distancia >= 1)
                return 80;
            else // balon_distancia < 1
                return -1;
        }
        else if (mc2)
        {
            if (balon_distancia >= 30)
                return 10;
            else if (balon_distancia < 30 && balon_distancia >= 10)
                return 0;
            else if (balon_distancia < 10 && balon_distancia >= 1)
                return 80;
            else // balon_distancia < 1
                return -1;
        }
        else if (mc3)
        {
            if (balon_distancia >= 30)
                return 10;
            else if (balon_distancia < 30 && balon_distancia >= 10)
                return 0;
            else if (balon_distancia < 10 && balon_distancia >= 1)
                return 80;
            else // balon_distancia < 1
                return -1;
        }
        else if (delantero1)
        {
            if (balon_distancia >= 25)
                return 10;
            else if (balon_distancia < 25 && balon_distancia >= 15)
                return 0;
            else if (balon_distancia < 15 && balon_distancia >= 1)
                return 80;
            else // balon_distancia < 1
                return -1;
        }
        else if (delantero2)
        {
            if (balon_distancia >= 25)
                return 10;
            else if (balon_distancia < 25 && balon_distancia >= 15)
                return 0;
            else if (balon_distancia < 15 && balon_distancia >= 1)
                return 80;
            else // balon_distancia < 1
                return -1;
        }
        else if (delantero3)
        {
            if (balon_distancia >= 25)
                return 10;
            else if (balon_distancia < 25 && balon_distancia >= 15)
                return 0;
            else if (balon_distancia < 15 && balon_distancia >= 1)
                return 80;
            else // balon_distancia < 1
                return -1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return -2;
    }
}

TEST(CheckAreaTest, PorteroInsideArea)
{
    EXPECT_TRUE(check_area("1", 15, 40)); // Portero dentro del área
}

TEST(CheckAreaTest, PorteroOutsideArea)
{
    EXPECT_FALSE(check_area("1", 5, 40)); // Portero fuera del área
}

TEST(CheckAreaTest, DefensaInsideArea)
{
    EXPECT_TRUE(check_area("3", 50, 55)); // Defensa dentro del área
}

TEST(CheckAreaTest, DefensaOutsideArea)
{
    EXPECT_FALSE(check_area("3", 70, 40)); // Defensa fuera del área
}

TEST(CheckAreaTest, MediocampistaInsideArea)
{
    EXPECT_TRUE(check_area("7", 65, 35)); // Mediocampista dentro del área
}

TEST(CheckAreaTest, MediocampistaOutsideArea)
{
    EXPECT_FALSE(check_area("7", 20, 50)); // Mediocampista fuera del área
}

TEST(CheckAreaTest, DelanteroInsideArea)
{
    EXPECT_TRUE(check_area("9", 105, 20)); // Delantero dentro del área
}

TEST(CheckAreaTest, DelanteroOutsideArea)
{
    EXPECT_FALSE(check_area("9", 20, 60)); // Delantero fuera del área
}

TEST(MovimientosJugadorTest, Portero)
{
    EXPECT_EQ(movimientos_jugador("1", 45, 15, 40), 10);  // Distancia >= 40
    EXPECT_EQ(movimientos_jugador("1", 30, 15, 40), 0);   // 40 > Distancia >= 20
    EXPECT_EQ(movimientos_jugador("1", 10, 15, 40), 80);  // 20 > Distancia >= 1
    EXPECT_EQ(movimientos_jugador("1", 0.5, 15, 40), -1); // Distancia < 1
}

TEST(MovimientosJugadorTest, Defensa) {
    EXPECT_EQ(movimientos_jugador("3", 45, 50, 55), 10);  // Distancia >= 40
    EXPECT_EQ(movimientos_jugador("3", 30, 50, 55), 0);   // 40 > Distancia >= 20
    EXPECT_EQ(movimientos_jugador("3", 15, 50, 55), 80);  // 20 > Distancia >= 10
    EXPECT_EQ(movimientos_jugador("3", 0.5, 50, 55), -1); // Distancia < 1
}

TEST(MovimientosJugadorTest, Mediocampista) {
    EXPECT_EQ(movimientos_jugador("7", 35, 65, 35), 10);  // Distancia >= 30
    EXPECT_EQ(movimientos_jugador("7", 20, 65, 35), 0);  // 30 > Distancia >= 10
    EXPECT_EQ(movimientos_jugador("7", 5, 65, 35), 80);   // 10 > Distancia >= 1
    EXPECT_EQ(movimientos_jugador("7", 0.5, 65, 35), -1); // Distancia < 1
}

TEST(MovimientosJugadorTest, Delantero) {
    EXPECT_EQ(movimientos_jugador("9", 30, 105, 20), 10);   // Distancia >= 25
    EXPECT_EQ(movimientos_jugador("9", 20, 105, 20), 0);   // 25 > Distancia >= 15
    EXPECT_EQ(movimientos_jugador("9", 10, 105, 20), 80);  // 15 > Distancia >= 1
    EXPECT_EQ(movimientos_jugador("9", 0.5, 105, 20), -1); // Distancia < 1
}
