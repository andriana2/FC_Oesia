#include "area.h"

bool check_area(Datos_Juego const &datos)
{
    // PORTEROS
    bool portero = (datos.jugador.jugador_numero == "1");
    // DEFENSAS
    bool defensa2 = (datos.jugador.jugador_numero == "2");
    bool defensa3 = (datos.jugador.jugador_numero == "3");
    bool defensa4 = (datos.jugador.jugador_numero == "4");
    bool defensa5 = (datos.jugador.jugador_numero == "5");
    // MEDIOCAMPISTAS
    bool mc1 = (datos.jugador.jugador_numero == "6");
    bool mc2 = (datos.jugador.jugador_numero == "7");
    bool mc3 = (datos.jugador.jugador_numero == "8");
    // DELANTEROS
    bool delantero1 = (datos.jugador.jugador_numero == "9");
    bool delantero2 = (datos.jugador.jugador_numero == "10");
    bool delantero3 = (datos.jugador.jugador_numero == "11");

    bool lado_izquierdo = (datos.jugador.lado_campo == "l");
    bool lado_derecho = (datos.jugador.lado_campo == "r");

    // Verificación para el lado derecho
    if (lado_izquierdo)
    {
        if (portero)
        {
            if ((datos.jugador.x_absoluta <= 18 && datos.jugador.x_absoluta >= 8) && (datos.jugador.y_absoluta <= 47 && datos.jugador.y_absoluta >= 33))
            {
                return true;
            }
        }
        else if (defensa2)
        {
            if ((datos.jugador.x_absoluta <= 30 && datos.jugador.x_absoluta >= 8) && (datos.jugador.y_absoluta <= 74 && datos.jugador.y_absoluta >= 50))
            {
                return true;
            }
        }
        else if (defensa3)
        {
            if ((datos.jugador.x_absoluta <= 30 && datos.jugador.x_absoluta >= 8) && (datos.jugador.y_absoluta <= 60 && datos.jugador.y_absoluta >= 40))
            {
                return true;
            }
        }
        else if (defensa4)
        {
            if ((datos.jugador.x_absoluta <= 30 && datos.jugador.x_absoluta >= 8) && (datos.jugador.y_absoluta <= 40 && datos.jugador.y_absoluta >= 22))
            {
                return true;
            }
        }
        else if (defensa5)
        {
            if ((datos.jugador.x_absoluta <= 30 && datos.jugador.x_absoluta >= 8) && (datos.jugador.y_absoluta <= 22 && datos.jugador.y_absoluta >= 8))
            {
                return true;
            }
        }
        else if (mc1)
        {
            if ((datos.jugador.x_absoluta <= 80 && datos.jugador.x_absoluta >= 30) && (datos.jugador.y_absoluta <= 60 && datos.jugador.y_absoluta >= 40))
            {
                return true;
            }
        }
        else if (mc2)
        {
            if ((datos.jugador.x_absoluta <= 80 && datos.jugador.x_absoluta >= 30) && (datos.jugador.y_absoluta <= 40 && datos.jugador.y_absoluta >= 20))
            {
                return true;
            }
        }
        else if (mc3)
        {
            if ((datos.jugador.x_absoluta <= 80 && datos.jugador.x_absoluta >= 30) && (datos.jugador.y_absoluta <= 60 && datos.jugador.y_absoluta >= 20))
            {
                return true;
            }
        }
        else if (delantero1)
        {
            if ((datos.jugador.x_absoluta <= 112 && datos.jugador.x_absoluta >= 45) && (datos.jugador.y_absoluta <= 40 && datos.jugador.y_absoluta >= 8))
            {
                return true;
            }
        }
        else if (delantero2)
        {
            if ((datos.jugador.x_absoluta <= 112 && datos.jugador.x_absoluta >= 45) && (datos.jugador.y_absoluta <= 74 && datos.jugador.y_absoluta >= 40))
            {
                return true;
            }
        }
        else if (delantero3)
        {
            if ((datos.jugador.x_absoluta <= 112 && datos.jugador.x_absoluta >= 45) && (datos.jugador.y_absoluta <= 74 && datos.jugador.y_absoluta >= 6))
            {
                return true;
            }
        }
    }
    // Verificación para el lado derecho
    if (lado_derecho)
    {
        if (portero)
        {
            if ((datos.jugador.x_absoluta >= 94 && datos.jugador.x_absoluta <= 104) && (datos.jugador.y_absoluta <= 47 && datos.jugador.y_absoluta >= 33))
            {
                return true;
            }
        }
        else if (defensa5)
        {
            if ((datos.jugador.x_absoluta >= 90 && datos.jugador.x_absoluta <= 112) && (datos.jugador.y_absoluta <= 74 && datos.jugador.y_absoluta >= 50))
            {
                return true;
            }
        }
        else if (defensa4)
        {
            if ((datos.jugador.x_absoluta >= 90 && datos.jugador.x_absoluta <= 112) && (datos.jugador.y_absoluta <= 60 && datos.jugador.y_absoluta >= 40))
            {
                return true;
            }
        }
        else if (defensa3)
        {
            if ((datos.jugador.x_absoluta >= 90 && datos.jugador.x_absoluta <= 112) && (datos.jugador.y_absoluta <= 40 && datos.jugador.y_absoluta >= 22))
            {
                return true;
            }
        }
        else if (defensa2)
        {
            if ((datos.jugador.x_absoluta >= 90 && datos.jugador.x_absoluta <= 112) && (datos.jugador.y_absoluta <= 22 && datos.jugador.y_absoluta >= 8))
            {
                return true;
            }
        }
        else if (mc2)
        {
            if ((datos.jugador.x_absoluta >= 40 && datos.jugador.x_absoluta <= 90) && (datos.jugador.y_absoluta <= 60 && datos.jugador.y_absoluta >= 40))
            {
                return true;
            }
        }
        else if (mc1)
        {
            if ((datos.jugador.x_absoluta >= 40 && datos.jugador.x_absoluta <= 90) && (datos.jugador.y_absoluta <= 40 && datos.jugador.y_absoluta >= 20))
            {
                return true;
            }
        }
        else if (mc3)
        {
            if ((datos.jugador.x_absoluta >= 40 && datos.jugador.x_absoluta <= 90) && (datos.jugador.y_absoluta <= 60 && datos.jugador.y_absoluta >= 20))
            {
                return true;
            }
        }
        else if (delantero2)
        {
            if ((datos.jugador.x_absoluta >= 8 && datos.jugador.x_absoluta <= 75) && (datos.jugador.y_absoluta <= 40 && datos.jugador.y_absoluta >= 8))
            {
                return true;
            }
        }
        else if (delantero1)
        {
            if ((datos.jugador.x_absoluta >= 8 && datos.jugador.x_absoluta <= 75) && (datos.jugador.y_absoluta <= 74 && datos.jugador.y_absoluta >= 40))
            {
                return true;
            }
        }
        else if (delantero3)
        {
            if ((datos.jugador.x_absoluta >= 8 && datos.jugador.x_absoluta <= 75) && (datos.jugador.y_absoluta <= 74 && datos.jugador.y_absoluta >= 6))
            {
                return true;
            }
        }
    }

    return false;
}

