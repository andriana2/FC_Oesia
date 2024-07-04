#include "Posicion_abs.h"

void inicializacion_flags(vector<shared_ptr<flagKnowns>> &flags)
{
    flags = {
        make_shared<flagKnowns>("(f c)", 60, 40, 999.0, 999.0),      // centro campo
        make_shared<flagKnowns>("(f l t)", 8, 74, 999.0, 999.0),     // corner arriba izq
        make_shared<flagKnowns>("(f l b)", 8, 6, 999.0, 999.0),      // corner abajo izq
        make_shared<flagKnowns>("(f r t)", 112, 74, 999.0, 999.0),   // corner arriba der
        make_shared<flagKnowns>("(f r b)", 112, 6, 999.0, 999.0),    // corner abajo der
        make_shared<flagKnowns>("(f p l t)", 24, 60, 999.0, 999.0),  // esquina area arriba izq
        make_shared<flagKnowns>("(f p l c)", 24, 40, 999.0, 999.0),  // esquina area centro izq
        make_shared<flagKnowns>("(f p l b)", 24, 20, 999.0, 999.0),  // esquina area abajo izq
        make_shared<flagKnowns>("(f p r t)", 96, 60, 999.0, 999.0),  // esquina area arriba der
        make_shared<flagKnowns>("(f p r c)", 96, 40, 999.0, 999.0),  // esquina area centro der
        make_shared<flagKnowns>("(f p r b)", 96, 20, 999.0, 999.0),  // esquina area abajo der
        make_shared<flagKnowns>("(f g l t)", 8, 47, 999.0, 999.0),   // palo arriba izq
        make_shared<flagKnowns>("(f g l b)", 8, 33, 999.0, 999.0),   // palo abajo izq
        make_shared<flagKnowns>("(f g r t)", 112, 47, 999.0, 999.0), // palo arriba der
        make_shared<flagKnowns>("(f g r b)", 112, 33, 999.0, 999.0), // palo abajo der
        make_shared<flagKnowns>("(f t l 10)", 50, 80, 999.0, 999.0), // banda fuera arriba hacia izq
        make_shared<flagKnowns>("(f t l 20)", 40, 80, 999.0, 999.0), //
        make_shared<flagKnowns>("(f t l 30)", 30, 80, 999.0, 999.0), //
        make_shared<flagKnowns>("(f t l 50)", 10, 80, 999.0, 999.0), //
        make_shared<flagKnowns>("(f t 0)", 60, 80, 999.0, 999.0),    // banda fuera centro arriba
        make_shared<flagKnowns>("(f t r 10)", 70, 80, 999.0, 999.0), // banda fuera arriba hacia der
        make_shared<flagKnowns>("(f t r 20)", 80, 80, 999.0, 999.0),
        make_shared<flagKnowns>("(f t r 30)", 90, 80, 999.0, 999.0),
        make_shared<flagKnowns>("(f t r 40)", 100, 80, 999.0, 999.0),
        make_shared<flagKnowns>("(f t r 50)", 110, 80, 999.0, 999.0), //
        make_shared<flagKnowns>("(f b l 10)", 50, 0, 999.0, 999.0),   // fuera banda abajo hacia izq
        make_shared<flagKnowns>("(f b l 20)", 40, 0, 999.0, 999.0),
        make_shared<flagKnowns>("(f b l 30)", 30, 0, 999.0, 999.0),
        make_shared<flagKnowns>("(f b l 40)", 20, 0, 999.0, 999.0),
        make_shared<flagKnowns>("(f b l 50)", 10, 0, 999.0, 999.0),
        make_shared<flagKnowns>("(f b 0)", 60, 0, 999.0, 999.0),    // centro banda fuera abajo
        make_shared<flagKnowns>("(f b r 10)", 70, 0, 999.0, 999.0), // fuera banda abajo hacia der
        make_shared<flagKnowns>("(f b r 20)", 80, 0, 999.0, 999.0),
        make_shared<flagKnowns>("(f b r 30)", 90, 0, 999.0, 999.0),
        make_shared<flagKnowns>("(f b r 40)", 100, 0, 999.0, 999.0),
        make_shared<flagKnowns>("(f b r 50)", 110, 0, 999.0, 999.0),
        make_shared<flagKnowns>("(f l t 10)", 0, 50, 999.0, 999.0), // fuera linea fondo izq
        make_shared<flagKnowns>("(f l t 20)", 0, 60, 999.0, 999.0),
        make_shared<flagKnowns>("(f l t 30)", 0, 70, 999.0, 999.0),
        make_shared<flagKnowns>("(f l b 10)", 0, 30, 999.0, 999.0),
        make_shared<flagKnowns>("(f l b 20)", 0, 20, 999.0, 999.0),
        make_shared<flagKnowns>("(f l b 30)", 0, 10, 999.0, 999.0),
        make_shared<flagKnowns>("(f r t 10)", 120, 50, 999.0, 999.0), // fuera linea fondo der
        make_shared<flagKnowns>("(f r t 20)", 120, 60, 999.0, 999.0),
        make_shared<flagKnowns>("(f r t 30)", 120, 70, 999.0, 999.0),
        make_shared<flagKnowns>("(f r b 10)", 120, 30, 999.0, 999.0),
        make_shared<flagKnowns>("(f r b 20)", 120, 20, 999.0, 999.0),
        make_shared<flagKnowns>("(f r b 30)", 120, 10, 999.0, 999.0),
        make_shared<flagKnowns>("(f c t)", 60, 74, 999.0, 999.0),  // banda centro arriba
        make_shared<flagKnowns>("(f c b)", 60, 6, 999.0, 999.0),   // banda centro abajo
        make_shared<flagKnowns>("(f c r)", 120, 40, 999.0, 999.0), // centro linea de fondo fuera izq ??
        make_shared<flagKnowns>("(f c l)", 0, 40, 999.0, 999.0)};
}

