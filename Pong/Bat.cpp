#include "pch.h"
#include "Bat.h"

Bat::Bat()
{
	SetSize({ 100.f, 5.f });
	SetPosition({ 1920.f / 2.f, 1080.f - 20.f });
	SetColor(sf::Color::White);
	SetOrigin(Origins::TC);
}

void Bat::Update(float dt)
{
	prevGlobalBounds = GetGlobalBounds();

	float h = InputMgr::GetAxis(Axis::Horizontal);
	sf::Vector2f pos = GetPosition();
	pos.x += h * speed * dt;
	SetPosition(pos);
}

void Bat::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
