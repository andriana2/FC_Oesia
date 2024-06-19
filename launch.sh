#!/bin/bash

cd build && make && cd ..

sleep 3;





for i in {0..10}
do
  gnome-terminal -- bash -c "/home/Andres5/Escritorio/FC_Oesia/build/player FC_Oesia 555$i" & sleep 1
done
