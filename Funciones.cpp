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
            pos.x = -50;
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
            pos.x = -18;
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

Datos_Juego gestion_ball(string const &message, Datos_Juego &datos)
{
    vector<string> vector_mensaje = GestionParentesis(message); // ("see", "((b) 12 12)")
    datos.ball.veo_balon = false;

    for (auto const &v : vector_mensaje)
    {
        if (v.find("(b)") != -1)
        {
            // cout << "vector del ball " << v << endl;
            vector<string> vec = split(v, ' ');
            if (!vec.empty())
            {
                datos.ball.balon_distancia = vec.at(1);
                datos.ball.balon_direccion = vec.at(2);
                datos.ball.veo_balon = true;
            }
        }
    }
    if (datos.ball.veo_balon == false)
    {
        // cout << "soy false "<<endl;
        datos.ball.balon_distancia = "999.0";
        datos.ball.balon_direccion = "999.0";
    }
    return datos;
}

Datos_Juego gestion_porteria(string const &message, Datos_Juego &datos)
{
    datos.porteria.veo_porteria_contraria = false;
    datos.porteria.palo_abajo_distancia = "999.0";
    datos.porteria.palo_abajo_direccion = "999.0";
    datos.porteria.centro_distancia = "999.0";
    datos.porteria.centro_direccion = "999.0";
    datos.porteria.palo_abajo_distancia = "999.0";
    datos.porteria.palo_abajo_direccion = "999.0";

    vector<string> vector_mensaje = GestionParentesis(message); // ("see", "((b) 12 12)")

    for (auto const &v : vector_mensaje)
    {
        if ((v.find("(f g r b)") != -1) && datos.jugador.lado_campo == "l")
        {
            vector<string> vector_palo_bajo = split(v, ' ');
            if (!vector_palo_bajo.empty())
            {
                datos.porteria.palo_abajo_distancia = vector_palo_bajo.at(4);
                datos.porteria.palo_abajo_direccion = vector_palo_bajo.at(5);
            }
        }
        if ((v.find("(g r)") != -1) && datos.jugador.lado_campo == "l")
        {

            datos.porteria.veo_porteria_contraria = true;
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
            if (!vector_palo_bajo.empty())
            {
                datos.porteria.palo_abajo_distancia = vector_palo_bajo.at(4);
                datos.porteria.palo_abajo_direccion = vector_palo_bajo.at(5);
            }
        }
        if ((v.find("(g l)") != -1) && datos.jugador.lado_campo == "r")
        {
            datos.porteria.veo_porteria_contraria = true;
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
    }
    return datos;
}

Datos_Juego gestion_jugadores_vistos(string const &message, Datos_Juego &datos)
{
    datos.jugadores_vistos.veo_equipo = false;
    datos.jugadores_vistos.jugadores.clear();

    vector<string> vector_mensaje = GestionParentesis(message); // ("see", "((b) 12 12)")
    vector<vector<string>> vector_jugadores_cerca;
    string encontrar_jugador_nuestro_equipo = "(p \"" + datos.nombre_equipo + "\" ";
    for (auto const &v : vector_mensaje)
    {
        if (v.find(encontrar_jugador_nuestro_equipo) != -1)
        {
            cout << "jugadores "<< v << endl;
            vector<string> vector_jugador_cercano = split(v, ' ');
            vector_jugador_cercano.at(2).pop_back();
            vector_jugadores_cerca.push_back({vector_jugador_cercano.at(2), vector_jugador_cercano.at(3), vector_jugador_cercano.at(4)});
            //                                jugador_numero                distancia jugador mi equipo     direccion jugador mi equipo
            datos.jugadores_vistos.veo_equipo = true;
        }
    }
    if (datos.jugadores_vistos.veo_equipo == true)
        datos.jugadores_vistos.jugadores = vector_jugadores_cerca;
    return datos;
}

bool check_tengo_balon(Datos_Juego const &datos)
{

    if (stod(datos.ball.balon_distancia) <= 1)
    {
        cout << "tengo el balon " << endl;
        return (true);
    }
    else
    {
        return (false);
    }
}

bool check_jugador_cerca(Datos_Juego &datos)
{
    auto db = stod(datos.ball.balon_distancia);
    auto thetab = -(M_PI / 180) * stod(datos.ball.balon_direccion);
    if (!datos.jugadores_vistos.jugadores.empty())
    {
        for (auto const &v : datos.jugadores_vistos.jugadores)
        {
            auto dp = stod(v.at(1));
            auto thetap = -(M_PI / 180) * stod(v.at(2));
            auto d = sqrt(db * db + dp * dp - 2 * db * dp * cos(thetab - thetap));
            float rel;
            if (db > d)
                float rel = abs((db - d) / db);
            else
                float rel = abs((d - db) / d);

            if ((rel > 0.3) && (db < d))
            {
                return true;
            }
        }
    }
    return false;
}

// si esta esto significa que no puedo tirar a puerta o no la veo
string pase(Datos_Juego &datos)
{
    string distancia{"0"};
    string direccion{"0"};
    int numero_mayor{0};
    if (!datos.jugadores_vistos.veo_equipo)
        return ("(kick 100 180)"); // paso hacia atras si no veo a nadie
    for (auto it : datos.jugadores_vistos.jugadores)
    {
        if (stoi(it.at(0)) > numero_mayor)
        {
            numero_mayor = stoi(it.at(0));
            distancia = it.at(1);
            direccion = it.at(2);
        }
    }
    int potencia = static_cast<int>(stof(distancia) * 2.3);
    if (potencia > 100)
    {
        potencia = 100;
    }
    return ("(kick " + to_string(potencia) + " " + direccion + ")"); // Creamos el mensaje con la potencia calculada y la direccion
}

void send_message_funtion(string const &mensaje, Datos_Juego &datos)
{
    if (mensaje.find("hear") != -1)
    {
        vector<string> vector_mensaje = GestionParentesis(mensaje); // ("init r 1 before_kick_off")
        vector_mensaje = GestionParentesis(vector_mensaje.at(0));   // ("init" "r" "1" "before_kick_off")
        if (vector_mensaje.at(0) != "hear")
        {
            throw runtime_error("error en el mensaje hear");
            return;
        }
        datos.evento_anterior = datos.evento;
        datos.evento = vector_mensaje.at(3);
    }

    if (mensaje.find("see") != -1)
    {
        vector<string> vector_mensaje = GestionParentesis(mensaje); // ("see ((b) 12 12)")
        gestion_ball(vector_mensaje.at(0), datos);
        gestion_porteria(vector_mensaje.at(0), datos);
        gestion_jugadores_vistos(vector_mensaje.at(0), datos);
    }
}

string funcionEnviar(Datos_Juego &datos)
{
    // Funcion que cogera los datos de la estructura Juego, y creará un mensaje
    // devolviendo la accion del jugador (girar cabeza, correr etc, en funcion del balon)

    string resultado{""};
    // cout << "x->" << datos.jugador.x_absoluta << "    y->" << datos.jugador.y_absoluta << endl;
    //  SI NO VEMOS EL BALON ---> CAMBIO DIRECCION PRIMERO
    if (!datos.ball.veo_balon)
    {
        return "(turn 70)";
    }
    else // SI VEMOS EL BALON ---> NOS GIRAMOS CCW O CW PARA VERLO MUY BIEN
    {
        if (stod(datos.ball.balon_direccion) > 30) // BALON A LA DERECHA, GIRA DERECHA
        {
            cout << "giro 30 grados" << "\n";

            return "(turn 20)";
        }
        else if (stod(datos.ball.balon_direccion) < -30) // BALON A LA IZQA, GIRA IZQA
        {
            return "(turn -20)";
        }
        else // BALON BIEN VISTO, PROCEDEMOS A MOVERNOS
        {
            if (check_tengo_balon(datos))
            {
                if (datos.jugador.jugador_numero == "1") // Soy portero
                    return ("(catch " + datos.ball.balon_direccion + ")");
                else if (datos.jugador.jugador_numero < "9") // No soy delantero
                    return (pase(datos));
                else // soy delantero
                {
                    // veo porteria contrari y estoy a menos de 20
                    if (datos.porteria.veo_porteria_contraria == true && stof(datos.porteria.centro_distancia) < 20)
                    {
                        float angulo;
                        if (rand() % 2 == 0)
                            angulo = stof(datos.porteria.palo_arriba_direccion) - (rand() % 20); // tiro con angulo derecha
                        else
                            angulo = stof(datos.porteria.palo_arriba_direccion) + (rand() % 20); // tiro con angulo izquierda
                        string msg = "(kick 100 " + to_string(angulo) + ")";
                        return (msg);
                    }
                    // Veo porteria estoy a mas de 20 metros
                    // OJO PUEDE HABER USA EXCEPCION SI EL KICK_OFF SE MANTIENE Y NO SE ESCUCHA NADA
                    else if (datos.porteria.veo_porteria_contraria == true)
                    {
                        if (datos.flag_kick_off == true)
                        {
                            datos.flag_kick_off = false; // OJO CAMBIO DATO----------
                            return (pase(datos));
                        }
                        else
                            return ("(kick 20 " + datos.porteria.centro_direccion + ")");
                    }
                    // no veo la porteria hago un cambio de sentido
                    else if (datos.porteria.veo_porteria_contraria == false)
                    {
                        return ("(kick 15 150)"); // revisar
                    }
                }
            }
            else // No tengo el balon
            {
                // true jugador mas cerca
                if (check_area(datos))
                {
                    if (!check_jugador_cerca(datos)) // soy de los jugadores mas cerca
                        return ("(dash 100 " + datos.ball.balon_direccion + ")");
                    else if (datos.jugador.jugador_numero == "1" && stof(datos.ball.balon_distancia) < 5 && stof(datos.ball.balon_distancia) > 1)
                    {
                        return ("(dash 100 " + datos.ball.balon_direccion + ")");
                    }
                }
                // no estoy en el area me voy para atras
                else if (datos.jugador.jugador_numero != "1")
                    return ("(dash 100 180)");
            }
        }
    }
    return resultado;
}