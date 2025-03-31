#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

/*
    Class that acts as engine
*/

class Game {
private:
  // variables
  // Window
  sf::RenderWindow *window;
  sf::Event ev;
  sf::VideoMode videoMode;

  // Private function
  void initVariable();
  void initWindow();

public:
  Game(/* args */);
  virtual ~Game();

  // Accessors
  const bool running() const;

  // Functions
  void pollEvents();
  void update();
  void render();
};
