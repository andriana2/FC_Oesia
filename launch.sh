#!/bin/bash

cd build && make && cd ..
rm 20*
sleep 3;

gnome-terminal -- bash -c /home/andri/Descargas/rcssserver-19.0.0/src/rcsoccersim & sleep 1



for i in {0..10}
do
  gnome-terminal -- bash -c "/home/andri/Escritorio/FC_Oesia/build/player FC_Oesia 555$i" & sleep 1
done
