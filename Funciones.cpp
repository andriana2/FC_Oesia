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

    datos.jugador.lado_campo = player_.at(1);
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
    auto moveCommand = "(move " + to_string(pos.x) + " " + to_string(pos.y) + ")"; // (move -51 0)
    // cout << moveCommand<< endl;
    udp_socket.sendTo(moveCommand, recep);
}

string posicion_inicial(Datos_Juego &datos)
{
    struct Posicion
    {
        int x;
        int y;
    };
    Posicion pos;

    switch (stoi(datos.jugador.jugador_numero) - 1)
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
    auto resultado = "(move " + to_string(pos.x) + " " + to_string(pos.y) + ")"; // (move -51 0)
    return (resultado);
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
            if (vec.size() >= 3) // Verificar que hay al menos 3 elementos
            {
                // cout<< "balon " << datos.ball.balon_direccion << " "<< datos.ball.balon_distancia<< endl;
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
            if (vector_palo_bajo.size() >= 6) // Verificar que hay al menos 6 elementos
            {
                datos.porteria.palo_abajo_distancia = vector_palo_bajo.at(4);
                datos.porteria.palo_abajo_direccion = vector_palo_bajo.at(5);
            }
        }
        if ((v.find("(g r)") != -1) && datos.jugador.lado_campo == "l")
        {

            datos.porteria.veo_porteria_contraria = true;
            vector<string> vector_porteria = split(v, ' ');
            if (vector_porteria.size() >= 4) // Verificar que hay al menos 4 elementos
            {
                datos.porteria.centro_distancia = vector_porteria.at(2);
                datos.porteria.centro_direccion = vector_porteria.at(3);
            }
        }
        if ((v.find("(f g r t)") != -1) && datos.jugador.lado_campo == "l")
        {
            vector<string> vector_palo_bajo = split(v, ' ');
            if (vector_palo_bajo.size() >= 6) // Verificar que hay al menos 6 elementos
            {
                datos.porteria.palo_abajo_distancia = vector_palo_bajo.at(4);
                datos.porteria.palo_abajo_direccion = vector_palo_bajo.at(5);
            }
        }

        // si erres el otro campo
        if ((v.find("(f g l b)") != -1) && datos.jugador.lado_campo == "r")
        {
            vector<string> vector_palo_bajo = split(v, ' ');
            if (vector_palo_bajo.size() >= 6) // Verificar que hay al menos 6 elementos
            {
                datos.porteria.palo_abajo_distancia = vector_palo_bajo.at(4);
                datos.porteria.palo_abajo_direccion = vector_palo_bajo.at(5);
            }
        }
        if ((v.find("(g l)") != -1) && datos.jugador.lado_campo == "r")
        {
            datos.porteria.veo_porteria_contraria = true;
            vector<string> vector_porteria = split(v, ' ');
            if (vector_porteria.size() >= 4) // Verificar que hay al menos 4 elementos
            {
                datos.porteria.centro_distancia = vector_porteria.at(2);
                datos.porteria.centro_direccion = vector_porteria.at(3);
            }
        }
        if ((v.find("(f g l t)") != -1) && datos.jugador.lado_campo == "r")
        {
            vector<string> vector_palo_bajo = split(v, ' ');
            if (vector_palo_bajo.size() >= 6) // Verificar que hay al menos 6 elementos
            {
                datos.porteria.palo_abajo_distancia = vector_palo_bajo.at(4);
                datos.porteria.palo_abajo_direccion = vector_palo_bajo.at(5);
            }
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
            vector<string> vector_jugador_cercano = split(v, ' ');
            if (vector_jugador_cercano.size() >= 5) // Verificar que hay al menos 5 elementos
            {
                vector_jugador_cercano.at(2).pop_back();
                vector_jugadores_cerca.push_back({vector_jugador_cercano.at(2), vector_jugador_cercano.at(3), vector_jugador_cercano.at(4)});
                //                                jugador_numero                distancia jugador mi equipo     direccion jugador mi equipo
                datos.jugadores_vistos.veo_equipo = true;
            }
        }
    }
    if (datos.jugadores_vistos.veo_equipo == true)
    {
        datos.jugadores_vistos.jugadores = vector_jugadores_cerca;
        // for (const auto &fila : datos.jugadores_vistos.jugadores)
        // {
        //     for (const auto &elemento : fila)
        //     {
        //         std::cout << elemento << " ";
        //     }
        //     std::cout << std::endl; // Nueva línea al final de cada fila
        // }
    }
    return datos;
}

