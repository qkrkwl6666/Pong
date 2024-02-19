#pragma once
#include "pch.h"

class Bat
{
protected:
	
public:
	Bat();

	float _speed = 500.f;
	sf::RectangleShape _shape;

	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

