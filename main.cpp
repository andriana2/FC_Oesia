#include <iostream>
#include <MinimalSocket/udp/UdpSocket.h>
#include <string>
#include <vector>
#include "Gestion_parentesis.h"

using namespace std;

void initial_message(const string &str, MinimalSocket::udp::Udp<true> &udp_socket,
                                        MinimalSocket::Address const &recep)
{
    struct Posicion{
    int x;
    int y;
    };
    Posicion pos;
    vector <string> player = split(str, ' ');//ejemplo de mensaje (init l 2 ...)
    if (player.at(0) != "(init")
        throw runtime_error("Invalid initial message");
    if (player.at(1) == "l")
    {
        switch(stoi(player[2]) - 1){
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

int main(int argc, char *argv[])
{
    //revisar si el numero de argumentos es correcto
    //argv[0] nombre del programa ejecutado en este caso player(revisar build y cmake)
    //argv[1] nombre del equipo
    //argv[2] numero del puerto random a partir de 5000
    if (argc != 3)
    {
        cout << "No hay puesto todos los argumentos" << argv[0] << endl;
        return (1);
    }
    string name_team = argv[1];
    
    //numero del puerto stoi pasa de letra a numero
    MinimalSocket::Port this_socket_port = stoi(argv[2]);
    MinimalSocket::udp::Udp<true> udp_socket(this_socket_port, MinimalSocket::AddressFamily::IP_V6);
    //Abrir el servidor
    cout <<"socket created"<< endl;
    bool success = udp_socket.open();
    if (!success){
        cout << "Error opening socket" << endl;
        return (1);
    }

    MinimalSocket::Address other_recipient_udp = MinimalSocket::Address{"127.0.0.1", 6000};
    cout << "(init " + name_team + "(version 19))" << endl;

    udp_socket.sendTo("(init " + name_team + "(version 19))", other_recipient_udp);
    cout << "Init Message sent" << endl;

    size_t message_max_size = 1000;
    cout << "Waiting for a message" << endl;
    auto received_message = udp_socket.receive(message_max_size);

    string received_message_content = received_message-> received_message;
    cout << received_message_content<< endl << endl;

    MinimalSocket::Address other_sender_udp = received_message->sender;
    MinimalSocket::Address server_udp = MinimalSocket::Address{"127.0.0.1", other_sender_udp.getPort()};
    initial_message(received_message_content, udp_socket, server_udp);
    
    while(true){
        received_message = udp_socket.receive(message_max_size);
        string received_message_content = received_message-> received_message;
    }
}