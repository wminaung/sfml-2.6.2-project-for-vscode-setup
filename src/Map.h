#pragma once
#include <SFML/Graphics.hpp>

class Map {
private:
  sf::Texture texture;
  sf::Sprite sprite;
  int tileWidth;
  int tileHeight;

  int totalTilesX;
  int totalTilesY;
  // sf::Vector2f scale;
  // sf::Vector2f size;
  // sf::RectangleShape boundingRectangle;
  // float defaultImgSize = 65;

public:
  Map();
  ~Map();
  void Initialize();
  void Load();
  void Update(float deltaTime);
  void Draw(sf::RenderWindow &window);
};
