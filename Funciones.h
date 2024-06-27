#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <vector>
using namespace std;
#include <iostream>
#include <MinimalSocket/udp/UdpSocket.h>
#include <unistd.h>
#include <memory>
#include "utils.h"

//struct Datos_Juego;

struct Jugador
{
    string jugador_numero;
    string lado_campo;
    float x_absoluta;
    float y_absoluta;
};
struct Ball
{
    string balon_distancia;
    string balon_direccion;
    bool veo_balon;
};
struct Porteria
{
    string palo_abajo_distancia;
    string palo_abajo_direccion;
    string palo_arriba_distancia;
    string palo_arriba_direccion;
    string centro_distancia;
    string centro_direccion;
    bool veo_porteria_contraria;
};

struct Datos_Juego
{
    Jugador jugador;
    Ball ball;
    Porteria porteria;
};

vector<string> GestionParentesis(string const &str);
vector<string> split(string const &str, char separador);
void initial_message(const string &str, MinimalSocket::udp::Udp<true> &udp_socket,
                     MinimalSocket::Address const &recep, Datos_Juego &datos);

void check_see_ball(string const &message, Datos_Juego &datos);
void send_message_funtion(string const &received_message_content, Datos_Juego &datos);
string funcionEnviar(Datos_Juego const &datos);

#endif