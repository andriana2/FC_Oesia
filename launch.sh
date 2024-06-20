#!/bin/bash

cd build && make && cd ..

sleep 3;





for i in {0..10}
do
  gnome-terminal -- bash -c "/home/mexarlg/Documents/Oesia /School project/FC_Oesia/build/player FC_Oesia 555$i" & sleep 1
done
