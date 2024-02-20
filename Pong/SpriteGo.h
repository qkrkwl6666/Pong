#pragma once
#include <functional>

class SpriteGo : public GameObject
{
public:

protected:
	Sprite sprite;

public:
	SpriteGo(const std::string& name = "");

	void SetTexture(const std::string& textureId);
	void SetTexture(const sf::Texture& texture);

	void SetPosition(const sf::Vector2f& pos) override;
	void SetOrigin(Origins preset) override;
	void SetOrigin(const sf::Vector2f& newOrigin) override;
	void SetScale(const sf::Vector2f& scale) override;
	void SetFlipX(bool filp) override;
	void SetFlipY(bool filp) override;

	void GetSize(Vector2f& size) const
	{
		size = Vector2f(sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);
	}
	void Draw(RenderWindow& window) override;
	void Update(float dt) override
	{

	}
	
};

