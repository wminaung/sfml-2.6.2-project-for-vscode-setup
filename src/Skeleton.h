
#pragma once
#include <SFML/Graphics.hpp>

class Skeleton
{
private:
	sf::Texture texture;

	
	float defaultImgSize = 65;
	sf::Vector2f scale;
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
	void Update(float deltaTime);
	/*
	*  once per frame
	*/
	void Draw(sf::RenderWindow& window);

};
