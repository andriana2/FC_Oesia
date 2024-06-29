#include "Funciones.h"
#include "Posicion_abs.h"

void initial_message(const string &str, MinimalSocket::udp::Udp<true> &udp_socket,
                     MinimalSocket::Address const &recep, Datos_Juego &datos)
{
    struct Posicion
    {
        int x;
        int y;
    };
    Posicion pos;
    vector<string> player_ = split(str, ' '); // ejemplo de mensaje (init l 2 ...)
    if (player_.at(0) != "(init")
        throw runtime_error("Invalid initial message");
    if (player_.at(1) == "l")
    {
        datos.jugador.lado_campo = "l";
        datos.jugador.jugador_numero = player_[2];
        switch (stoi(player_[2]) - 1)
        {
        case 0:
            pos.x = -51;
            pos.y = 0;
            break;
        case 1:
            pos.x = -30;
            pos.y = -30;
            break;
        case 2:
            pos.x = -35;
            pos.y = -10;
            break;
        case 3:
            pos.x = -35;
            pos.y = 10;
            break;
        case 4:
            pos.x = -30;
            pos.y = 30;
            break;
        case 5:
            pos.x = -25;
            pos.y = -10;
            break;
        case 6:
            pos.x = -25;
            pos.y = 10;
            break;
        case 7:
            pos.x = -11;
            pos.y = 0;
            break;
        case 8:
            pos.x = -5;
            pos.y = 27;
            break;
        case 9:
            pos.x = -5;
            pos.y = -27;
            break;
        case 10:
            pos.x = -5;
            pos.y = 10;
            break;
        }
    }
    auto moveCommand = "(move " + to_string(pos.x) + " " + to_string(pos.y) + ")"; // (move -51 0)
    // cout << moveCommand<< endl;
    udp_socket.sendTo(moveCommand, recep);
}

void check_see_ball(string const &message, Datos_Juego &datos) // comprobamos si veo el balon (b)
{
    if (message.find("(b)") != -1)
    {
        datos.ball.veo_balon = true;
    }
    else
        datos.ball.veo_balon = false;
}

void check_see_porteria_contraria(string const &message, Datos_Juego &datos)
{
    if (message.find("(g r)") != -1 && datos.jugador.lado_campo == "l")
    {
        datos.porteria.veo_porteria_contraria = true;
    }
    else if (message.find("(g l)") != -1 && datos.jugador.lado_campo == "r")
    {
        datos.porteria.veo_porteria_contraria = true;
    }
    else
        datos.porteria.veo_porteria_contraria = false;
}

void check_tengo_balon(Datos_Juego &datos)
{
    try
    {
        if (stod(datos.ball.balon_distancia) < 0.9)
        {
            datos.jugador.tengo_balon = true;
            cout << "tengo el balon " << endl;
        }
        else
        {
            datos.jugador.tengo_balon = false;
        }
    }
    catch (const std::invalid_argument &e)
    {
        // std::cerr << "Error: balon_distancia no es un número válido." << std::endl;
        datos.jugador.tengo_balon = false;
    }
    catch (const std::out_of_range &e)
    {
        // std::cerr << "Error: balon_distancia está fuera del rango permitido." << std::endl;
        datos.jugador.tengo_balon = false;
    }
}

// esta mal check_equipo_balon
void check_jugador_cercano_cerca_balon(Datos_Juego &datos)
{
    try
    {
        float resto = abs(stod(datos.jugador_cercano.distancia) - stod(datos.ball.balon_distancia));
        if (stod(datos.jugador_cercano.distancia) < stod(datos.ball.balon_distancia) && resto < 25)
            datos.jugador_cercano.cerca_balon = true;
        else
            datos.jugador_cercano.cerca_balon = false;
    }
    catch (const std::invalid_argument &e)
    {
        // std::cerr << "Error: balon_distancia no es un número válido." << std::endl;
       datos.jugador_cercano.cerca_balon = false;
    }
    catch (const std::out_of_range &e)
    {
        // std::cerr << "Error: balon_distancia está fuera del rango permitido." << std::endl;
       datos.jugador_cercano.cerca_balon = false;
    }
    if (datos.jugador_cercano.cerca_balon == true)
        cout << "jugador mas cerca del balon que yo" << datos.jugador_cercano.jugador_numero <<endl;
    // if (datos.jugador.tengo_balon)
    // {
    //     datos.jugador.equipo_tiene_balon = true;
    // }
    // else if ((datos.jugador_cercano.distancia == datos.ball.balon_distancia) &&
    //          (datos.jugador_cercano.direccion == datos.ball.balon_direccion))
    //     datos.jugador.equipo_tiene_balon = true;
    // else
    //     datos.jugador.equipo_tiene_balon = false;
}

