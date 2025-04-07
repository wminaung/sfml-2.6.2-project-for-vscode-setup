#!/bin/bash

# Create build directory if it doesn't exist
mkdir -p build

# Function to copy file only if it doesn't exist in build directory
copy_if_not_exists() {
    if [ ! -f "build/$(basename "$1")" ]; then
        cp "$1" build/
        echo "Copied $(basename "$1")"
    else
        echo "$(basename "$1") already exists, skipping..."
    fi
}

# Copy required DLLs only if they don't exist
copy_if_not_exists "dependencies/SFML/bin/sfml-graphics-2.dll"
copy_if_not_exists "dependencies/SFML/bin/sfml-window-2.dll"
copy_if_not_exists "dependencies/SFML/bin/sfml-system-2.dll"

# Compile
# g++ -g src/*.cpp -o build/main.exe -I dependencies/SFML/include -L dependencies/SFML/lib -lsfml-graphics -lsfml-window -lsfml-system
g++ -g src/*.cpp -o build/main.exe -I dependencies/SFML/include -L build -lsfml-graphics-2 -lsfml-window-2 -lsfml-system-2

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful! Running the program..."
    ./build/main.exe
else
    echo "Compilation failed!"
fi
