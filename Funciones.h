#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <vector>
using namespace std;
#include <iostream>
#include <MinimalSocket/udp/UdpSocket.h>
#include <unistd.h>
#include <memory>

struct Datos_Juego{
    string jugador_numero;
    string jugador_lado_campo;
    string balon_distancia;
    string balon_direccion;
    bool veo_balon;
};

vector <string> GestionParentesis(string const &str);
vector <string> split(string const &str, char separador);
void initial_message(const string &str, MinimalSocket::udp::Udp<true> &udp_socket,
                                        MinimalSocket::Address const &recep,Datos_Juego &datos);

void check_see_ball(string const &message, Datos_Juego &datos);
void send_message_funtion(string const &received_message_content, Datos_Juego &datos);
string funcionEnviar(Datos_Juego const & datos);

#endif // GESTION_PARENTESIS_H