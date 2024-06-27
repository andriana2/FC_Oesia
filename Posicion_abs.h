#ifndef POSICION_ABS_H
#define POSICION_ABS_H

#include "Funciones.h"
#include <memory>
#include <string>
#include <vector>
using namespace std;
#include <iostream>
#include <unistd.h>
#include <cmath>
#include <algorithm>

using namespace std;
vector <string> GestionParentesis(string const &str);//Borrar
vector <string> split(string const &str, char separador);//Borrar

struct flagKnowns {
    string name;
    int x;
    int y;
    float distancia;
    float direccion;
};
void inicializacion_flags(vector <shared_ptr<flagKnowns>> &flags);
void crear_matriz_valores_absolutos(string const &mensaje, vector<shared_ptr<flagKnowns>> &flags);
string vector_separar_string(string const &linea);
void imprimir_matriz(vector <shared_ptr<flagKnowns>> &flag);


void relative2Abssolute(vector<shared_ptr<flagKnowns>> &flags);
void absolute2relative(double x, double y, double xf, double yf);
bool compareDistance(const shared_ptr<flagKnowns> &f1, const shared_ptr<flagKnowns> &f2);



#endif // GESTION_PARENTESIS_H