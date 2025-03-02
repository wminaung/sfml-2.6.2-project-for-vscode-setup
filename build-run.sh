#!/bin/bash

# Create build directory if it doesn't exist
mkdir -p build

# Copy required DLLs to build directory
cp dependencies/SFML/bin/sfml-graphics-2.dll build/
cp dependencies/SFML/bin/sfml-window-2.dll build/
cp dependencies/SFML/bin/sfml-system-2.dll build/

# Compile
g++ -g src/*.cpp -o build/main.exe -I dependencies/SFML/include -L dependencies/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful! Running the program..."
    ./build/main.exe
else
    echo "Compilation failed!"
fi
