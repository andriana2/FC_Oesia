#!/bin/bash

echo "Starting script..."
cd build
echo "Entering build directory..."

if make; then
    echo "Build succeeded."
    cd ..
else
    echo "Build failed, exiting..."
    exit 1
fi

sleep 2

for i in {0..10}
do
  echo "Launching player $i..."
  gnome-terminal -- bash -c "'/home/mexarlg/Documents/Oesia /School project/FC_Oesia/build/player' 'FC_Oesia' '555$i'" &
  sleep 1
done

echo "All players launched."