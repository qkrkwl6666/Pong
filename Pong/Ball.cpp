#include "Ball.h"
#include "pch.h"
#include "Bat.h"
#include "Framework/Utils.h"

Ball::Ball(Bat& b, const sf::FloatRect& bounds) : bat(bat) ,
	windowBounds(bounds)
{
	_shape.setRadius(10.f);
	_shape.setPosition({1920.f / 2.f , 1080.f - 35.f});
	_shape.setFillColor(sf::Color::White);

	Utils::SetOrigin(_shape, Origins::BC);
}

void Ball::Fire(sf::Vector2f d, float s)
{
	direction = d;
	_speed = s;
	isDead = false;
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
	if (ballBounds.intersects(batBounds))
	{
		direction *= 1.f;
		isBoundBat = true;
	}
	

	//if (_shape.getGlobalBounds().top < windowBounds.top                                                                                                                                                                                                                                                                                          windowBounds.left)
	//{
	//	Fire({-std::abs(Utils::RandomValue()), 1.f}, 1000.f);
	//}
	//if (_shape.getGlobalBounds().top - 100 > 1080)
	//{
	//	Fire({std::abs(Utils::RandomValue()), -1.f}, 1000.f);
	//}
	//if (_shape.getGlobalBounds().left > windowBounds.left)
	//{
	//	Fire({std::abs(Utils::RandomValue()), -1.f}, 1000.f);
	//}

}

void Ball::Draw(sf::RenderWindow& window)
{
	window.draw(_shape);
}
