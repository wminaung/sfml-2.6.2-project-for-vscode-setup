#include "Map.h"
#include <iostream>

Map::Map() : tileWidth(16), tileHeight(16), totalTilesX(0), totalTilesY(0) {}

Map::~Map() {}

void Map::Initialize() { std::cout << "Map::Initialize()" << std::endl; }

void Map::Load() {
  //
  if (texture.loadFromFile("Assets/World/Prison/tilesheep.png")) {
    totalTilesX = texture.getSize().x / tileWidth;
    totalTilesY = texture.getSize().y / tileHeight;
    std::cout << "Total tiles: " << totalTilesX << " x " << totalTilesY
              << std::endl;
    std::cout << "Map Tilesheep loaded!" << std::endl;
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(5, 5));
    // sprite.setTexture(texture);
    // int XIndex = 0;
    // int YIndex = 0;
    // sf::IntRect rect(XIndex * size.x, YIndex * size.y, size.x, size.y);
    // sprite.setTextureRect(rect);
    // sprite.setScale(scale);
    // sprite.setPosition(sf::Vector2f(120, 120));

    // boundingRectangle.setSize(sf::Vector2f(size.x * scale.x, size.y *
    // scale.y)); boundingRectangle.setPosition(sprite.getPosition());
  } else {
    std::cout << "Map Tilesheep not loaded!" << std::endl;
  }
}

void Map::Update(float deltaTime) {}

void Map::Draw(sf::RenderWindow &window) { window.draw(sprite); }
