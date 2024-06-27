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
void imprimir_matriz(vector<shared_ptr<flagKnowns>> &flag);

void relative2Abssolute(vector<shared_ptr<flagKnowns>> &flags, Datos_Juego &datos);
// void absolute2relative(double x, double y, double xf, double yf);
bool compareDistance(const shared_ptr<flagKnowns> &f1, const shared_ptr<flagKnowns> &f2);

#endif // GESTION_PARENTESIS_H