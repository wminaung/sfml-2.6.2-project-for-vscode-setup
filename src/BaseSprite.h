#pragma once
#include <SFML/Graphics.hpp>

class BaseSprite {
private:
  sf::Texture texture;
  sf::Vector2f scale;
  sf::Vector2f size;
  sf::RectangleShape boundingRectangle;
  float defaultImgSize;

public:
  sf::Sprite sprite;

  virtual void Initialize();
  virtual void Load();
  virtual void Update(float deltaTime);
  virtual void Draw(sf::RenderWindow &window);
};
