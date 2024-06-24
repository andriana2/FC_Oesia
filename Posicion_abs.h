#ifndef POSICION_ABS_H
#define POSICION_ABS_H

#include "Funciones.h"

struct Absolutos{
    string flag_nombre;
    float distancia;
    float direccion;
};

void crear_matriz_valores_absolutos(string const &received_message_content, vector<shared_ptr<Absolutos>> &vectores_absolutos);

#endif // GESTION_PARENTESIS_H