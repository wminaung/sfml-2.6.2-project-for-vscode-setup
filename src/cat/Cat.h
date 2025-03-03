#pragma once
#include <SFML/Graphics.hpp>

class Cat {
private:
  sf::Texture texture;
  sf::Vector2f scale;
  sf::Vector2f size;
  sf::RectangleShape boundingRectangle;
  float defaultImgSize = 65;

public:
  sf::Sprite sprite;

  void Initialize();
  void Load();
  void Update(float deltaTime);
  void Draw(sf::RenderWindow &window);
};
