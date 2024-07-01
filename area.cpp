#include "area.h"

bool check_area(Datos_Juego const &datos)
{
    bool portero = (datos.jugador.jugador_numero == "1");
    bool defensa = (datos.jugador.jugador_numero == "2" || datos.jugador.jugador_numero == "3" || datos.jugador.jugador_numero == "4" || datos.jugador.jugador_numero == "5");
    bool mc = (datos.jugador.jugador_numero == "6" || datos.jugador.jugador_numero == "7" || datos.jugador.jugador_numero == "8");
    bool delantero = (datos.jugador.jugador_numero == "9" || datos.jugador.jugador_numero == "10" || datos.jugador.jugador_numero == "11");

    if (portero)
    {
        //if ((datos.jugador.x_absoluta < 13 && datos.jugador.x_absoluta > 8) && (datos.jugador.y_absoluta < 47 && datos.jugador.y_absoluta > 33))
        if ((datos.jugador.x_absoluta < 20 && datos.jugador.x_absoluta > 12) && (datos.jugador.y_absoluta < 47 && datos.jugador.y_absoluta > 33))
        {
            return true;
        }
    }
    else if (defensa)
    {
        if ((datos.jugador.x_absoluta < 60 && datos.jugador.x_absoluta > 20) && (datos.jugador.y_absoluta < 74 && datos.jugador.y_absoluta > 6))
        {
            return true;
        }
    }
    else if (mc)
    {
        if ((datos.jugador.x_absoluta < 90 && datos.jugador.x_absoluta > 30) && (datos.jugador.y_absoluta < 74 && datos.jugador.y_absoluta > 6))
        {
            return true;
        }
    }
    else if (delantero)
    {
        if ((datos.jugador.x_absoluta < 112 && datos.jugador.x_absoluta > 40) && (datos.jugador.y_absoluta < 74 && datos.jugador.y_absoluta > 6))
        {
            return true;
        }
    }
    return false;
}

string movimientos_jugador(Datos_Juego const &datos)
{
    bool defensa = (datos.jugador.jugador_numero == "3" || datos.jugador.jugador_numero == "4");
    bool defensa_lateral = (datos.jugador.jugador_numero == "2" || datos.jugador.jugador_numero == "5");
    bool mc = (datos.jugador.jugador_numero == "6" || datos.jugador.jugador_numero == "7" || datos.jugador.jugador_numero == "8");
    bool delantero = (datos.jugador.jugador_numero == "9" || datos.jugador.jugador_numero == "10" || datos.jugador.jugador_numero == "11");
    bool portero = (datos.jugador.jugador_numero == "1");

    if (check_area(datos))
    {
        // cout <<"distancia balon "<< datos.ball.balon_distancia<<endl;
        if (defensa)
        {
            if (stof(datos.ball.balon_distancia) >= 40)
                return "10";
            else if (stof(datos.ball.balon_distancia) < 40)
                return "0";
            else if (stof(datos.ball.balon_distancia) < 20)
                return "80";
            else if (stof(datos.ball.balon_distancia) < 1)
                return "-1";
            else
                return "0";
        }
        else if (defensa_lateral)
        {
            if (stof(datos.ball.balon_distancia) >= 40)
                return "10";
            else if (stof(datos.ball.balon_distancia) < 40)
                return "5";
            else if (stof(datos.ball.balon_distancia) < 20)
                return "80";
            else if (stof(datos.ball.balon_distancia) < 1)
                return "-1";
            else
                return "0";
        }

        else if (mc)
        {
            if (stof(datos.ball.balon_distancia) >= 30)
                return "25";
            else if (stof(datos.ball.balon_distancia) < 30)
                return "10";
            else if (stof(datos.ball.balon_distancia) < 10)
                return "90";
            else if (stof(datos.ball.balon_distancia) < 1)
                return "-1";
            else
                return "0";
        }

        else if (delantero)
        {
            if (stof(datos.ball.balon_distancia) >= 25)
                return "30";
            else if (stof(datos.ball.balon_distancia) < 25)
                return "50";
            else if (stof(datos.ball.balon_distancia) < 15)
                return "100";
            else if (stof(datos.ball.balon_distancia) < 1)
                return "-1";
            else
                return "0";
        }
        else
            return "0";
    }
    else
    {
        cout << "fuera de area" << endl;
        return "-2";
    }
}