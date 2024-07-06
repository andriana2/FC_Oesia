// #include <gtest/gtest.h>
// #include "../../Posicion_abs.h"
// #include <string>
// #include <vector>
// using namespace std;

// string mensaje = "(see 0 ((f c) 11.1 2 0 0) ((f c t) 44.3 -18) ((f r t) 72.2 28) ((g r) 58.6 56) ((f g r t) 59.7 49) ((f p r c) 42.1 52) ((f p r t) 50.9 29) ((f t 0) 49.4 -18) ((f t r 10) 51.4 -7) ((f t r 20) 55.1 3) ((f t r 30) 60.3 11) ((f t r 40) 66.7 18) ((f t r 50) 73.7 24) ((f t l 10) 49.4 -30) ((f t l 20) 51.4 -41) ((f t l 30) 55.1 -51) ((f t l 40) 60.3 -60) ((f r 0) 63.4 57) ((f r t 10) 65.4 48) ((f r t 20) 69.4 40) ((f r t 30) 74.4 33) ((b) 11 2 0 0) ( 49.4 -56) ( 12.2 -55 -0 0 66 66) ( 36.6 -24) ((l t) 48.4 66))";

// TEST(CalculadoraTest, separacion)
// {
//     vector<shared_ptr<flagKnowns>> flags;
//     inicializacion_flags(flags);
//     crear_matriz_valores_absolutos(mensaje, flags);
//     imprimir_matriz(flags);
//     // EXPECT_EQ(flags.at(0)->distancia,11.1);
//     // EXPECT_EQ(flags.at(0)->direccion,2);
//     EXPECT_NEAR(flags.at(0)->distancia, 11.1, 0.001);
//     EXPECT_NEAR(flags.at(0)->direccion,2, 0.01);// para poder hacerlo con float
// }