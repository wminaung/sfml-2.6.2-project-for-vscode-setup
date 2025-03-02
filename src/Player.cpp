#include "Player.h"
#include "Math.h"
#include <iostream>

void Player::Initialize()
{
	bullets.reserve(100);
	scale = sf::Vector2f(2.f, 2.f);
	size = sf::Vector2f(defaultImgSize, defaultImgSize);

	boundingRectangle.setFillColor(sf::Color::Transparent);
	boundingRectangle.setOutlineColor(sf::Color::Green);
	boundingRectangle.setOutlineThickness(1);



}

void Player::Load()
{
	if (texture.loadFromFile("Assets/Player/Textures/spritesheep.png")) {
		std::cout << "Player images loaded!" << std::endl;
		sprite.setTexture(texture);
		int XIndex = 0;
		int YIndex = 0;
		sf::IntRect rect(XIndex * size.x, YIndex * size.y, size.x, size.y);
		sprite.setTextureRect(rect);
		sprite.setScale(scale);
		sprite.setPosition(sf::Vector2f(120, 120));

		boundingRectangle.setSize(sf::Vector2f(size.x * scale.x, size.y * scale.y));
		boundingRectangle.setPosition(sprite.getPosition());
	}
	else {

		std::cout << "Player images not loaded!" << std::endl;
	}
}

void Player::Update(float deltaTime, Skeleton& skeleton)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		sf::Vector2f postion = sprite.getPosition();
		sprite.setPosition(postion + sf::Vector2f(1, 0) * playerSpeed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		sf::Vector2f postion = sprite.getPosition();
		sprite.setPosition(postion + sf::Vector2f(-1, 0) * playerSpeed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		sf::Vector2f postion = sprite.getPosition();
		sprite.setPosition(postion + sf::Vector2f(0, 1) * playerSpeed * deltaTime);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		sf::Vector2f postion = sprite.getPosition();
		sprite.setPosition(postion + sf::Vector2f(0, -1) * playerSpeed * deltaTime);
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		bullets.push_back(sf::RectangleShape(sf::Vector2f(40, 20)));
		bullets[bullets.size() - 1].setPosition(sprite.getPosition());

	}

	for (size_t i = 0; i < bullets.size(); i++)
	{
		// move bullet
		sf::Vector2f bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
		bulletDirection = Math::NormalizeVector(bulletDirection);
		bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);

		// check bullet collision
		if (Math::DidRectCollide(bullets[i].getGlobalBounds(), skeleton.sprite.getGlobalBounds()))
		{
				bullets.erase(bullets.begin() + i);
		}

	}
	// update bounding rectangle
	boundingRectangle.setPosition(sprite.getPosition());


}

void Player::Draw(sf::RenderWindow& window)
{
	window.draw(sprite);
	window.draw(boundingRectangle);
	for (size_t i = 0; i < bullets.size(); i++)
	{
		window.draw(bullets[i]);
	}
}