void send_message_funtion(string const &mensage, Datos_Juego &datos)
{
    if (mensage.find("see") == -1)
        return;
    check_see_ball(mensage, datos);
    check_see_porteria_contraria(mensage, datos);
    check_tengo_balon(datos);
    check_jugador_cercano_cerca_balon(datos);

    vector<string> vector_mensaje = GestionParentesis(mensage);
    vector_mensaje = GestionParentesis(vector_mensaje.at(0));
    vector<string> vector_balon;
    for (auto const &v : vector_mensaje)
    {
        if (v.find("(b)") != -1)
        {
            vector_balon = split(v, ' ');
            datos.ball.balon_distancia = vector_balon.at(1);
            datos.ball.balon_direccion = vector_balon.at(2);
            // cout << datos.balon_distancia << " " << datos.balon_direccion << endl;
        }
        if ((v.find("(f g r b)") != -1) && datos.jugador.lado_campo == "l")
        {
            vector<string> vector_palo_bajo = split(v, ' ');
            datos.porteria.palo_abajo_distancia = vector_palo_bajo.at(4);
            datos.porteria.palo_abajo_direccion = vector_palo_bajo.at(5);
        }
        if ((v.find("(g r)") != -1) && datos.jugador.lado_campo == "l")
        {
            vector<string> vector_porteria = split(v, ' ');
            datos.porteria.centro_distancia = vector_porteria.at(2);
            datos.porteria.centro_direccion = vector_porteria.at(3);
        }
        if ((v.find("(f g r t)") != -1) && datos.jugador.lado_campo == "l")
        {
            vector<string> vector_palo_bajo = split(v, ' ');
            datos.porteria.palo_abajo_distancia = vector_palo_bajo.at(4);
            datos.porteria.palo_abajo_direccion = vector_palo_bajo.at(5);
        }

        // si erres el otro campo
        if ((v.find("(f g l b)") != -1) && datos.jugador.lado_campo == "r")
        {
            vector<string> vector_palo_bajo = split(v, ' ');
            datos.porteria.palo_abajo_distancia = vector_palo_bajo.at(4);
            datos.porteria.palo_abajo_direccion = vector_palo_bajo.at(5);
        }
        if ((v.find("(g l)") != -1) && datos.jugador.lado_campo == "r")
        {
            vector<string> vector_porteria = split(v, ' ');
            datos.porteria.centro_distancia = vector_porteria.at(2);
            datos.porteria.centro_direccion = vector_porteria.at(3);
        }
        if ((v.find("(f g l t)") != -1) && datos.jugador.lado_campo == "r")
        {
            vector<string> vector_palo_bajo = split(v, ' ');
            datos.porteria.palo_abajo_distancia = vector_palo_bajo.at(4);
            datos.porteria.palo_abajo_direccion = vector_palo_bajo.at(5);
        }
        string encontrar_jugador_nuestro_equipo = "(p \"" + datos.nombre_equipo + "\" ";
        if (v.find(encontrar_jugador_nuestro_equipo) != -1)
        {
            vector<string> vector_jugador_cercano = split(v, ' ');
            datos.jugador_cercano.jugador_numero = vector_jugador_cercano.at(2);
            datos.jugador_cercano.distancia = vector_jugador_cercano.at(3);
            datos.jugador_cercano.direccion = vector_jugador_cercano.at(4);
            // cout << v << "        vector anterior"<< endl;
            // cout << vector_jugador_cercano.at(2)<< "        numero"<< endl;
            // cout << vector_jugador_cercano.at(3)<< "        distacia"<< endl;
            // cout << vector_jugador_cercano.at(4)<< "        dirreccion"<< endl;
        }
    }
}

string funcionEnviar(Datos_Juego const &datos)
{
    // Funcion que cogera los datos de la estructura Juego, y creará un mensaje
    // devolviendo la accion del jugador (girar cabeza, correr etc, en funcion del balon)

    string resultado;

    // SI NO VEMOS EL BALON ---> CAMBIO DIRECCION PRIMERO
    if (!datos.ball.veo_balon)
    {
        return resultado = "(turn 60)";
    }
    else // SI VEMOS EL BALON ---> NOS GIRAMOS CCW O CW PARA VERLO MUY BIEN
    {
        if (stod(datos.ball.balon_direccion) > 40) // BALON A LA DERECHA, GIRA DERECHA
        {
            cout << "giro 30 grados" << "\n";

            return resultado = "(turn 30)";
        }
        else if (stod(datos.ball.balon_direccion) < -40) // BALON A LA IZQA, GIRA IZQA
        {
            return resultado = "(turn -30)";
        }
        else // BALON BIEN VISTO, PROCEDEMOS A MOVERNOS
        {
            string movimiento_hacer = movimientos_jugador(datos);
            string mensaje_devolver = "";

            if (datos.jugador.tengo_balon == true)
            {
                if (datos.porteria.veo_porteria_contraria == true && stof(datos.porteria.centro_distancia) < 50)
                {
                    mensaje_devolver = "(kick 100 " + datos.porteria.centro_direccion + ")";
                    return mensaje_devolver;
                }
                else if (datos.porteria.veo_porteria_contraria == true && stof(datos.porteria.centro_distancia) >= 30 && (datos.jugador_cercano.jugador_numero > datos.jugador.jugador_numero))
                {
                    mensaje_devolver = "(kick 30 " + datos.jugador_cercano.direccion + ")";
                    return mensaje_devolver;
                }
                else if (datos.porteria.veo_porteria_contraria == false && datos.jugador_cercano.jugador_numero < datos.jugador.jugador_numero)
                {
                    mensaje_devolver = "(kick 30 " + datos.jugador_cercano.direccion + ")";
                    return mensaje_devolver;
                }
                else{
                    return ("(turn 30)");
                }
            }
            if (datos.jugador_cercano.cerca_balon == true || (stod(movimiento_hacer) == 0 || stod(movimiento_hacer) == -1))
            {
                return "";
            }
            else
            {
                mensaje_devolver = "(dash " + movimiento_hacer + " " + datos.ball.balon_direccion + ")";
                // cout <<mensaje_devolver<< endl;
                return (mensaje_devolver);
            }
        }
    }
    return resultado;
}
