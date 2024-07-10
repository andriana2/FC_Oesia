# FC_Oesia

Nosotros somos:
- Andriana Dovhanych
- Andrés Medina 
- Aldo Lupio
- Francisco J. Carrasco

## Documentación y instalación

- [Official RoboCup Soccer Simulator](https://rcsoccersim.github.io/)
- [Resources](https://github.com/rcsoccersim/)

## How to use it in Ubuntu
```bash
mkdir build
cd build
cmake ..
make
cd ..
./launch.sh
````
## Fallos 
En Ubuntu 24.04 da un fallo por el gnome pero se soluciona añadiendo antes de la ejecucion esta linea de codigo
````c
unset GTK_PATH
````
## Descripción
Se trata de un partido de fútbol en el que diseñamos la estrategia de los jugadores, simulando un encuentro lo más parecido posible a uno real, incluyendo faltas y todos los elementos involucrados en un partido.

En la imagen a continuación, pueden ver el inicio de un partido, siendo nuestro equipo el de la izquierda.

![Imagen](imagenes/robocup.png)