bool check_tengo_balon(Datos_Juego const &datos)
{

    if (stod(datos.ball.balon_distancia) <= 1 && datos.ball.balon_distancia != "999.0")
    {
        cout << "tengo el balon " << endl;
        return (true);
    }
    else
    {
        return (false);
    }
}

bool voy_balon(Datos_Juego &datos)
{
    // Devolver true si tenemos que ir a por el balon, falso si no

    // Variables de jugador a balon
    auto db = stod(datos.ball.balon_distancia);
    auto thetab = -(M_PI / 180) * stod(datos.ball.balon_direccion);

    vector<vector<string>> jugadores = datos.jugadores_vistos.jugadores;

    if (jugadores.size() > 0)
    {
        for (auto const jugador : jugadores)
        {
            // variables 3º jugador a balon
            auto dp = stod(jugador.at(1));
            auto thetap = -(M_PI / 180) * stod(jugador.at(2));

            auto d = sqrt(db * db + dp * dp - 2 * db * dp * cos(thetab - thetap));

            // Si mi distancia al balon es mayor devolvemos false
            // Si mi distancia al balon es menor comparada con 3º jugador devolvemos true
            // Hacemos return si encontramos algun true

            if (db < d)
            {
                return true;
            }
        }
    }
    // Si no vemos a nadie cerca, tambien voy
    if(jugadores.size() == 0)
    {
        // Si no vemos a jugadores cerca deberiamos de ir a por el balon, por ello debemos devolver true
        // pero los jugadores tienden a ir demasiado al balon, por lo que agregamos una probabilidad de no ir
        bool random_boolean = rand() % 100 < 80;
        return random_boolean;
    }
    return false; // No voy
}

void check_jugador_cerca_pase(Datos_Juego &datos)
{
    // Guardar el numero, distancia y direccion del jugador mas cercano a ti y con numero mayor
    // Se guarda en estructura nueva Jugador Cercano
    vector<vector<string>> jugadoresCerca = datos.jugadores_vistos.jugadores;
    vector<vector<string>> jugadoresNumeroMayor;

    // Evaluamos todos los jugadores
    for (auto jugador : jugadoresCerca)
    {
        // aceptamos pases de menor numero si somos delanteros a centrocampistas
        bool somosDelanteros = (datos.jugador.jugador_numero == "11" || datos.jugador.jugador_numero == "10" ||
        datos.jugador.jugador_numero == "9");

        if(somosDelanteros && stod(jugador.at(0)) >= 5)
        {
            jugadoresNumeroMayor.push_back(jugador);
        }
        else if(stod(jugador.at(0)) > stod(datos.jugador.jugador_numero))
        {
            jugadoresNumeroMayor.push_back(jugador);
        }
    }
    
    if(jugadoresNumeroMayor.size() != 0)
    {
        // Ordenamos el vector juagdoresNumeroMayor por mayor numero
        sort(jugadoresNumeroMayor.begin(), jugadoresNumeroMayor.end(), [](const vector<string> &a, const vector<string> &b) {
            return stod(a.at(0)) > stod(b.at(0));
        });

        // Si hay jugadores con numero mayor
        // Guardamos el jugador mas cercano
        datos.jugadorCerca.hayJugadoor = true;
        datos.jugadorCerca.distancia = jugadoresNumeroMayor.at(0).at(1);
        datos.jugadorCerca.direccion = jugadoresNumeroMayor.at(0).at(2);
        datos.jugadorCerca.numero_jugador = jugadoresNumeroMayor.at(0).at(0);
    }
    else
    {
        datos.jugadorCerca.hayJugadoor = false;
    }
}

string pase(Datos_Juego const &datos)
{
check_jugador_cerca_pase(datos);
// Si vemos a un jugador cerca con un numero mayor al nuestro
bool hayJugadorMasCerca = datos.jugadorCerca.hayJugadoor;

if (hayJugadorMasCerca)
{
         // Hay jugador cerca, calculamos potencia necesaria del pase
         int potencia = static_cast<int>(stof(datos.jugadorCerca.distancia) * 2.53);
        cout << "pasando balon" << endl;
         if (potencia > 100)
         {
             return "(kick 100 " + datos.jugadorCerca.direccion + ")";
         }
         else
         {
             return "(kick " + to_string(potencia) + " " + datos.jugadorCerca.direccion + ")";
         }
}
else
{
    // No hay nadie cerca, pase corto hacia atras para girar la cabeza
    return "(kick 10 130)";
}
}

