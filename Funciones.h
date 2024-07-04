#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>
#include <vector>
using namespace std;
#include <iostream>
#include <MinimalSocket/udp/UdpSocket.h>
#include <unistd.h>
#include <memory>
#include <random>
#include "utils.h"
#include "area.h"

// struct Datos_Juego;


struct Jugador
{
    string jugador_numero;
    string lado_campo;
    string nombre_equipo;
    float x_absoluta;
    float y_absoluta;
    bool tengo_balon;
    bool equipo_tiene_balon;

    // Constructor por defecto
    Jugador() 
        : jugador_numero(""), lado_campo(""), nombre_equipo(""), 
          x_absoluta(999.0f), y_absoluta(999.0f), tengo_balon(false), equipo_tiene_balon(false) {}
};

struct Jugadores_Vistos
{
    vector<vector<string>> jugadores;
    bool veo_equipo;

    // Constructor por defecto
    Jugadores_Vistos() 
        : jugadores(), veo_equipo(false) {}
};

struct Ball
{
    string balon_distancia;
    string balon_direccion;
    bool veo_balon;

    // Constructor por defecto
    Ball() 
        : balon_distancia("999.0"), balon_direccion("999.0"), veo_balon(false) {}
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

    // Constructor por defecto
    Porteria() 
        : palo_abajo_distancia("999.0"), palo_abajo_direccion("999.0"), 
          palo_arriba_distancia("999.0"), palo_arriba_direccion("999.0"), 
          centro_distancia("999.0"), centro_direccion("999.0"), veo_porteria_contraria(false) {}
};

struct jugadorCercaPase
{
    bool hayJugadoor;
    string direccion;
    string distancia;
    string numero_jugador;
    jugadorCercaPase()
    : hayJugadoor(false), direccion("999.0"), distancia("999.0"), numero_jugador("") {}
};

struct Datos_Juego
{
    string nombre_equipo;
    Jugador jugador;
    Ball ball;
    Porteria porteria;
    Jugadores_Vistos jugadores_vistos;
    jugadorCercaPase jugadorCerca;
    string evento;
    string evento_anterior;
    bool flag_kick_off;

    // Constructor por defecto
    Datos_Juego() 
        : nombre_equipo(""), jugador(), ball(), porteria(), jugadores_vistos(),jugadorCerca(), 
          evento("999.0"), evento_anterior("999.0"), flag_kick_off(false) {}
};

string posicion_inicial(Datos_Juego &datos);

void initial_message(const string &str, MinimalSocket::udp::Udp<true> &udp_socket,
                     MinimalSocket::Address const &recep, Datos_Juego &datos);


//gestiona el mensaje de ball ((b) 12 13) y guarda las variables direccion y distacia 
//y tiene un flag para saber si tiene el balon o no
Datos_Juego gestion_ball(string const &message, Datos_Juego &datos);

//gestiona el mensaje de porteria y guarda las variables direccion y distacia de ciertas partes de la porteria
//y tiene un flag para saber si veo la porteria contraria o no
Datos_Juego gestion_porteria(string const &message, Datos_Juego &datos);

//gestiona el mensaje de jugadores del mismo equipo y guarda las variables direccion y distacia en un vector de un vector de string
//y tiene un flag para saber si veo jugadores o no
Datos_Juego gestion_jugadores_vistos(string const &message, Datos_Juego &datos);

bool check_tengo_balon(Datos_Juego const &datos);

//es true cuando hay un jugador mas cerca que yo del balon
void check_jugador_cerca_pase(Datos_Juego &datos);

bool voy_balon(Datos_Juego &datos);

//lo que hace cuando esta lejos de la porteria
string pase(Datos_Juego const &datos);

void send_message_funtion(string const &mensaje, Datos_Juego &datos);

string funcionEnviar(Datos_Juego &datos);
string ataque(Datos_Juego &datos);
string sendMessage(Datos_Juego &datos);
#endif