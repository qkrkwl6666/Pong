#include "pch.h"
#include "ShapeGo.h"

ShapeGo::ShapeGo(const std::string name) : GameObject(name)
{

}

ShapeGo::~ShapeGo()
{

}

void ShapeGo::Init()
{
	
}

void ShapeGo::Release()
{

}

void ShapeGo::Reset()
{

}

void ShapeGo::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

void ShapeGo::SetScale(const sf::Vector2f& scale)
{
	GameObject::SetScale(scale);
	shape.setScale(scale);
}

void ShapeGo::SetOrigin(Origins preset)
{
	GameObject::SetOrigin(preset);
	Utils::SetOrigin(shape, preset);
}

void ShapeGo::SetOrigin(const sf::Vector2f& newOrigin)
{
	GameObject::SetOrigin(newOrigin);
	shape.setOrigin(newOrigin);
}

void ShapeGo::SetTexture(const std::string& textureId)
{
	const sf::Texture& texture = ResourceMgr<sf::Texture>::Instance().Get(textureId);
	shape.setTexture(&texture);
}

void ShapeGo::SetTexture(const sf::Texture & texture)
{
	shape.setTexture(&texture);
}

void ShapeGo::SetSize(const sf::Vector2f& size)
{
	shape.setSize(size);
}

sf::Vector2f ShapeGo::GetSize()
{
	return shape.getSize();
}

void ShapeGo::SetColor(sf::Color color)
{
	shape.setFillColor(color);
}

sf::FloatRect ShapeGo::GetGlobalBounds()
{
	return shape.getGlobalBounds();
}


