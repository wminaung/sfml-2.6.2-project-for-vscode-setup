#include "Bullet.h"
#include "Math.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Bullet::Bullet() : speed(0) {}

Bullet::~Bullet() {}

void Bullet::Initialize(const sf::Vector2f &position, sf::Vector2f &target,
                        float speed) {
  //
  this->speed = speed;
  std::cout << "Bullet::Initialize()" << std::endl;

  rectangleShape.setSize(sf::Vector2f(50, 25));
  rectangleShape.setFillColor(sf::Color::Red);
  rectangleShape.setPosition(position);
  direction = Math::NormalizeVector(target - position);
}

void Bullet::Load() {}

void Bullet::Update(float deltaTime) {

  rectangleShape.setPosition(rectangleShape.getPosition() +
                             direction * speed * deltaTime);
}

void Bullet::Draw(sf::RenderWindow &window) {
  //
  window.draw(rectangleShape);
}
