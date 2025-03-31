
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <iostream>

template <typename T> void println(T t) { std::cout << t << std::endl; }

int main() {

  // Init Game Engine

  Game game;

  // Game loop
  while (game.running()) {

    // Update
    game.update();
    // Render
    game.render();
    // End Game loop
  }

  return 0;
}
