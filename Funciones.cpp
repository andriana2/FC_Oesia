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
        pos.x = -51;
        pos.y = -4;
        break;
    case 1:
        pos.x = -32;
        pos.y = -10;
        break;
    case 2:
        pos.x = -27;
        pos.y = -2;
        break;
    case 3:
        pos.x = -27;
        pos.y = 2;
        break;
    case 4:
        pos.x = -32;
        pos.y = 10;
        break;
    case 5:
        pos.x = -15;
        pos.y = -7;
        break;
    case 6:
        pos.x = -15;
        pos.y = 7;
        break;
    case 7:
        pos.x = -12;
        pos.y = -2;
        break;
    case 8:
        pos.x = -1;
        pos.y = 15;
        break;
    case 9:
        pos.x = -1;
        pos.y = -15;
        break;
    case 10:
        if ((datos.evento.find("kick_off_l") != -1 && datos.lado_campo == "l") ||
            (datos.evento.find("kick_off_r") != -1 && datos.lado_campo == "r"))
        {
            pos.x = -5;
            pos.y = 10;
        }
        else
        {
            pos.x = -5;
            pos.y = 10;
        }
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
        pos.x = -51;
        pos.y = -4;
        break;
    case 1:
        pos.x = -32;
        pos.y = -10;
        break;
    case 2:
        pos.x = -27;
        pos.y = -2;
        break;
    case 3:
        pos.x = -27;
        pos.y = 2;
        break;
    case 4:
        pos.x = -32;
        pos.y = 10;
        break;
    case 5:
        pos.x = -15;
        pos.y = -7;
        break;
    case 6:
        pos.x = -15;
        pos.y = 7;
        break;
    case 7:
        pos.x = -12;
        pos.y = -2;
        break;
    case 8:
        pos.x = -1;
        pos.y = 15;
        break;
    case 9:
        pos.x = -1;
        pos.y = -15;
        break;
    case 10:
        if ((datos.evento.find("goal_l") != -1 && datos.lado_campo == "r") ||
            (datos.evento.find("goal_r") != -1 && datos.lado_campo == "l"))
        {
            pos.x = -5;
            pos.y = 10;
        }
        else
        {
            pos.x = -5;
            pos.y = 10;
        }
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
    datos.porteria.veo_porteria_propia = false;
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
        else if ((v.find("(f g r b)") != -1) && datos.jugador.lado_campo == "r")
        {
            datos.porteria.veo_porteria_propia = true;
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
        else if ((v.find("(g r)") != -1) && datos.jugador.lado_campo == "r")
        {
            datos.porteria.veo_porteria_propia = true;
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
        else if ((v.find("(f g r t)") != -1) && datos.jugador.lado_campo == "r")
        {
            datos.porteria.veo_porteria_propia = true;
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
        else if ((v.find("(f g l b)") != -1) && datos.jugador.lado_campo == "l")
        {
            datos.porteria.veo_porteria_propia = true;
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
        else if ((v.find("(g l)") != -1) && datos.jugador.lado_campo == "l")
        {
            datos.porteria.veo_porteria_propia = true;
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
        else if ((v.find("(f g l t)") != -1) && datos.jugador.lado_campo == "l")
        {
            datos.porteria.veo_porteria_propia = true;
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
    vector<vector<string>> vector_contrarios_1;
    string encontrar_jugador_nuestro_equipo = "(p \"" + datos.nombre_equipo + "\" ";
    string encontrar_jugador_equipo_constrario = "(p \"";

    for (auto const &v : vector_mensaje)
    {
        if (v.find(encontrar_jugador_nuestro_equipo) != -1)
        {
            vector<string> vector_jugador = split(v, ' ');
            if (vector_jugador.size() >= 5) // Verificar que hay al menos 5 elementos
            {
                vector_jugador.at(2).pop_back();
                vector_jugadores_cerca.push_back({vector_jugador.at(2), vector_jugador.at(3), vector_jugador.at(4)});
                //                                jugador_numero                distancia jugador mi equipo     direccion jugador mi equipo
                datos.jugadores_vistos.veo_equipo = true;
            }
        }
        else if (v.find(encontrar_jugador_equipo_constrario) != -1)
        {
            vector<string> contrarios = split(v, ' ');
            if (contrarios.at(1) != datos.jugador.nombre_equipo && contrarios.size() >= 5)
            {
                contrarios.at(2).pop_back();
                if (contrarios.at(2) < "12" && contrarios.at(2) > "0")
                {
                    vector_contrarios_1.push_back({contrarios.at(2), contrarios.at(3), contrarios.at(4)});
                    //                                jugador_numero     distancia jugador mi equipo     direccion jugador mi equipo

                    datos.jugadores_vistos.veo_equipo_contrario = true;
                }
            }
        }
    }
    if (datos.jugadores_vistos.veo_equipo == true)
    {
        datos.jugadores_vistos.jugadores = vector_jugadores_cerca;
    }
    if (datos.jugadores_vistos.veo_equipo_contrario == true)
    {
        datos.jugadores_vistos.jugadores_contrario = vector_contrarios_1;
    }
    return datos;
}

bool check_tengo_balon(Datos_Juego const &datos)
{

    if (stod(datos.ball.balon_distancia) <= 1 && datos.ball.balon_distancia != "999.0")
    {
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

    int contador{0};
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

            if (db > d)
            {
                contador++;
            }
        }
    }
    if ((datos.jugador.jugador_numero == "3" || datos.jugador.jugador_numero == "4" || datos.jugador.jugador_numero == "2" || datos.jugador.jugador_numero == "5") && stof(datos.ball.balon_distancia) < 10)
    {
        return true;
    }

    if (contador > (int)(jugadores.size() / 2))
        return false;
    // Si no vemos a nadie cerca, tambien voy
    if (jugadores.size() == 0)
    {
        // Si no vemos a jugadores cerca deberiamos de ir a por el balon, por ello debemos devolver true
        // pero los jugadores tienden a ir demasiado al balon, por lo que agregamos una probabilidad de no ir
        bool random_boolean = rand() % 100 < 80;
        return random_boolean;
    }
    return true;
}

bool cerca_enemigo(Datos_Juego &datos)
{
    float distancia{1000};
    for (auto const &jugador : datos.jugadores_vistos.jugadores_contrario)
    {
        if (datos.jugadores_vistos.veo_equipo_contrario)
        {
            if (stof(jugador.at(1)) < distancia)
                distancia = stof(jugador.at(1));
        }
    }
    if (distancia < 10)
        return true;
    else
        return false;
}

void check_jugador_cerca_pase(Datos_Juego &datos)
{
    // Guardar el numero, distancia y direccion del jugador mas cercano a ti y con numero mayor
    // Se guarda en estructura nueva Jugador Cercano
    if (!cerca_enemigo(datos))
    {
        vector<vector<string>> jugadoresCerca = datos.jugadores_vistos.jugadores;
        vector<vector<string>> jugadoresNumeroMayor;

        // Evaluamos todos los jugadores
        for (auto &jugador : jugadoresCerca)
        {
            // aceptamos pases de menor numero si somos delanteros a centrocampistas
            bool somosDelanteros = (datos.jugador.jugador_numero == "11" || datos.jugador.jugador_numero == "10" ||
                                    datos.jugador.jugador_numero == "9");

            if (somosDelanteros && stod(jugador.at(0)) >= 5)
            {
                jugadoresNumeroMayor.push_back(jugador);
            }
            else if (stod(jugador.at(0)) > stod(datos.jugador.jugador_numero) && stod(jugador.at(1)) > 8)
            {
                jugadoresNumeroMayor.push_back(jugador);
            }
        }

        if (jugadoresNumeroMayor.size() != 0)
        {
            // Ordenamos el vector juagdoresNumeroMayor por menor distancia
            sort(jugadoresNumeroMayor.begin(), jugadoresNumeroMayor.end(), [](const vector<string> &a, const vector<string> &b)
                 { return stod(a.at(1)) > stod(b.at(1)); });//cambio <
            if (datos.jugador.jugador_numero == "1" || datos.jugador.jugador_numero == "2" || datos.jugador.jugador_numero == "3" ||
                datos.jugador.jugador_numero == "4" || datos.jugador.jugador_numero == "5")
            {
                sort(jugadoresNumeroMayor.begin(), jugadoresNumeroMayor.end(), [](const vector<string> &a, const vector<string> &b)
                     { return stod(a.at(1)) > stod(b.at(1)); });
            }
            if(datos.jugador.jugador_numero == "6" || datos.jugador.jugador_numero == "7" || datos.jugador.jugador_numero == "8")
            {
                sort(jugadoresNumeroMayor.begin(), jugadoresNumeroMayor.end(), [](const vector<string> &a, const vector<string> &b)
                     { return stod(a.at(0)) > stod(b.at(0)); });
            }
            // Si hay jugadores con numero mayor

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
    else
    {
        vector<vector<string>> jugadoresCerca = datos.jugadores_vistos.jugadores;
        vector<vector<string>> jugadoresNumeroMayor;

        // Evaluamos todos los jugadores
        for (auto &jugador : jugadoresCerca)
        {
            // aceptamos pases de menor numero si somos delanteros a centrocampistas
            bool somosDelanteros = (datos.jugador.jugador_numero == "11" || datos.jugador.jugador_numero == "10" ||
                                    datos.jugador.jugador_numero == "9");

            if (somosDelanteros && stod(jugador.at(0)) >= 5) // jugador distancia en mayor de 11
            {
                jugadoresNumeroMayor.push_back(jugador);
            }
            else if (stod(jugador.at(0)) > stod(datos.jugador.jugador_numero) && stod(jugador.at(1)) > 8)
            {
                jugadoresNumeroMayor.push_back(jugador);
            }
        }

        if (jugadoresNumeroMayor.size() != 0)
        {
            // Ordenamos el vector juagdoresNumeroMayor por mayor distancia
            sort(jugadoresNumeroMayor.begin(), jugadoresNumeroMayor.end(), [](const vector<string> &a, const vector<string> &b)
                 { return stod(a.at(1)) > stod(b.at(1)); });
            if (datos.jugador.jugador_numero == "1" || datos.jugador.jugador_numero == "2" || datos.jugador.jugador_numero == "3" ||
                datos.jugador.jugador_numero == "4" || datos.jugador.jugador_numero == "5")
            {
                sort(jugadoresNumeroMayor.begin(), jugadoresNumeroMayor.end(), [](const vector<string> &a, const vector<string> &b)
                     { return stod(a.at(1)) > stod(b.at(1)); });
            }
            if(datos.jugador.jugador_numero == "6" || datos.jugador.jugador_numero == "7" || datos.jugador.jugador_numero == "8")
            {
                sort(jugadoresNumeroMayor.begin(), jugadoresNumeroMayor.end(), [](const vector<string> &a, const vector<string> &b)
                     { return stod(a.at(0)) > stod(b.at(0)); });
            }
            // Si hay jugadores con numero mayor
            // Guardamos el jugador con mayor numero
            // for (auto &j : jugadoresNumeroMayor)
            //     cout << "-> " << j.at(1) << endl;
            // cout << "fin" << endl;
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
}

string pase(Datos_Juego &datos)
{
    check_jugador_cerca_pase(datos);
    // Si vemos a un jugador cerca con un numero mayor al nuestro
    bool hayJugadorMasCerca = datos.jugadorCerca.hayJugadoor;

    if (hayJugadorMasCerca)
    {
        int potencia;
        // Hay jugador cerca, calculamos potencia necesaria del pase
        if (stof(datos.jugadorCerca.distancia) >= 20)
            potencia = static_cast<int>(stof(datos.jugadorCerca.distancia) * 2.7);
        else if (stof(datos.jugadorCerca.distancia) < 20 && stof(datos.jugadorCerca.distancia) > 10)
            potencia = static_cast<int>(stof(datos.jugadorCerca.distancia) * 2.4);
        else
        {
            potencia = static_cast<int>(stof(datos.jugadorCerca.distancia) * 2.3);
        }

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
        return "(kick 12 130)";
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

string ataque(Datos_Juego &datos)
{
    string resultado;

    // Si somos el jugador que va al balon, y su distancia es < 25
    if ((datos.jugador.jugador_numero == "10" || datos.jugador.jugador_numero == "11" || datos.jugador.jugador_numero == "9") &&
        stod(datos.ball.balon_distancia) <= 30 && stod(datos.ball.balon_distancia) > 1)
    {
        return "(dash 100 " + datos.ball.balon_direccion + ")";
    }

    // Si somos el jugador que va al balon, y su distancia es < 25
    if (voy_balon(datos) && stod(datos.ball.balon_distancia) <= 20 && stod(datos.ball.balon_distancia) > 1)
    {
        return "(dash 100 " + datos.ball.balon_direccion + ")";
    }

    // Si somos el 11, hay corner y la distancia al balon > 1
    bool corner = (datos.evento.find("kick_off_l") == -1 && datos.jugador.jugador_numero == "11" && datos.jugador.lado_campo == "l") ||
                  (datos.evento.find("kick_off_r") == -1 && datos.jugador.jugador_numero == "11" && datos.jugador.lado_campo == "r");

    if (datos.jugador.jugador_numero == "11" && stod(datos.ball.balon_distancia) > 1 && corner)
    {
        return "(dash 100 " + datos.ball.balon_direccion + ")";
    }

    // Somos cualquier jugador y la distancia al balon >25
    if (datos.jugador.jugador_numero != "1" && stod(datos.ball.balon_distancia) > 20 && stod(datos.ball.balon_distancia) < 40)
    {
        return "(dash 35 " + datos.ball.balon_direccion + ")";
    }

    // Somos cualquier jugador y la distancia al balon >25
    if (datos.jugador.jugador_numero != "1" && stod(datos.ball.balon_distancia) >= 40)
    {
        return "(dash 55 " + datos.ball.balon_direccion + ")";
    }

    // Somos portero y nos atacan con el balon, salimos
    if (datos.jugador.jugador_numero == "1" && stod(datos.ball.balon_distancia) > 2 && stod(datos.ball.balon_distancia) <= 4)
    {
        return "(dash 10 " + datos.ball.balon_direccion + ")";
    }
    return "0";
}

string disparo(Datos_Juego &datos)
{
    float angulo;
    if (rand() % 2 == 0)
    {
        angulo = stof(datos.porteria.centro_direccion) + (rand() % 11); // tiro con angulo derecha de 5º
    }
    else
    {
        angulo = stof(datos.porteria.centro_direccion) - (rand() % 11); // tiro con angulo izquierda de 5º
    }
    string msg = "(kick 100 " + to_string(angulo) + ")";
    return (msg);
}

string sendMessage(Datos_Juego &datos)
{
    check_jugador_cerca_pase(datos);

    string resultado;

    ///////////////////////////POSICIONAMIENTO//////////////////////////////////////////////
    // Inicio de posiciones
    bool checkStart = (datos.evento.find("goal_l") != -1 || datos.evento.find("goal_r") != -1 ||
                       datos.evento.find("half_time") != -1 || datos.evento.find("extra_half_time") != -1) ||
                      datos.evento.find("before_kick_off") != -1;

    if (checkStart)
    {
        resultado = posicion_inicial(datos);
        if ((datos.evento.find("goal_l") != -1 && datos.lado_campo == "r") || (datos.evento.find("goal_r") != -1 && datos.lado_campo == "l"))
        {
            datos.flag_kick_off = true;
        }
        else if (datos.evento.find("half_time") != -1 || datos.evento.find("extra_half_time") != -1)
        {
            datos.flag_kick_off = true;
        }
        return resultado;
    }

    /////////////////////////////GIROS PARA VER BALON////////////////////////////////////////////////////////
    // Si no vemos balon giramos mucho
    if (!datos.ball.veo_balon)
    {
        return "(turn 70)";
    }

    // si vemos mal el balon giramos poco
    if (abs(stod(datos.ball.balon_direccion)) > 10) // BALON A LA DERECHA, GIRA DERECHA
    {
        return "(turn " + datos.ball.balon_direccion + ")";
    }

    //////////////SAQUES FALTAS/////////////////////
    // Hay saque de balon nuestro (kisk_off_side_l y somos l)
    if ((datos.evento == "kick_off_l" && datos.jugador.lado_campo == "l") ||
        (datos.evento == "kick_off_r" && datos.jugador.lado_campo == "r"))
    {
        if (check_tengo_balon(datos))
            return "(kick 100 70)";
    }

    ////////////////////////////// CORNER
    bool DelanterosCorner = (datos.jugador.jugador_numero == "11" || datos.jugador.jugador_numero == "10" || datos.jugador.jugador_numero == "9");
    if ((datos.evento.find("indirect_free_kick_l") != -1 && datos.jugador.lado_campo == "l" && DelanterosCorner) ||
        (datos.evento.find("indirect_free_kick_r") != -1 && datos.jugador.lado_campo == "r" && DelanterosCorner) ||
        (datos.evento.find("corner_kick_l") != -1 && datos.jugador.lado_campo == "l" && DelanterosCorner) ||
        (datos.evento.find("corner_kick_r") != -1 && datos.jugador.lado_campo == "r" && DelanterosCorner))
    {
        if (!check_tengo_balon(datos))
            return "(dash 100 " + datos.ball.balon_direccion + ")";
        else if (check_tengo_balon(datos))
            if(datos.porteria.veo_porteria_contraria)
            {
                resultado = disparo(datos);
                return resultado;
            }
            else 
            {
                resultado = pase(datos);
            }
        if (resultado == "(kick 10 130)")
        {
            return "(kick 70 120)";
        }
        return resultado;
    }

    // Si somos el 11 y hay penaltie
    if (datos.jugador.jugador_numero == "11" && ((datos.evento.find("penalty_kick_l") != -1) && datos.lado_campo == "l" ||
                                                 (datos.evento.find("penalty_kick_r") != -1) && datos.lado_campo == "r"))
    {
        if (check_tengo_balon(datos))
        {
            resultado = disparo(datos);
            return resultado;
        }
    }

    // Si somos el portero y hay saque de porteria (d<1)
    bool saquePortero = (datos.evento.find("free_kick_") != -1 && datos.jugador.jugador_numero == "1" && stod(datos.ball.balon_distancia) < 1);
    if (saquePortero)
    {
        resultado = pase(datos);
        if (resultado == "(kick 10 130)")
        {
            resultado = "(kick 100 10)";
            return resultado;
        }
        return resultado;
    }

    ////////////////////CHECK AREA////////////////////////////////////////////

    if (check_area(datos) || voy_balon(datos))
    {
        resultado = ataque(datos);
        if (resultado != "0")
        {
            return resultado;
        }
    }
    else
    {
        if (datos.jugador.jugador_numero == "1")
        {
            return "";
        }
        else
        {
            // Mejor tener juego agresivo a bugs por ir hacia atras
            return "(dash 20 180)";
        }
    }

    ////////////////////////////TACTICA DE PORTERO//////////////////

    // if (datos.jugador.saque_puerta && datos.jugador.jugador_numero == "1" && stod(datos.ball.balon_distancia) < 1)
    if(datos.jugador.jugador_numero == "1" && stod(datos.ball.balon_distancia) <= 2 && stod(datos.ball.balon_distancia) >= 1)
    {
        return "(catch " + datos.ball.balon_direccion + ")";
    }
    
    if (datos.jugador.jugador_numero == "1" && stod(datos.ball.balon_distancia) <= 1)
    {
        // datos.jugador.saque_puerta = false;
        if (datos.jugadorCerca.hayJugadoor && stof(datos.jugadorCerca.distancia) > 10 && !datos.jugadores_vistos.veo_equipo_contrario)
        {
            resultado = pase(datos);
            if (resultado == "(kick 10 130)")
            {
                if (datos.porteria.veo_porteria_propia)
                {
                    return "(kick 100 120)";
                }
                else
                {
                    return "(kick 100 20)";
                }
            }
            return resultado;
        }
        if (datos.porteria.veo_porteria_propia)
        {
            return "(kick 100 120)";
        }
        else
        {
            return "(kick 100 40)";
        }
    }


    /////////////////DISPAROS TENEMOS BALON/////////////////////////////////////////////////
    // Si podemos TIRAR A PORTERIA
    if (stod(datos.ball.balon_distancia) < 1 && stod(datos.porteria.centro_distancia) <= 38)
    {
        resultado = disparo(datos);
        return resultado;
    }

    /////////////////PASES CON POSESION DE BALON/////////////////////////////////////////////////
    // Si TENEMOS BALON, valoramos distintas opciones
    if (stod(datos.ball.balon_distancia) < 1)
    {
        check_jugador_cerca_pase(datos);
        // Si no somos delanteros y vemos a compañero
        bool Delantero = (datos.jugador.jugador_numero == "11" || datos.jugador.jugador_numero == "10");

        // Comportamiento defensas
        bool defensa = (datos.jugador.jugador_numero == "2" || datos.jugador.jugador_numero == "3" || datos.jugador.jugador_numero == "4" || datos.jugador.jugador_numero == "5");
        if (defensa && !datos.porteria.veo_porteria_propia && datos.jugadorCerca.hayJugadoor && stof(datos.jugadorCerca.distancia) < 20)
        {
            if (datos.porteria.veo_porteria_contraria)
            {
                return "(kick 100 " + datos.porteria.centro_direccion + ")";
            }
            else
            {
                return "(kick 100 " + datos.ball.balon_direccion + ")";
            }
        }
        else if (datos.jugadorCerca.hayJugadoor && stof(datos.jugadorCerca.distancia) > 15)
        {
            resultado = pase(datos);
            return resultado;
        }

        if (!Delantero && datos.jugadorCerca.hayJugadoor)
        {
            resultado = pase(datos);
            return resultado;
        }
        // else
        // {
        //     // Si hay corner o falta indirecta, pasamos
        //     bool CornerOrFreeKickIn = ((datos.evento.find("corner_kick_l") != -1 && datos.lado_campo == "l") ||
        //                                (datos.evento.find("corner_kick_r") != -1 && datos.lado_campo == "r"));
        //     if (CornerOrFreeKickIn)
        //     {
        //         resultado = pase(datos);
        //         return resultado;
        //     }

        //     // Si hay falta directa
        //     bool freeKick = (datos.evento.find("free_kick_") != -1 && datos.lado_campo == "l") ||
        //                     (datos.evento.find("free_kick_") != -1 && datos.lado_campo == "r");
        //     if (freeKick && datos.porteria.veo_porteria_contraria)
        //     {
        //         resultado = disparo(datos);
        //         return resultado;
        //     }
        //     else if (freeKick)
        //     {
        //         resultado = pase(datos);
        //         return resultado;
        //     }
        // }
        // Si somos cualquier jugador y vemos porteria corremos a ella
        if (datos.porteria.veo_porteria_contraria && datos.jugador.jugador_numero != "1")
        {
            return "(kick 25 " + datos.porteria.centro_direccion + ")";
        }

        if (datos.jugador.jugador_numero != "1")
        {
            if (datos.evento.find("kick_in_") != -1 || datos.evento.find("corner_kick_") != -1)
            {
                if (datos.jugadorCerca.hayJugadoor)
                {
                    resultado = pase(datos);
                    return resultado;
                }
                else
                {
                    return ("(kick 60 180)");
                }
            } // REGATE
            if (datos.lado_campo == "l")
                return "(kick 10 -70)";
            else
            {
                return "(kick 10 70)";
            }
        }
    }

    if (datos.jugador.jugador_numero == "1")
    {
        return "";
    }

    if (check_tengo_balon(datos))
    {
        return "(kick 20" + datos.porteria.centro_direccion + ")";
    }

    return "(dash 1 " + datos.ball.balon_direccion + ")";
}