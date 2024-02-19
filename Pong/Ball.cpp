#include "Ball.h"
#include "pch.h"
#include "Bat.h"
#include "Framework/Utils.h"

Ball::Ball(Bat& b, const sf::FloatRect& bounds) : bat(b) ,
	windowBounds(bounds)
{
	_shape.setRadius(10.f);
	_shape.setPosition({1920.f / 2.f , 1080.f - 35.f});
	_shape.setFillColor(sf::Color::White);

	Utils::SetOrigin(_shape, Origins::BC);
	font.loadFromFile("DS-DIGI.ttf");
	text.setFont(font);

	text.setCharacterSize(50);
	text.setString("SCORE : " + std::to_string(_score) +
		"  LIVES : " + std::to_string(_lives));
}

void Ball::Fire(sf::Vector2f d, float s)
{
	direction = d;
	_speed = s;
	isDead = false;
}

float Ball::RandomValue()
{
	if (Utils::RandomValue() > 0.5)
	{
		return 1.f;
	}
	else
		return -1.f;
}

void Ball::AddScore()
{
	if (isBoundBat)
	{
		_score += 10;
		text.setString("SCORE : " + std::to_string(_score) +
			"  LIVES : " + std::to_string(_lives));
	}

}

void Ball::Update(float dt)
{
	sf::Vector2f pos = _shape.getPosition();
	pos += direction * _speed * dt;
	_shape.setPosition(pos);
	// ballbounds top == windowbounds 서로 비교하고 충돌검사

	const sf::FloatRect& ballBounds = _shape.getGlobalBounds();
	const sf::FloatRect& batBounds = bat._shape.getGlobalBounds();
	
	// isDead = true;

	//충돌 처리 bat
	if (ballBounds.intersects(batBounds) && !isBoundBat)
	{
		direction = { RandomValue(), -1.f };
		isBoundBat = true;
	}

	AddScore();

	isBoundBat = false;

	// 위 충돌
	if (_shape.getGlobalBounds().top < windowBounds.top)
	{
		Fire({ RandomValue(), 1.f }, _speed);
	}

	// 오른쪽 충돌
	if (_shape.getGlobalBounds().left + _shape.getGlobalBounds().width > windowBounds.width)
	{
		Fire({ -1.f, RandomValue() }, _speed);
	}

	// 아래 충돌
	if (_shape.getGlobalBounds().top + _shape.getGlobalBounds().height > windowBounds.height)
	{
		Fire({ RandomValue(), -1.f }, _speed);
	}

	// 왼쪽 충돌
	if (_shape.getGlobalBounds().left < windowBounds.left)
	{
		Fire({ 1.f, RandomValue() }, _speed);
	}
}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(_shape);
	window.draw(text);
}
