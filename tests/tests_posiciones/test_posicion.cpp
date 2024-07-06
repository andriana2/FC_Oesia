#include <gtest/gtest.h>  
#include <vector>         
#include <string>         
#include <cmath>          
#include <algorithm>      
#include <iostream>       
#include "../../Funciones.h" 

using namespace std;

// Definición de la clase FlagKnowns
class FlagKnowns {
public:
    std::string name;
    double x, y, distancia, direccion;

    FlagKnowns(std::string name, double x, double y, double distancia, double direccion)
        : name(name), x(x), y(y), distancia(distancia), direccion(direccion) {}
};

// Declaración de funciones
void imprimir_matriz(std::vector<FlagKnowns> &flags);
void crear_matriz_valores_absolutos(std::string const &mensaje, std::vector<FlagKnowns> &flags);
void relative2Abssolute(std::vector<FlagKnowns> &flags, Datos_Juego &datos);

// Implementación de funciones
void imprimir_matriz(std::vector<FlagKnowns> &flags) {
    for (auto const &f : flags) {
        std::cout << "Nombre: " << f.name;
        std::cout << " Distancia: " << f.distancia;
        std::cout << " Direccion: " << f.direccion;
        std::cout << " X_absoluta: " << f.x;
        std::cout << " Y_absoluta: " << f.y;
        std::cout << std::endl;
    }
}

void crear_matriz_valores_absolutos(std::string const &mensaje, std::vector<FlagKnowns> &flags) {
    if (mensaje.find("see") == -1)
        return;
    // Suponiendo que las siguientes funciones están definidas:
    // GestionParentesis y split
    std::vector<std::string> vector_mensaje = GestionParentesis(mensaje);                // see ((  f l c (2132)) )
    std::vector<std::string> vector_mensaje_2 = GestionParentesis(vector_mensaje.at(0)); // {1} see {2} (f c l)(12) (23) .... {23} ((b) 12 23.3)
    for (auto &f : flags) {
        if (mensaje.find(f.name) == -1) {
            f.direccion = 999.0;
            f.distancia = 999.0;
        } else {
            for (auto const &v : vector_mensaje_2) {
                if (v.find(f.name) != -1) {
                    std::vector<std::string> vector_balon;
                    std::string nueva_linea = vector_separar_string(v);
                    vector_balon = split(nueva_linea, ' ');

                    // EJEMPLO ((b) 12 23.3)
                    f.distancia = std::stod(vector_balon.at(0)); // 12
                    f.direccion = std::stod(vector_balon.at(1)); // 23.3
                }
            }
        }
    }
    std::sort(flags.begin(), flags.end(), [](const FlagKnowns &f1, const FlagKnowns &f2) {
        return f1.distancia < f2.distancia;
    });
}

