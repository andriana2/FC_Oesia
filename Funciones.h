#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <vector>
using namespace std;
#include <iostream>
#include <MinimalSocket/udp/UdpSocket.h>
#include <unistd.h>
#include <memory>

vector <string> GestionParentesis(string const &str);
vector <string> split(string const &str, char separador);
void initial_message(const string &str, MinimalSocket::udp::Udp<true> &udp_socket,
                                        MinimalSocket::Address const &recep,Datos_Juego &datos);
//hola
bool check_see_ball(string const &message);

struct Datos_Juego{
    string jugador_numero;
    string jugador_lado_campo;
    
};

#endif // GESTION_PARENTESIS_H