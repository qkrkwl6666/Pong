#pragma once
#include <SFML/Graphics.hpp>

class Bat
{
protected:

public:
	Bat();

	sf::FloatRect prevGlobalBounds;

	float speed = 1000.f;
	sf::RectangleShape shape;

	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

