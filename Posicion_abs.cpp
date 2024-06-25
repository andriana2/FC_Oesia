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
                if (v.find(f->name) != -1)
                {
                    vector<string> vector_balon;
                    vector_balon = split(v, ' ');            // EJEMPLO ((b) 12 23.3)
                    f->distancia = stod(vector_balon.at(1)); // 12
                    f->direccion = stod(vector_balon.at(2)); // 23.3
                }
            }
            cout << "Algo ha fallado" << endl;
        }
    }
}

void inicializacion_flags(vector<shared_ptr<flagKnowns>> &flags)
{

    flags.push_back(make_shared<flagKnowns>("(f c)", 60, 40, -999.0, -999.0));      // centro campo
    flags.push_back(make_shared<flagKnowns>("(f l t)", 8, 74, -999.0, -999.0));     // corner arriba izq
    flags.push_back(make_shared<flagKnowns>("(f l b)", 8, 6, -999.0, -999.0));      // corner abajo izq
    flags.push_back(make_shared<flagKnowns>("(f r t)", 112, 74, -999.0, -999.0));   // corner arriba der
    flags.push_back(make_shared<flagKnowns>("(f r b)", 112, 6, -999.0, -999.0));    // corner abajo der
    flags.push_back(make_shared<flagKnowns>("(f p l t)", 24, 60, -999.0, -999.0));  // esquina area arriba izq
    flags.push_back(make_shared<flagKnowns>("(f p l c)", 24, 40, -999.0, -999.0));  // esquina area centro izq
    flags.push_back(make_shared<flagKnowns>("(f p l b)", 24, 20, -999.0, -999.0));  // esquina area abajo izq
    flags.push_back(make_shared<flagKnowns>("(f p r t)", 96, 60, -999.0, -999.0));  // esquina area arriba der
    flags.push_back(make_shared<flagKnowns>("(f p r c)", 96, 40, -999.0, -999.0));  // esquina area centro der
    flags.push_back(make_shared<flagKnowns>("(f p r b)", 96, 20, -999.0, -999.0));  // esquina area abajo der
    flags.push_back(make_shared<flagKnowns>("(f g l t)", 8, 47, -999.0, -999.0));   // palo arriba izq
    flags.push_back(make_shared<flagKnowns>("(f g l b)", 8, 33, -999.0, -999.0));   // palo abajo izq
    flags.push_back(make_shared<flagKnowns>("(f g r t)", 52, 7, -999.0, -999.0));   // palo arriba der
    flags.push_back(make_shared<flagKnowns>("(f g r b)", 52, 7, -999.0, -999.0));   // palo abajo der
    flags.push_back(make_shared<flagKnowns>("(f t l 10)", 50, 80, -999.0, -999.0)); // banda fuera arriba hacia izq
    flags.push_back(make_shared<flagKnowns>("(f t l 20)", 40, 80, -999.0, -999.0)); //
    flags.push_back(make_shared<flagKnowns>("(f t l 30)", 30, 80, -999.0, -999.0)); //
    flags.push_back(make_shared<flagKnowns>("(f t l 50)", 10, 80, -999.0, -999.0)); //
    flags.push_back(make_shared<flagKnowns>("(f t 0)", 60, 80, -999.0, -999.0));    // banda fuera centro arriba
    flags.push_back(make_shared<flagKnowns>("(f t r 10)", 70, 80, -999.0, -999.0)); // banda fuera arriba hacia der
    flags.push_back(make_shared<flagKnowns>("(f t r 20)", 80, 80, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f t r 30)", 90, 80, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f t r 40)", 100, 80, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f t r 50)", 110, 80, -999.0, -999.0)); //
    flags.push_back(make_shared<flagKnowns>("(f b l 10)", 50, 0, -999.0, -999.0));   // fuera banda abajo hacia izq
    flags.push_back(make_shared<flagKnowns>("(f b l 20)", 40, 0, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f b l 30)", 30, 0, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f b l 40)", 20, 0, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f b l 50)", 10, 0, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f b 0)", 60, 0, -999.0, -999.0));    // centro banda fuera abajo
    flags.push_back(make_shared<flagKnowns>("(f b r 10)", 70, 0, -999.0, -999.0)); // fuera banda abajo hacia der
    flags.push_back(make_shared<flagKnowns>("(f b r 20)", 80, 0, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f b r 30)", 90, 0, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f b r 40)", 100, 0, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f b r 50)", 110, 0, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f l t 10)", 0, 50, -999.0, -999.0)); // fuera linea fondo izq
    flags.push_back(make_shared<flagKnowns>("(f l t 20)", 0, 60, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f l t 30)", 0, 70, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f l b 10)", 0, 30, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f l b 20)", 0, 20, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f l b 30)", 0, 10, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f r t 10)", 120, 50, -999.0, -999.0)); // fuera linea fondo der
    flags.push_back(make_shared<flagKnowns>("(f r t 20)", 120, 60, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f r t 30)", 120, 70, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f r b 10)", 120, 30, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f r b 20)", 120, 20, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f r b 30)", 120, 10, -999.0, -999.0));
    flags.push_back(make_shared<flagKnowns>("(f c t)", 60, 74, -999.0, -999.0));  // banda centro arriba
    flags.push_back(make_shared<flagKnowns>("(f c b)", 60, 6, -999.0, -999.0));   // banda centro abajo
    flags.push_back(make_shared<flagKnowns>("(f c r)", 120, 40, -999.0, -999.0)); // centro linea de fondo fuera izq ??
    flags.push_back(make_shared<flagKnowns>("(f c l)", 0, 40, -999.0, -999.0));   // centro linea de fondo fuera der ??
}

