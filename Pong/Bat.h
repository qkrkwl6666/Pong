#pragma once
#include "ShapeGo.h"

class Bat : public ShapeGo<sf::RectangleShape>
{
protected:

public:
	Bat();

	sf::FloatRect prevGlobalBounds;

	float speed = 2500.f;

	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

