#include "area.h"

bool area_portero(Datos_Juego &datos)
{
    if (datos.jugador_numero == "1")
    {
        if (datos.x_absoluta < 13 && datos.y_absoluta > 0){
            return true;
        }
    }

    return false;
}