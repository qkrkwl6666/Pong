#include "pch.h"
#include "Ball.h"
#include "Bat.h"

Ball::Ball(Bat& bat, const sf::FloatRect& bounds)
	: ShapeGo<sf::CircleShape>("Ball"), bat(bat), windowBounds(bounds)
{
	shape.setRadius(10.f);
	SetColor(sf::Color::White);
	SetOrigin(Origins::BC);
}

void Ball::Fire(sf::Vector2f d, float s)
{
	direction = d;
	speed = s;
	isDead = false;
}

void Ball::Update(float dt)
{
	isBoundBat = false;

	const sf::FloatRect& prevBallBounds = GetGlobalBounds();
	sf::Vector2f prevPos = GetPosition();
	sf::Vector2f pos = prevPos;
	pos += direction * speed * dt;
	SetPosition(pos);

	const sf::FloatRect& ballBounds = GetGlobalBounds();
	float ballLeft = ballBounds.left;
	float ballRight = ballBounds.left + ballBounds.width;
	float ballTop = ballBounds.top;
	float ballBottom = ballBounds.top + ballBounds.height;

	float windowLeft = windowBounds.left;
	float windowRight = windowBounds.left + windowBounds.width;
	float windowTop = windowBounds.top;
	float windowBottom = windowBounds.top + windowBounds.height;

	// 面倒 贸府 windowBounds
	// isDead = true;
	if (ballBottom > windowBottom + 300)
	{
		isDead = true;
		SetPosition(prevPos);
		direction.y *= -1.f;
	}
	else if (ballTop < windowTop)
	{
		SetPosition(prevPos);
		direction.y *= -1.f;
	}
	else if (ballLeft < windowLeft || ballRight > windowRight)
	{
		SetPosition(prevPos);
		direction.x *= -1.f;
	}

	// 面倒 贸府 bat
	const sf::FloatRect& batBounds = bat.GetGlobalBounds();
	if (!prevBallBounds.intersects(bat.prevGlobalBounds) && ballBounds.intersects(batBounds))
	{
		isBoundBat = true;

		float batLeft = batBounds.left;
		float batRight = batBounds.left + batBounds.width;
		float batTop = batBounds.top;
		float batBottom = batBounds.top + batBounds.height;

		if (ballBottom > batTop || ballTop < batBottom)
		{
			direction.y *= -1.f;
		}
		if (ballLeft > batRight || ballRight < batLeft)
		{
			direction.x *= -1.f;
		}
	}
}

void Ball::Draw(sf::RenderWindow& window)
{
	ShapeGo<sf::CircleShape>::Draw(window);
}