void relative2Abssolute(std::vector<FlagKnowns> &flags, Datos_Juego &datos) {
    float theta1 = -flags.at(0).direccion;
    float d1 = flags.at(0).distancia;
    float x1 = flags.at(0).x;
    float y1 = flags.at(0).y;

    float theta2 = -flags.at(1).direccion;
    float d2 = flags.at(1).distancia;
    float x2 = flags.at(1).x;
    float y2 = flags.at(1).y;

    float theta3 = -flags.at(2).direccion;
    float d3 = flags.at(2).distancia;
    float x3 = flags.at(2).x;
    float y3 = flags.at(2).y;

    float errorTheta = std::abs((theta1 - theta2) / theta1);
    if (errorTheta < 0.01) {
        float auxTheta = theta2;
        float auxD = d2;
        float auxX = x2;
        float auxY = y2;

        theta2 = theta3;
        d2 = d3;
        x2 = x3;
        y2 = y3;

        theta3 = auxTheta;
        d3 = auxD;
        x3 = auxX;
        y3 = auxY;
    }

    float cosTheta1 = std::cos((M_PI / 180) * theta1);
    float sinTheta1 = std::sin((M_PI / 180) * theta1);
    float cosTheta2 = std::cos((M_PI / 180) * theta2);
    float sinTheta2 = std::sin((M_PI / 180) * theta2);

    float R;
    R = std::sqrt(d1 * d1 + d2 * d2 - 2 * d1 * d2 * cos((M_PI / 180) * (theta1 - theta2)));

    float psi;
    float b = d2 * sinTheta2 - d1 * sinTheta1;
    float a = d1 * cosTheta1 - d2 * cosTheta2;

    if (std::abs(a) < 0.01) {
        a = 0;
    }
    if (std::abs(b) < 0.01) {
        b = 0;
    }

    psi = std::atan2(b, a);

    float beta;
    float cosBeta = (x1 - x2) / R;

    if (std::abs(cosBeta) <= 1) {
        beta = std::acos(cosBeta);
    } else {
        beta = 0;
    }

    float alpha1 = psi + beta;
    float alpha2 = psi - beta;

    float xp1 = x1 - d1 * (cosTheta1 * std::cos(alpha1) - sinTheta1 * std::sin(alpha1));
    float yp1 = y1 - d1 * (cosTheta1 * std::sin(alpha1) + sinTheta1 * std::cos(alpha1));

    float xp2 = x1 - d1 * (cosTheta1 * std::cos(alpha2) - sinTheta1 * std::sin(alpha2));
    float yp2 = y1 - d1 * (cosTheta1 * std::sin(alpha2) + sinTheta1 * std::cos(alpha2));

    float distPlayer1Flag3 = std::sqrt((xp1 - x3) * (xp1 - x3) + (yp1 - y3) * (yp1 - y3));
    float distPlayer2Flag3 = std::sqrt((xp2 - x3) * (xp2 - x3) + (yp2 - y3) * (yp2 - y3));

    float x_player;
    float y_player;

    float error1 = std::abs((d3 - distPlayer1Flag3) / d3);
    float error2 = std::abs((d3 - distPlayer2Flag3) / d3);

    if (error1 >= 0.5 && error2 >= 0.5) {
        x_player = (xp1 + xp2) / 2;
        y_player = (yp1 + yp2) / 2;
    } else if (error1 < error2) {
        x_player = xp1;
        y_player = yp1;
    } else {
        x_player = xp2;
        y_player = yp2;
    }

    datos.jugador.x_absoluta = x_player;
    datos.jugador.y_absoluta = y_player;
}

TEST(ImprimirMatrizTest, BasicAssertions) {
    vector<FlagKnowns> flags;
    flags.push_back(FlagKnowns("(f c)", 60, 40, 999.0, 999.0));
    testing::internal::CaptureStdout();
    imprimir_matriz(flags);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("Nombre: (f c)"), std::string::npos);
    EXPECT_NE(output.find("Distancia: 999"), std::string::npos);
    EXPECT_NE(output.find("Direccion: 999"), std::string::npos);
    EXPECT_NE(output.find("X_absoluta: 60"), std::string::npos);
    EXPECT_NE(output.find("Y_absoluta: 40"), std::string::npos);
}

TEST(CrearMatrizValoresAbsolutosTest, BasicAssertions) {
    vector<FlagKnowns> flags;
    flags.push_back(FlagKnowns("(f c)", 60, 40, 999.0, 999.0));
    string mensaje = "see ((f c (60 40)))";
    crear_matriz_valores_absolutos(mensaje, flags);
    EXPECT_EQ(flags[0].distancia, 999);
    EXPECT_EQ(flags[0].direccion, 999);
  
}

TEST(Relative2AbssoluteTest, BasicAssertions) {
    vector<FlagKnowns> flags;
    flags.push_back(FlagKnowns("(f c)", 60, 40, 0.0, 0.0));
    flags.push_back(FlagKnowns("(f l t)", 30, 30, 0.0, 0.0));
    flags.push_back(FlagKnowns("(f r b)", 40, 60, 0.0, 0.0));
    
    Datos_Juego datos;
    relative2Abssolute(flags, datos);
    
    EXPECT_NEAR(datos.jugador.x_absoluta, 60, 0.1);
    EXPECT_NEAR(datos.jugador.y_absoluta, 40, 0.1);
}