void send_message_funtion(string const &mensaje, Datos_Juego &datos)
{
    if (mensaje.find("hear") != -1)
    {
        vector<string> vector_mensaje_1 = GestionParentesis(mensaje); // ("init r 1 before_kick_off")
        vector_mensaje_1 = split(vector_mensaje_1.at(0), ' ');
        if (vector_mensaje_1.at(0) != "hear")
        {
            throw runtime_error("error en el mensaje hear");
            return;
        }
        datos.evento_anterior = datos.evento;
        datos.evento = vector_mensaje_1.at(3);
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
                {
                    string resultado = pase(datos);
                    return resultado;
                }
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
                        // if (datos.flag_kick_off == true)
                        // {
                        //     datos.flag_kick_off = false; // OJO CAMBIO DATO----------
                        //     return (pase(datos));
                        // }
                        // else
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
                if (datos.jugador.jugador_numero == "1" && stof(datos.ball.balon_distancia) < 5 && stof(datos.ball.balon_distancia) > 1)
                {
                    return ("(dash 100 " + datos.ball.balon_direccion + ")");
                }
                if (check_area(datos) && datos.jugador.jugador_numero != "1")
                {
                    if (voy_balon(datos)) // soy de los jugadores mas cerca
                        return ("(dash 100 " + datos.ball.balon_direccion + ")");
                }
                // no estoy en el area me voy para atras
                else if (datos.jugador.jugador_numero != "1")
                    return ("(dash 100 180)");
                else
                    return ("");
            }
        }
    }
    return resultado;
}

