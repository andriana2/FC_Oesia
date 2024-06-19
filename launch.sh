#!/bin/bash

cd build && make && cd ..
<<<<<<< HEAD

=======
rm 20*
>>>>>>> 68695890dc8949c3b7f70e34cb59b2da9bef25a2
sleep 3;





for i in {0..10}
do
  gnome-terminal -- bash -c "/home/Andres5/Escritorio/FC_Oesia/build/player FC_Oesia 555$i" & sleep 1
done