void relative2Abssolute(double direccion, double d, double xf, double yf)
{

    double beta = -direccion;   // Need positive rotation ccw, direccion is negative ccw
    double cosBeta = cos((M_PI/180)*beta);
    double sinBeta = sin((M_PI/180)*beta);

    if(abs(cosBeta) < 0.01)
    {
        cosBeta = 0;
    }
    else if(abs(sinBeta) < 0.01)
    {
        sinBeta = 0;
    }

    double x = xf -d*cosBeta;
    double y = yf -d*sinBeta;

    if(abs(x) < 0.001)
    {
        x = 0;
    }
    if(abs(y) < 0.001)
    {
        y = 0;
    }

    std::cout << "x: " << x << endl;
    std::cout << "y: " << y << endl;
    std::cout << endl;
}

void absolute2relative(double x, double y, double xf, double yf)
{

    double direccion;
    double d = sqrt(pow((xf - x),2) + pow((yf - y),2));
    double cosBeta = (xf - x)/d;
    double sinBeta = (yf - y)/d;

    if(abs(cosBeta) < 0.01)
    {
        cosBeta = 0;
    }
    else if(abs(sinBeta) < 0.01)
    {
        sinBeta = 0;
    }

    if((cosBeta == 0)||(sinBeta == 0))
    {
        if((cosBeta == 0)&&(sinBeta == 0))
        {
            direccion = 0;
        }
        else if(sinBeta == 0)
        {
            if(xf > x)
            {
                direccion = 0;
            }
            else
            {
                direccion = 180;
            }
        }
        else if(cosBeta == 0)
        {
            if(yf > y)
            {
                direccion = -90;
            }
            else
            {
                direccion = 90;
            }
        }
    }
    else
    {
        double beta = atan2(sinBeta,cosBeta);
        direccion = -((180/M_PI)*beta);
    }

    std::cout << "angle: " << direccion << endl;
    std::cout << "d: " << d << endl;
    std::cout << endl;
}

bool compareDistance(const flagKnowns & f1, const flagKnowns & f2)
{
    return (f1.distancia < f2.distancia);
}

