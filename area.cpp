
#include "area.h"

bool area_portero(Datos_Juego &datos)
{   //defino numero portero
    bool portero = (datos.jugador.jugador_numero == "1");
    if (portero)
    {
        if ((datos.jugador.x_absoluta < 13 && datos.jugador.y_absoluta > 8) || (datos.jugador.y_absoluta < 47 && datos.jugador.y_absoluta > 33)){
            return true;
        }
    }

    return false;
}

bool area_defensas(Datos_Juego &datos)
{   //defino numero defensa
    bool defensa = (datos.jugador.jugador_numero == "2" || datos.jugador.jugador_numero == "3" || datos.jugador.jugador_numero == "4" || datos.jugador.jugador_numero == "5");
    
    if (defensa)
    {
        if ((datos.jugador.x_absoluta < 50 && datos.jugador.x_absoluta > 24) || (datos.jugador.y_absoluta < 74 && datos.jugador.y_absoluta > 6)){
            return true;
        }
    }

    return false;

    }

bool area_mcs(Datos_Juego &datos)
{   //defino numero mediocentros
    bool mc = (datos.jugador.jugador_numero == "6" || datos.jugador.jugador_numero == "7" || datos.jugador.jugador_numero == "8");
    
    if (mc)
    {
        if ((datos.jugador.x_absoluta < 80 && datos.jugador.x_absoluta > 34) || (datos.jugador.y_absoluta < 74 && datos.jugador.y_absoluta > 6)){
            return true;
        }
    }

    return false;
}

bool area_delantero(Datos_Juego &datos)
{   //defino numero delanteros
    bool delantero = (datos.jugador.jugador_numero == "9" || datos.jugador.jugador_numero == "10" || datos.jugador.jugador_numero == "11");
    
    if (delantero)
    {
        if ((datos.jugador.x_absoluta <112 && datos.jugador.x_absoluta > 50) || (datos.jugador.y_absoluta < 74 && datos.jugador.y_absoluta > 6)){
            return true;
        }
    }

    return false;
}