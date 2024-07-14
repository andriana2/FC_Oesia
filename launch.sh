
#!/bin/bash

cd build && make && cd ..

sleep 2;

gnome-terminal -- bash -c "./build/player FC_Oesia 566$i" & sleep 1

for i in {1..10}
do
  gnome-terminal -- bash -c "./build/player FC_Oesia 555$i" & sleep 1
done
