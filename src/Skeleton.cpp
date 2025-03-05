#include "Skeleton.h"
#include <iostream>
Skeleton::Skeleton() : health(10.f) {}
Skeleton::~Skeleton() {}
void Skeleton::ChangeHealth(float hp) { health += hp; }
void Skeleton::Initialize() {
  scale = sf::Vector2f(2.f, 2.f);
  size = sf::Vector2f(defaultImgSize, defaultImgSize);

  boundingRectangle.setFillColor(sf::Color::Transparent);
  boundingRectangle.setOutlineColor(sf::Color::Red);
  boundingRectangle.setOutlineThickness(1);
}

void Skeleton::Load() {
  if (font.loadFromFile("Assets/Fonts/Roboto.ttf")) {
    healthText.setFont(font);
    healthText.setCharacterSize(24);
    std::cout << "Font loaded" << std::endl;
    healthText.setString(std::to_string((int)health) + " HP");
  } else {
    std::cout << "Font not loaded" << std::endl;
  }
  if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheep.png")) {
    std::cout << "Enemy images loaded!" << std::endl;
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(400, 400));
    int XIndex = 0;
    int YIndex = 2;
    sf::IntRect rect(XIndex * size.x, YIndex * size.y, size.x, size.y);
    sprite.setTextureRect(rect);
    sprite.setScale(scale);

    boundingRectangle.setSize(sf::Vector2f(size.x * scale.x, size.y * scale.y));
    boundingRectangle.setPosition(sprite.getPosition());
  } else {
    std::cout << "Enemy images not loaded!" << std::endl;
  }
}

void Skeleton::Update(float deltaTime) {
  if (health <= 0)
    return;
  healthText.setPosition(sprite.getPosition() + sf::Vector2f(0, -20));
  healthText.setString(std::to_string((int)health) + " HP");
  boundingRectangle.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow &window) {
  if (health <= 0)
    return;
  window.draw(healthText);
  window.draw(sprite);
  window.draw(boundingRectangle);
}
