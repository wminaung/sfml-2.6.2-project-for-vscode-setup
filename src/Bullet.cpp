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
  std::cout << ">>> position x , y " << position.x << " " << position.y
            << " <<<" << std::endl;
  std::cout << ">>> target x , y " << target.x << " " << target.y << " <<<"
            << std::endl;
  std::cout << ">>> target - position " << (target - position).x << " "
            << (target - position).y << " <<<" << std::endl;
  direction = Math::NormalizeVector(target - position);
  std::cout << ">>> direction x , y " << direction.x << " " << direction.y
            << " <<<" << std::endl;
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
