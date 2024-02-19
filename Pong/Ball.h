#pragma once
#include "pch.h"

class Bat;

class Ball
{
protected:
	sf::Vector2f direction = { 0.f , 0.f };
	float _speed = 0.f;
	Bat& bat;
	sf::FloatRect windowBounds;
	

public:
	bool isDead = false;
	bool isBoundBat = false;

	Ball(Bat& b, const sf::FloatRect& bounds);
	
	

	sf::CircleShape _shape;


	void Fire(sf::Vector2f d, float s);

	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

