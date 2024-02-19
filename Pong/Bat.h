#pragma once

class Bat
{
protected:
	
public:
	float _speed = 100.f;
	sf::RectangleShape _shape;

	void Init();

	void Update(float dt);
	void Draw(sf::RenderWindow& window);
};

