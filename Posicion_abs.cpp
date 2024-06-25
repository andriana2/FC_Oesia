#include "Posicion_abs.h"

void crear_matriz_valores_absolutos(string const &mensaje, vector<shared_ptr<flagKnowns>> &flags)
{
    if (mensaje.find("see") == -1)
        return;
    vector<string> vector_mensaje = GestionParentesis(mensaje);                // see ((  f l c (2132)) )
    vector<string> vector_mensaje_2 = GestionParentesis(vector_mensaje.at(0)); // {1} see {2} (f c l)(12) (23) .... {23} ((b) 12 23.3)
    for (auto const &f : flags)
    {
        if (mensaje.find(f->name) == -1)
        {
            f->direccion = -999.0;
            f->distancia = -999.0;
        }
        else
        {
            for (auto const &v : vector_mensaje_2)
            {
                
            }
        }
    }
}

void inicializacion_flags(vector<shared_ptr<flagKnowns>> &flags)
{
    flags = {
        make_shared<flagKnowns>("(f c)", 0, 0, -999.0, -999.0),
        make_shared<flagKnowns>("(f l t)", -52, -34, -999.0, -999.0),
        make_shared<flagKnowns>("(f l b)", -52, 34, -999.0, -999.0),
        make_shared<flagKnowns>("(f r t)", 52, -34, -999.0, -999.0),
        make_shared<flagKnowns>("(f r b)", 52, 34, -999.0, -999.0),
        make_shared<flagKnowns>("(f p l t)", -36, -20, -999.0, -999.0),
        make_shared<flagKnowns>("(f p l c)", -36, 0, -999.0, -999.0),
        make_shared<flagKnowns>("(f p l b)", -36, 20, -999.0, -999.0),
        make_shared<flagKnowns>("(f p r t)", 36, -20, -999.0, -999.0),
        make_shared<flagKnowns>("(f p r c)", 36, 0, -999.0, -999.0),
        make_shared<flagKnowns>("(f p r b)", 36, 20, -999.0, -999.0),
        make_shared<flagKnowns>("(f g l t)", -52, -7, -999.0, -999.0),
        make_shared<flagKnowns>("(f g l b)", -52, 7, -999.0, -999.0),
        make_shared<flagKnowns>("(f g r t)", 52, -7, -999.0, -999.0),
        make_shared<flagKnowns>("(f g r b)", 52, 7, -999.0, -999.0),
        make_shared<flagKnowns>("(f t l 10)", -40, -34, -999.0, -999.0),
        make_shared<flagKnowns>("(f t l 20)", -30, -34, -999.0, -999.0),
        make_shared<flagKnowns>("(f t l 30)", -20, -34, -999.0, -999.0),
        make_shared<flagKnowns>("(f t l 40)", -10, -34, -999.0, -999.0),
        make_shared<flagKnowns>("(f t 0)", 0, -34, -999.0, -999.0),
        make_shared<flagKnowns>("(f t r 10)", 10, -34, -999.0, -999.0),
        make_shared<flagKnowns>("(f t r 20)", 20, -34, -999.0, -999.0),
        make_shared<flagKnowns>("(f t r 30)", 30, -34, -999.0, -999.0),
        make_shared<flagKnowns>("(f t r 40)", 40, -34, -999.0, -999.0),
        make_shared<flagKnowns>("(f b l 10)", -40, 34, -999.0, -999.0),
        make_shared<flagKnowns>("(f b l 20)", -30, 34, -999.0, -999.0),
        make_shared<flagKnowns>("(f b l 30)", -20, 34, -999.0, -999.0),
        make_shared<flagKnowns>("(f b l 40)", -10, 34, -999.0, -999.0),
        make_shared<flagKnowns>("(f b 0)", 0, 34, -999.0, -999.0),
        make_shared<flagKnowns>("(f b r 10)", 10, 34, -999.0, -999.0),
        make_shared<flagKnowns>("(f b r 20)", 20, 34, -999.0, -999.0),
        make_shared<flagKnowns>("(f b r 30)", 30, 34, -999.0, -999.0),
        make_shared<flagKnowns>("(f b r 40)", 40, 34, -999.0, -999.0),
        make_shared<flagKnowns>("(f l t 10)", -52, -24, -999.0, -999.0),
        make_shared<flagKnowns>("(f l t 20)", -52, -14, -999.0, -999.0),
        make_shared<flagKnowns>("(f l t 30)", -52, -4, -999.0, -999.0),
        make_shared<flagKnowns>("(f l b 10)", -52, 24, -999.0, -999.0),
        make_shared<flagKnowns>("(f l b 20)", -52, 14, -999.0, -999.0),
        make_shared<flagKnowns>("(f l b 30)", -52, 4, -999.0, -999.0),
        make_shared<flagKnowns>("(f r t 10)", 52, -24, -999.0, -999.0),
        make_shared<flagKnowns>("(f r t 20)", 52, -14, -999.0, -999.0),
        make_shared<flagKnowns>("(f r t 30)", 52, -4, -999.0, -999.0),
        make_shared<flagKnowns>("(f r b 10)", 52, 24, -999.0, -999.0),
        make_shared<flagKnowns>("(f r b 20)", 52, 14, -999.0, -999.0),
        make_shared<flagKnowns>("(f r b 30)", 52, 4, -999.0, -999.0),
        make_shared<flagKnowns>("(f c t)", 0, -20, -999.0, -999.0),
        make_shared<flagKnowns>("(f c b)", 0, 20, -999.0, -999.0),
        make_shared<flagKnowns>("(f c r)", 20, 0, -999.0, -999.0),
        make_shared<flagKnowns>("(f c l)", -20, 0, -999.0, -999.0)};
}
