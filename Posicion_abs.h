#ifndef POSICION_ABS_H
#define POSICION_ABS_H

#include "Funciones.h"
#include <memory>

using namespace std;

struct flagKnowns {
    string name;
    int x;
    int y;
    float distancia;
    float direccion;
};
void inicializacion_flags(vector <shared_ptr<flagKnowns>> &flags);
void crear_matriz_valores_absolutos(string const &mensaje, vector<shared_ptr<flagKnowns>> &flags);

#endif // GESTION_PARENTESIS_H