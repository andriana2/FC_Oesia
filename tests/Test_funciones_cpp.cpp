#include <gtest/gtest.h>
#include "Funciones.h"
#include "utils.h"
#include <string>
#include <vector>
using namespace std;

// TEST(testFunciones,)
// {
//     string mensaje = "";

// }

#include "area.h"
#include <gtest/gtest.h>

class AreaTest : public ::testing::Test {
protected:
    Datos_Juego datos;

    void SetUp() override {
        // Configuración inicial común a todas las pruebas, si es necesario
    }
};

TEST_F(AreaTest, PorteroEnArea) {
    datos.jugador.jugador_numero = "1";
    datos.jugador.x_absoluta = 15;
    datos.jugador.y_absoluta = 40;
    ASSERT_TRUE(check_area(datos));
}

TEST_F(AreaTest, DefensaEnArea) {
    datos.jugador.jugador_numero = "2";
    datos.jugador.x_absoluta = 30;
    datos.jugador.y_absoluta = 50;
    ASSERT_TRUE(check_area(datos));
}

TEST_F(AreaTest, MediocampoEnArea) {
    datos.jugador.jugador_numero = "6";
    datos.jugador.x_absoluta = 50;
    datos.jugador.y_absoluta = 40;
    ASSERT_TRUE(check_area(datos));
}

// Implementar más pruebas según sea necesario...

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}