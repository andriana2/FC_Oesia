#include <iostream>
#include <MinimalSocket/udp/UdpSocket.h>

using namespace std;

int main(int argc, char *argv[])
{
    //revisar si el numero de argumentos es correcto
    //argv[0] nombre del programa ejecutado en este caso player(revisar build y cmake)
    //argv[1] nombre del equipo
    //argv[2] numero del puerto
    if (argc != 3)
    {
        cout << "No hay puesto todos los argumentos" << argv[0] << endl;
        return (1);
    }
    //numero del puerto stoi pasa de letra a numero
    MinimalSocket::Port this_socket_port = stoi(argv[2]);
    
    return (0);
}