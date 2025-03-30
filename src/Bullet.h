#pragma once
#include <SFML/Graphics.hpp>

class Bullet {
private:
  sf::RectangleShape rectangleShape;
  sf::Vector2f direction;

  //   sf::Texture texture;
  //   sf::Vector2f scale;
  //   sf::Vector2f size;
  //   sf::RectangleShape boundingRectangle;
  //   float defaultImgSize = 65;

public:
  //   sf::Sprite sprite;
  Bullet();
  ~Bullet();

  float speed;
  //   float fireRate;

  void Initialize(const sf::Vector2f &position, sf::Vector2f &target,
                  float speed);
  void Load();
  void Update(float deltaTime);
  void Draw(sf::RenderWindow &window);

  inline sf::FloatRect GetBlobalBounds() const {
    return rectangleShape.getGlobalBounds();
  }
};
