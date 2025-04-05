#!/bin/bash

# Create build directory if it doesn't exist
mkdir -p build

# Function to copy file only if it doesn't exist in build directory

# Compile
# g++ -g src/*.cpp -o build/main.exe -I dependencies/SFML/include -L dependencies/SFML/lib  -lsfml-graphics-d -lsfml-window-d -lsfml-system-d
g++ -g src/*.cpp -o build/main.exe

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful! Running the program..."
    ./build/main.exe
else
    echo "Compilation failed!"
fi
