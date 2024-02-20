#pragma once
#include "ShapeGo.h"

class Bat : public ShapeGo
{
protected:

public:
	Bat();

	sf::FloatRect prevGlobalBounds;

	float speed = 1000.f;

	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

