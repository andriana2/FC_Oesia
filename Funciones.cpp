#include "Funciones.h"


void initial_message(const string &str, MinimalSocket::udp::Udp<true> &udp_socket,
                                        MinimalSocket::Address const &recep, Datos_Juego &datos)
{
    struct Posicion{
    int x;
    int y;
    };
    Posicion pos;
    vector <string> player_ = split(str, ' ');//ejemplo de mensaje (init l 2 ...)
    if (player_.at(0) != "(init")
        throw runtime_error("Invalid initial message");
    if (player_.at(1) == "l")
    {
        datos.jugador_lado_campo = "l";
        datos.jugador_numero = player_[2];
        switch(stoi(player_[2]) - 1){
            case 0: pos.x= -51; pos.y = 0; break;
            case 1: pos.x= -30; pos.y = -30; break;
            case 2: pos.x= -35; pos.y = -10; break;
            case 3: pos.x= -35; pos.y = 10; break;
            case 4: pos.x= -30; pos.y = 30; break;
            case 5: pos.x= -25; pos.y = -10; break;
            case 6: pos.x= -25; pos.y = 10; break;
            case 7: pos.x= -11; pos.y = 0; break;
            case 8: pos.x= -5; pos.y = 27; break;
            case 9: pos.x= -5; pos.y = -27; break;
            case 10: pos.x= -5; pos.y = 10; break;
        }
    }
    auto moveCommand = "(move " + to_string(pos.x) + " " + to_string(pos.y) + ")";// (move -51 0)
    cout << moveCommand<< endl;
    udp_socket.sendTo(moveCommand, recep);
}

void check_see_ball(string const &message, Datos_Juego &datos)
{
    if(message.find("(b)") != -1)
    {
        datos.veo_balon = true;
    }
    else
        datos.veo_balon = false;
}
void send_message_funtion(string const &mensage, Datos_Juego &datos)
{
    if (mensage.find("see") == -1)
        return ;
    check_see_ball(mensage, datos);
    vector<string> vector_mensaje = GestionParentesis(mensage);
    vector<string> vector_mensaje_2 = GestionParentesis(vector_mensaje.at(0));
    vector<string> vector_balon;
    for(auto const &v : vector_mensaje_2)
    {
        if (v.find("(b)") != -1)
        {
            vector_balon = split(v, ' ');
            datos.balon_distancia = vector_balon.at(1);
            datos.balon_direccion = vector_balon.at(2);
            cout << datos.balon_distancia << " " << datos.balon_direccion << endl;
        }
    }

}

string funcionEnviar(Datos_Juego const & datos)
{
    // Funcion que cogera los datos de la estructura Juego, y creará un mensaje
    // devolviendo la accion del jugador (girar cabeza, correr etc, en funcion del balon)
    
    string resultado;

        // SI NO VEMOS EL BALON ---> CAMBIO DIRECCION PRIMERO
    if(!datos.veo_balon)
    {
        cout << datos.jugador_numero << "no veo nada"<< "\n";
        return resultado = "(turn 60)";
    }
    else // SI VEMOS EL BALON ---> NOS GIRAMOS CCW O CW PARA VERLO MUY BIEN
    {
        if(stod(datos.balon_direccion) > 40) // BALON A LA DERECHA, GIRA DERECHA
        {
            cout << "giro 30 grados"<< "\n";

            return resultado = "(turn 30)";
        }
        else if(stod(datos.balon_direccion) < -40) // BALON A LA IZQA, GIRA IZQA
        {
            cout <<datos.jugador_numero << " giro -30 grados"<< "\n\n\n\n\n\n";

            return resultado = "(turn -30)";
        }
        else    // BALON BIEN VISTO, PROCEDEMOS A MOVERNOS
        {
            if(stod(datos.balon_distancia) <= 1)        // BALON MUY CERCA
            {
                return resultado = "(kick 100 "+datos.balon_direccion+")";
            }
            if(stod(datos.balon_distancia) <= 20)   // BALON DISTANCIA MEDIA 
            {
                return resultado = "(dash 100 "+datos.balon_direccion+")";
            }
            else                                   // BALON MUY LEJOS
            {
                return resultado = "(dash 70 "+datos.balon_direccion+")";
            }
        }
    }
    return resultado;
}
