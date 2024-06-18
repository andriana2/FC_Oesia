#!/bin/bash

##cd build && make && cd ..
sleep 3;



for i in {0..2}; do

    xterm -e /bin/bash -l -c "/home/francarg/Escritorio/FC_Oesia/build/player FC_Oesia 557$i" & sleep 1
done