string ataque(Datos_Juego &datos)
{
    string resultado;

    // Si somos el jugador que va al balon, y su distancia es < 25
    if (voy_balon(datos) && stod(datos.ball.balon_distancia) <= 25)
    {
        return "(dash 100 " + datos.ball.balon_direccion + ")";
    }

    // Si somos el 11, hay corner y la distancia al balon > 1
    bool corner = false;
    if (datos.jugador.jugador_numero == "11" && stod(datos.ball.balon_distancia) > 1 && corner)
    {
        return "(dash 100 " + datos.ball.balon_direccion + ")";
    }

    // Somos cualquier jugador y la distancia al balon >25
    if (datos.jugador.jugador_numero != "1" && stod(datos.ball.balon_distancia) > 25)
    {
        return "(dash 50 " + datos.ball.balon_direccion + ")";
    }

    // Somos portero y nos atacan con el balon, salimos
    if (datos.jugador.jugador_numero == "1" && stod(datos.ball.balon_distancia) > 1 && stod(datos.ball.balon_distancia) <= 5)
    {
        return "(dash 100 " + datos.ball.balon_direccion + ")";
    }

    return "(kick 30 180)";
}
/*
string pase(Datos_Juego const &datos)
{
float angulo;
    if (rand() % 2 == 0)
        {
            angulo = stof(datos.porteria.centro_direccion) + (rand() % 16); // tiro con angulo derecha de 5º
        }
    else
        {
            angulo = stof(datos.porteria.centro_direccion) - (rand() % 16); // tiro con angulo izquierda de 5º
        }
    string msg = "(kick 100 " + to_string(angulo) + ")";
    return (msg);    
}


string sendMessage(Datos_Juego &datos)
{
    string resultado;

    ////////////////////////////////////////////////////////////////////////////////////////////////

    // Si hay inicio de posiciones
    cout << datos.evento << "\n";
    cout << endl;
    bool checkStart = (datos.evento.find("goal_l") != -1 || datos.evento.find("goal_r") != -1 ||
                       datos.evento.find("half_time") != -1 || datos.evento.find("extra_half_time") != -1);

    if (checkStart)
    {
        resultado = posicion_inicial(datos);
        if ((datos.evento.find("goal_l") != -1 && datos.lado_campo == "r") || (datos.evento.find("goal_l") != -1 && datos.lado_campo == "l"))
        {
            datos.flag_kick_off = true;
        }
        else if (datos.evento.find("half_time") != -1 || datos.evento.find("extra_half_time") != -1)
        {
            datos.flag_kick_off = true;
        }
        return resultado;
    }

    //////////////////////////////////////////////////////////////////////////////////////////////////

    // Si no vemos balon giramos mucho
    if (!datos.ball.veo_balon)
    {
        return "(turn 70)";
    }

    // si vemos mal el balon giramos poco
    if (stod(datos.ball.balon_direccion) > 30) // BALON A LA DERECHA, GIRA DERECHA
    {
        cout << "giro + grados" << "\n";

        return "(turn " + datos.ball.balon_direccion + ")";
    }

    // Si somos el 11 y hay saque de balon nuestro (kisk_off_side_l y somos l)
    if ((datos.evento == "kick_off_l" && datos.jugador.jugador_numero == "11" && datos.jugador.lado_campo == "l") ||
        (datos.evento == "kick_off_r" && datos.jugador.jugador_numero == "11" && datos.jugador.lado_campo == "r"))
    {
        if (check_tengo_balon(datos))
            return "(kick 50 -90)";
    }

    if (datos.flag_kick_off && datos.jugador.jugador_numero == "11")
    {
        datos.flag_kick_off = false;
        return "(kick 50 -90)";
    }

    
    // // Si estamos aun sin jugar, vemos bien el balon hasta que la direccion == 0
    // if(datos.evento.find("before_kick_off") != -1)
    // {
    //     if(stod(datos.ball.balon_direccion) != 0)
    //     {
    //         return "(turn "+ datos.ball.balon_direccion + ")";
    //     }
    // }

    // Si somos el 11 y hay saque de balon nuestro (kisk_off_side_l y somos l)

    // Si somos el portero y hay saque de porteria (d<1)
    bool saquePortero = (datos.evento.find("free_kick_") != -1 && datos.jugador.jugador_numero == "1" && stod(datos.ball.balon_distancia) < 1);
    if(saquePortero)
    {
        resultado = pase(datos);
        return resultado;
    }


/////////////////////////////////////////////////////////////////////////////////////
    // AÑADIR BOOLEANO PARA SABER SI EL EQUIPO TIENE EL BALON, Y ASI SABER SI PERSEGUIR AL BALON
    // Si estamos en area, aplicamos funcion de ataque al balon, sino volvemos hacia atras
    if (check_area(datos))
    {
        resultado = ataque(datos);
        if(resultado != "0")
        {
            return resultado;
        }
    }
    else
    {
        if(datos.jugador.jugador_numero == "1")
        {
            return "";
        }
        else
        {
            // Mejor tener juego agresivo a bugs por ir hacia atras
            return "(dash 10 180)";
        }
    }

    // Si somos el portero y tenemos el balon, lo atrapamos
    if (datos.jugador.jugador_numero == "1" && stod(datos.ball.balon_distancia) < 1)
    {
        return "(catch " + datos.ball.balon_direccion + ")";
    }

    // Si podemos tirar a puerta
    if (stod(datos.ball.balon_distancia) < 1 && stod(datos.porteria.centro_distancia) <= 25)
    {
        return "(kick 100 " + datos.ball.balon_direccion + ")";
    }

    // Si TENEMOS BALON, valoramos distintas opciones
    if (stod(datos.ball.balon_distancia) < 1)
    {
        // Si no somos delanteros y vemos a compañero
        bool Delantero = (datos.jugador.jugador_numero == "11" || datos.jugador.jugador_numero == "10" || datos.jugador.jugador_numero == "9");

        if (!Delantero && datos.jugadorCerca.hayJugadoor)
        {
            resultado = pase(datos);
            return resultado;
        }
        else
        {
            // Si hay corner o falta indirecta, pasamos
            bool CornerOrFreeKickIn = ((datos.evento.find("corner_kick_l") != -1 && datos.lado_campo == "l") ||
                                      (datos.evento.find("corner_kick_r") != -1 && datos.lado_campo == "r"));
            if (CornerOrFreeKickIn)
            {
                return "(kick 100 180)";
            }

            // Si hay falta directa
            bool freeKick = false;
            if (freeKick && datos.porteria.veo_porteria_contraria)
            {
                resultado = disparo(datos);
                return resultado;            
            }
        }

        // Si somos cualquier jugador y vemos porteria corremos a ella
        if (datos.porteria.veo_porteria_contraria)
        {
            return "(kick 20 " + datos.porteria.centro_direccion + ")";
        }
    }
    return "(dash 5 " + datos.ball.balon_direccion + ")";
}