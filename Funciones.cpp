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

bool check_see_ball(string const &message)
{
    if(message.find("b") != -1)
        return (true);
    return(false);
}
