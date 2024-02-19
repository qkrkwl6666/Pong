#pragma once
#include "pch.h"

class Bat;

class Ball
{
protected:
	sf::Vector2f direction = { 0.f , 0.f };
	float _speed = 0.f;
	Bat& bat;

	sf::Font font;
	sf::Text text;
	int _score = 0;
	int _lives = 3;

public:
	bool isDead = false;
	bool isBoundBat = false;
	sf::FloatRect windowBounds;
	Ball(Bat& b, const sf::FloatRect& bounds);
	

	sf::CircleShape _shape;


	void Fire(sf::Vector2f d, float s);
	float RandomValue();
	void AddScore();
	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