string movimientos_jugador(Datos_Juego const &datos)
{

    if (check_area(datos))
    {
        // PORTEROS
        bool portero = (datos.jugador.jugador_numero == "1");
        // DEFENSAS
        bool defensa2 = (datos.jugador.jugador_numero == "2");
        bool defensa3 = (datos.jugador.jugador_numero == "3");
        bool defensa4 = (datos.jugador.jugador_numero == "4");
        bool defensa5 = (datos.jugador.jugador_numero == "5");
        // MEDIOCAMPISTAS
        bool mc1 = (datos.jugador.jugador_numero == "6");
        bool mc2 = (datos.jugador.jugador_numero == "7");
        bool mc3 = (datos.jugador.jugador_numero == "8");
        // DELANTEROS
        bool delantero1 = (datos.jugador.jugador_numero == "9");
        bool delantero2 = (datos.jugador.jugador_numero == "10");
        bool delantero3 = (datos.jugador.jugador_numero == "11");

        if (check_area(datos))
        {

            if (portero)
            {
                if (datos.ball.balon_distancia >= "40")
                    return "10";
                else if (datos.ball.balon_distancia < "40" && datos.ball.balon_distancia >= "20")
                    return "0";
                else if (datos.ball.balon_distancia < "20" && datos.ball.balon_distancia >= "1")
                    return "80";
                else // datos.ball.balon_distancia < 1
                    return "-1";
            }
            else if (defensa2)
            {
                if (datos.ball.balon_distancia >= "40")
                    return "10";
                else if (datos.ball.balon_distancia < "40" && datos.ball.balon_distancia >= "20")
                    return "0";
                else if (datos.ball.balon_distancia < "20" && datos.ball.balon_distancia >= "1")
                    return "80";
                else // datos.ball.balon_distancia < 1
                    return "-1";
            }
            else if (defensa3)
            {
                if (datos.ball.balon_distancia >= "40")
                    return "10";
                else if (datos.ball.balon_distancia < "40" && datos.ball.balon_distancia >= "20")
                    return "0";
                else if (datos.ball.balon_distancia < "20" && datos.ball.balon_distancia >= "1")
                    return "80";
                else // datos.ball.balon_distancia < 1
                    return "-1";
            }
            else if (defensa4)
            {
                if (datos.ball.balon_distancia >= "40")
                    return "10";
                else if (datos.ball.balon_distancia < "40" && datos.ball.balon_distancia >= "20")
                    return "0";
                else if (datos.ball.balon_distancia < "20" && datos.ball.balon_distancia >= "1")
                    return "80";
                else // datos.ball.balon_distancia < 1
                    return "-1";
            }
            else if (defensa5)
            {
                if (datos.ball.balon_distancia >= "40")
                    return "10";
                else if (datos.ball.balon_distancia < "40" && datos.ball.balon_distancia >= "20")
                    return "0";
                else if (datos.ball.balon_distancia < "20" && datos.ball.balon_distancia >= "1")
                    return "80";
                else // datos.ball.balon_distancia < 1
                    return "-1";
            }
            else if (mc1)
            {
                if (datos.ball.balon_distancia >= "30")
                    return "10";
                else if (datos.ball.balon_distancia < "30" && datos.ball.balon_distancia >= "10")
                    return "0";
                else if (datos.ball.balon_distancia < "10" && datos.ball.balon_distancia >= "1")
                    return "80";
                else // datos.ball.balon_distancia < 1
                    return "-1";
            }
            else if (mc2)
            {
                if (datos.ball.balon_distancia >= "30")
                    return "10";
                else if (datos.ball.balon_distancia < "30" && datos.ball.balon_distancia >= "10")
                    return "0";
                else if (datos.ball.balon_distancia < "10" && datos.ball.balon_distancia >= "1")
                    return "80";
                else // datos.ball.balon_distancia < 1
                    return "-1";
            }
        }
        else if (delantero1)
        {
            if (datos.ball.balon_distancia >= "25")
                return "10";
            else if (datos.ball.balon_distancia < "25" && datos.ball.balon_distancia >= "15")
                return "0";
            else if (datos.ball.balon_distancia < "15" && datos.ball.balon_distancia >= "1")
                return "80";
            else // datos.ball.balon_distancia < 1
                return "-1";
        }
        else if (delantero2)
        {
            if (datos.ball.balon_distancia >= "25")
                return "10";
            else if (datos.ball.balon_distancia < "25" && datos.ball.balon_distancia >= "15")
                return "0";
            else if (datos.ball.balon_distancia < "15" && datos.ball.balon_distancia >= "1")
                return "80";
            else // datos.ball.balon_distancia < 1
                return "-1";
        }
        else if (delantero3)
        {
            if (datos.ball.balon_distancia >= "25")
                return "10";
            else if (datos.ball.balon_distancia < "25" && datos.ball.balon_distancia >= "15")
                return "0";
            else if (datos.ball.balon_distancia < "15" && datos.ball.balon_distancia >= "1")
                return "80";
            else // balon_distancia < 1
                return "-1";
        }
        else
        {
            return "0";
        }
    }
    else
    {
        return "-2";
    }
    // Retorno por defecto para evitar warning de "control reaches end of non-void function"
    return "-3"; // Puedes elegir un valor de retorno que tenga sentido en tu contexto
}
