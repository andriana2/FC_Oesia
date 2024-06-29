#include "Funciones.h"
#include "Posicion_abs.h"
#include "utils.h"


int main(int argc, char *argv[])
{
    Datos_Juego datos;

    //PUEDE QUE QUITAR
    vector<shared_ptr<flagKnowns>> flags;
    inicializacion_flags(flags);
    //FIN PUEDE QUE QUITAR

    
    //revisar si el numero de argumentos es correcto
    //argv[0] nombre del programa ejecutado en este caso player(revisar build y cmake)
    //argv[1] nombre del equipo
    //argv[2] numero del puerto random a partir de 5000
    if (argc != 3)
    {
        cout << "No hay puesto todos los argumentos" << argv[0] << endl;
        return (1);
    }
    datos.nombre_equipo = argv[1];
    
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
    cout << "(init " + datos.nombre_equipo + "(version 19))" << endl;

    udp_socket.sendTo("(init " + datos.nombre_equipo + "(version 19))", other_recipient_udp);
    cout << "Init Message sent" << endl;

    size_t message_max_size = 1000;
    cout << "Waiting for a message" << endl;
    auto received_message = udp_socket.receive(message_max_size);

    string received_message_content = received_message-> received_message;
    cout << received_message_content<< endl << endl;

    MinimalSocket::Address other_sender_udp = received_message->sender;
    MinimalSocket::Address server_udp = MinimalSocket::Address{"127.0.0.1", other_sender_udp.getPort()};
    initial_message(received_message_content, udp_socket, server_udp, datos);
    
    while(true){
        string received_message_content = received_message-> received_message;
        do{
            received_message = udp_socket.receive(message_max_size);
            received_message_content = received_message->received_message;
            try
            {
                send_message_funtion(received_message_content, datos);
                crear_matriz_valores_absolutos(received_message_content, flags);//ABSOLUTOS
                relative2Abssolute(flags, datos);//ABSOLUTOS
            }
            catch (const std::exception &e)
            {
                cout << e.what() << endl;
            }
        } while (received_message_content.find("(see") == -1);
        //cout << received_message_content << endl <<endl <<endl;
        string envio = funcionEnviar(datos);
        if (envio != ""){
            cout << datos.jugador.jugador_numero << "<- numero jugador "<< envio <<endl;
            udp_socket.sendTo(envio,server_udp);
        }
    }
}