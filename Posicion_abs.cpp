#include "Posicion_abs.h"


void crear_matriz_valores_absolutos(string const &mensage, vector<shared_ptr<Absolutos>> &vectores_absolutos)
{
    if (mensage.find("see") == -1)
        return ;
    vector<string> vector_mensaje = GestionParentesis(mensage);//see ((  f l c (2132)) )
    vector<string> vector_mensaje_2 = GestionParentesis(vector_mensaje.at(0));// {1} see {2} (f c l)(12) (23) .... {23} ((b) 12 23.3)
    for(auto const &v : vector_mensaje_2)
    {
        
    }
    
}