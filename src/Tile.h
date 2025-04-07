#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

struct Tile {
  int id = -1;
  sf::Texture *texture = nullptr;
  sf::Sprite sprite;
};