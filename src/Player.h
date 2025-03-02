#pragma once
#include <SFML/Graphics.hpp>
#include "Skeleton.h"
#include <iostream>
#include <vector>

class Player
{
private: 
	sf::Texture texture;
	std::vector<sf::RectangleShape> bullets;
	float bulletSpeed = 1.f;
	float playerSpeed = 1.f;
	sf::Vector2f scale;
	float defaultImgSize = 65;
	sf::Vector2f size;
	sf::RectangleShape boundingRectangle;

public:
	sf::Sprite sprite;
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
	void Update(float deltaTime, Skeleton& skeleton);
	/*
	*  once per frame
	*/
	void Draw(sf::RenderWindow &window);

};