void imprimir_matriz(const vector<shared_ptr<flagKnowns>> &flags)
{
    for (auto const &f : flags)
    {
        cout << "Nombre: " << f->name;
        cout << " Distancia: " << f->distancia;
        cout << " Direccion: " << f->direccion;
        cout << " X_absoluta: " << f->x;
        cout << " Y_absoluta: " << f->y;
        cout << endl;
    }
}

void crear_matriz_valores_absolutos(string const &mensaje, vector<shared_ptr<flagKnowns>> &flags)
{
    if (mensaje.find("see") == -1)
        return;
    vector<string> vector_mensaje = GestionParentesis(mensaje);                // see ((  f l c (2132)) )
    vector<string> vector_mensaje_2 = GestionParentesis(vector_mensaje.at(0)); // {1} see {2} (f c l)(12) (23) .... {23} ((b) 12 23.3)
    if (flags.size() != 0)
    {
        for (auto &f : flags)
        {
            if (mensaje.find(f->name) == -1)
            {
                f->direccion = 999.0;
                f->distancia = 999.0;
            }
            else
            {
                for (auto const &v : vector_mensaje_2)
                {
                    if (v.find(f->name) != -1)
                    {
                        vector<string> vec;
                        string nueva_linea = vector_separar_string(v);
                        vec = split(nueva_linea, ' ');

                        // EJEMPLO ((b) 12 23.3)
                        f->distancia = stod(vec.at(0)); // 12
                        f->direccion = stod(vec.at(1)); // 23.3
                    }
                }
                // inicializacion_flags << "Algo ha fallado" << endl;
            }
        }
        sort(flags.begin(), flags.end(), [](const shared_ptr<flagKnowns> &f1, const shared_ptr<flagKnowns> &f2)
             { return f1->distancia < f2->distancia; });
    }
}
void relative2Abssolute(vector<shared_ptr<flagKnowns>> &flags, Datos_Juego &datos)
{
    // declaration of flags
    float theta1 = -flags.at(0)->direccion;
    float d1 = flags.at(0)->distancia;
    float x1 = flags.at(0)->x;
    float y1 = flags.at(0)->y;

    float theta2 = -flags.at(1)->direccion;
    float d2 = flags.at(1)->distancia;
    float x2 = flags.at(1)->x;
    float y2 = flags.at(1)->y;

    float theta3 = -flags.at(2)->direccion;
    float d3 = flags.at(2)->distancia;
    float x3 = flags.at(2)->x;
    float y3 = flags.at(2)->y;

    // If f1 and f2 are almost collinear, change f2 to f3
    float errorTheta = abs((theta1 - theta2) / theta1);
    if (errorTheta < 0.01)
    {
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

        // cout << "f1 and f2 collinear, changing to f3" << endl;
    }

    float cosTheta1 = cos((M_PI / 180) * theta1);
    float sinTheta1 = sin((M_PI / 180) * theta1);
    float cosTheta2 = cos((M_PI / 180) * theta2);
    float sinTheta2 = sin((M_PI / 180) * theta2);

    // From the triangle, we are gonna solve for R and alpha. We gotta take care of signs and exceptions
    // Does not work for collinear points
    float R;
    R = sqrt(d1 * d1 + d2 * d2 - 2 * d1 * d2 * cos((M_PI / 180) * (theta1 - theta2)));
    // cout << "R: " << R << endl;

    float psi; // phase angle [rad]
    float b = d2 * sinTheta2 - d1 * sinTheta1;
    float a = d1 * cosTheta1 - d2 * cosTheta2;

    if (abs(a) < 0.01)
    {
        a = 0;
    }
    if (abs(b) < 0.01)
    {
        b = 0;
    }
    // cout << "a: " << a << "\t" << "b: " << b << endl;

    psi = atan2(b, a);
    // cout << "psiº: " << (180/M_PI)*psi << endl;
    // cout << endl;

    float beta; // angle [rad]
    float cosBeta = (x1 - x2) / R;
    // cout << "cosBeta: " << cosBeta << endl;

    if (abs(cosBeta) <= 1)
    {
        beta = acos(cosBeta);
    }
    else
    {
        beta = 0; // should throw error
        // cout << "error, cosBeta > 1" << endl;
    }
    // cout << "beta: " << beta << endl;

    // 2 possible solutions given alpha1 and alpha2
    float alpha1 = psi + beta;
    float alpha2 = psi - beta;

    // cout << "alpha1º: " << (180/M_PI)*alpha1 << "\t" << "alpha2º: " << (180/M_PI)*alpha2 << endl;
    // cout << endl;

    float xp1 = x1 - d1 * (cosTheta1 * cos(alpha1) - sinTheta1 * sin(alpha1));
    float yp1 = y1 - d1 * (cosTheta1 * sin(alpha1) + sinTheta1 * cos(alpha1));
    // cout << "x1: " << xp1 << "\t" << "y1: " << yp1 << endl;

    float xp2 = x1 - d1 * (cosTheta1 * cos(alpha2) - sinTheta1 * sin(alpha2));
    float yp2 = y1 - d1 * (cosTheta1 * sin(alpha2) + sinTheta1 * cos(alpha2));
    // cout << "x2: " << xp2 << "\t" << "y2: " << yp2 << endl;

    // Make sure that the solution gives a similar distance to third flag
    float distPlayer1Flag3 = sqrt((xp1 - x3) * (xp1 - x3) + (yp1 - y3) * (yp1 - y3));
    float distPlayer2Flag3 = sqrt((xp2 - x3) * (xp2 - x3) + (yp2 - y3) * (yp2 - y3));

    float x_player;
    float y_player;

    float error1 = abs((d3 - distPlayer1Flag3) / d3);
    float error2 = abs((d3 - distPlayer2Flag3) / d3);

    // check if solutions are accurate, if not give estimation and print error
    if (error1 >= 0.5 && error2 >= 0.5)
    {
        x_player = (xp1 + xp2) / 2;
        y_player = (yp1 + yp2) / 2;
        // cout << "Position not accurate, approximation given" << endl;
    }
    else if (error1 < error2) // use solution 1 if error1 is smaller
    {
        x_player = xp1;
        y_player = yp1;
    }
    else // use solution 2 if error2 is smaller
    {
        x_player = xp2;
        y_player = yp2;
    }

    // cout << "xPlayer: " << x_player << "\t" << "yPlayer: " << y_player << endl;
    datos.jugador.x_absoluta = x_player;
    datos.jugador.y_absoluta = y_player;
}

bool compareDistance(const shared_ptr<flagKnowns> &f1, const shared_ptr<flagKnowns> &f2)
{
    return (f1->distancia < f2->distancia);
}
