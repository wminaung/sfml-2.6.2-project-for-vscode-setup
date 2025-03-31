#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

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

  // Mouse positions

  sf::Vector2i mousePosWindow;

  // Game Objects
  std::vector<sf::RectangleShape> enemies;
  sf::RectangleShape enemy;

  // Private function
  void initVariable();
  void initWindow();
  void initEnemies();

public:
  Game(/* args */);
  virtual ~Game();

  // Accessors
  const bool running() const;

  // Functions

  void pollEvents();
  void updateMousePosition();
  void update();
  void render();
};
