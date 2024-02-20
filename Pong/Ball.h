#pragma once
#include "ShapeGo.h"

class Bat;

class Ball : public ShapeGo<sf::CircleShape>
{
protected:
	sf::Vector2f direction = { 0.f, 0.f };
	float speed = 110.f;

	Bat& bat;
	sf::FloatRect windowBounds;

public:
	bool isDead = false;
	bool isBoundBat = false;

	Ball(Bat& bat, const sf::FloatRect& bounds);

	void Fire(sf::Vector2f d, float s);

	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

