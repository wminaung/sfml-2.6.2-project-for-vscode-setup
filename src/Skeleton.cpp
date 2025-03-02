#include "Skeleton.h"
#include <iostream>
void Skeleton::Initialize()
{
	scale = sf::Vector2f(2.f, 2.f);
	size = sf::Vector2f(defaultImgSize, defaultImgSize );

	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Red);
	boundingRectangle.setOutlineThickness(1);



}


void Skeleton::Load()
{
	if (texture.loadFromFile("Assets/Skeleton/Textures/spritesheep.png")) {
		std::cout << "Enemy images loaded!" << std::endl;
		sprite.setTexture(texture);
		sprite.setPosition(sf::Vector2f(400, 400));
		int XIndex = 0;
		int YIndex = 2;
		sf::IntRect rect(XIndex * size.x, YIndex * size.y, size.x, size.y);
		sprite.setTextureRect(rect);
		sprite.setScale(scale);

		boundingRectangle.setSize(sf::Vector2f( size.x * scale.x, size.y * scale.y));
		boundingRectangle.setPosition(sprite.getPosition());
	}
	else {
		std::cout << "Enemy images not loaded!" << std::endl;
	}
}

void Skeleton::Update(float deltaTime)
{
	boundingRectangle.setPosition(sprite.getPosition());
}

void Skeleton::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);	
	window.draw(boundingRectangle);
}
