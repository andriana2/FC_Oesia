
#!/bin/bash

cd build && make && cd ..

sleep 2;

for i in {0..10}
do
  gnome-terminal -- bash -c "./build/player FC_Oesia 555$i" & sleep 1
done
