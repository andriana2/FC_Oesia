
#include "area.h"

bool area_portero(Datos_Juego &datos)
{   //defino numero portero
    bool portero = (datos.jugador_numero == "1");
    if (portero)
    {
        if ((datos.x_absoluta < 13 && datos.y_absoluta > 8) || (datos.y_absoluta < 47 && datos.y_absoluta > 33)){
            return true;
        }
    }

    return false;
}

bool area_defensas(Datos_Juego &datos)
{   //defino numero defensa
    bool defensa = (datos.jugador_numero == "2" || datos.jugador_numero == "3" || datos.jugador_numero == "4" || datos.jugador_numero == "5");
    
    if (defensa)
    {
        if ((datos.x_absoluta < 50 && datos.x_absoluta > 24) || (datos.y_absoluta < 74 && datos.y_absoluta > 6)){
            return true;
        }
    }

    return false;

    }

bool area_mcs(Datos_Juego &datos)
{   //defino numero mediocentros
    bool mc = (datos.jugador_numero == "6" || datos.jugador_numero == "7" || datos.jugador_numero == "8");
    
    if (mc)
    {
        if ((datos.x_absoluta < 80 && datos.x_absoluta > 34) || (datos.y_absoluta < 74 && datos.y_absoluta > 6)){
            return true;
        }
    }

    return false;
}

bool area_delantero(Datos_Juego &datos)
{   //defino numero delanteros
    bool delantero = (datos.jugador_numero == "9" || datos.jugador_numero == "10" || datos.jugador_numero == "11");
    
    if (delantero)
    {
        if ((datos.x_absoluta <112 && datos.x_absoluta > 50) || (datos.y_absoluta < 74 && datos.y_absoluta > 6)){
            return true;
        }
    }

    return false;
}