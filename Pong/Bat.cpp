
#include "Bat.h"

Bat::Bat()
{
	_shape.setSize({ 100, 5 });
	_shape.setPosition({ 1920.f / 2.f , 1080.f - 20.f });
	_shape.setFillColor(sf::Color::White);

	Utils::SetOrigin(_shape, Origins::TC);
}

void Bat::Update(float dt)
{
	// Ű �Է�
	float h = InputMgr::GetAxisRaw(Axis::Horieontal);

	sf::Vector2f pos = _shape.getPosition();
	pos.x += h * _speed * dt;
	_shape.setPosition(pos);

	std::cout << InputMgr::GetMouseButton(sf::Mouse::Left) << std::endl;

}

void Bat::Draw(sf::RenderWindow& window)
{
	window.draw(_shape); // �ڽ��� _shape��ü �׸���
}
