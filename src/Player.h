#pragma once
#include "Bullet.h"
#include "Skeleton.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>


class Player {
private:
  sf::Texture texture;
  std::vector<Bullet> bullets;
  // float bulletSpeed;
  float maxFireRate;
  float fireRateTimer;

  float playerSpeed;
  sf::Vector2f scale;
  float defaultImgSize = 65;
  sf::Vector2f size;
  sf::RectangleShape boundingRectangle;

public:
  sf::Sprite sprite;

  Player();
  ~Player();
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
  void Update(float deltaTime, Skeleton &skeleton, sf::Vector2f &mousePosition);
  /*
   *  once per frame
   */
  void Draw(sf::RenderWindow &window);
};
