#ifndef POSICION_ABS_H
#define POSICION_ABS_H


#include "Funciones.h"
#include "utils.h"

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <cmath>
#include <algorithm>

using namespace std;

// #ifndef FLAGKNOWN_H
// #define FLAGKNOWN_H

// struct flagKnowns {
//     std::string nombre;
//     int numero;
//     int valor1;
//     double valor2;
//     double valor3;

//     flagKnowns(const char* n, int num, int v1, double v2, double v3)
//         : nombre(n), numero(num), valor1(v1), valor2(v2), valor3(v3) {}

//     // Opcionalmente, agregar un constructor por defecto
//     flagKnowns() : numero(0), valor1(0), valor2(0.0), valor3(0.0) {}
// };

// #endif

struct flagKnowns
{
    string name;
    int x;
    int y;
    float distancia;
    float direccion;
};

void inicializacion_flags(vector<shared_ptr<flagKnowns>> &flags);
void crear_matriz_valores_absolutos(string const &mensaje, vector<shared_ptr<flagKnowns>> &flags);
string vector_separar_string(string const &linea);
void reset_flags(vector<shared_ptr<flagKnowns>> &flags);
void imprimir_matriz(vector<shared_ptr<flagKnowns>> &flag);

void relative2Abssolute(vector<shared_ptr<flagKnowns>> &flags, Datos_Juego &datos);
// void absolute2relative(double x, double y, double xf, double yf);
bool compareDistance(const shared_ptr<flagKnowns> &f1, const shared_ptr<flagKnowns> &f2);

#endif