
#pragma once
#include <SFML/Graphics.hpp>

class Skeleton {
private:
  sf::Texture texture;
  sf::Text healthText;
  sf::Font font;
  float defaultImgSize = 65;
  sf::Vector2f scale;
  sf::Vector2f size;
  sf::RectangleShape boundingRectangle;

public:
  sf::Sprite sprite;
  float health;

  Skeleton();
  ~Skeleton();
  void ChangeHealth(float hp);
  /*
   *  called per app start
   */
  void Initialize();
  /*
   *  called per app start
   */
  void Load();

  /*
   *  once per frame
   */
  void Update(float deltaTime);
  /*
   *  once per frame
   */
  void Draw(sf::RenderWindow &window);
};
