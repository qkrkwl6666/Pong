#pragma once

class ShapeGo : public GameObject
{
public:
	ShapeGo(const std::string name = "");
	virtual ~ShapeGo();

	void Init() override;
	void Release() override;

	void Reset() override;

	void Update(float dt) override;
	void Draw(sf::RenderWindow& window) override;

	void SetPosition(const sf::Vector2f& pos) override
	{
		GameObject::SetPosition(pos);
		shape.setPosition(pos);
	}

	void SetScale(const sf::Vector2f& scale) override;

	virtual void SetOrigin(Origins preset);
	virtual void SetOrigin(const sf::Vector2f& newOrigin);

	void SetTexture(const std::string& textureId);
	void SetTexture(const sf::Texture& texture);

	void SetSize(const sf::Vector2f& size);
	sf::Vector2f GetSize();

	void SetColor(sf::Color color);

	sf::FloatRect GetGlobalBounds();



protected:
	sf::RectangleShape shape;

};

