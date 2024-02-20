#pragma once
#include "Scene.h"
class TextGo;

class Ball;
class Bat;

class poong : public Scene
{
public:
	poong(SceneIds ids);

	void Init() override;
	void Release() override;
	void Reset();

	void Enter() override;
	void Exit() override;

	void Update(float dt);
	void Draw(sf::RenderWindow& window);

private:
	Ball* _ball;
	Bat* _bat;
	TextGo* _Ui;
	TextGo* _GameOver;

	int _score = 0;
	int _lives = 3;

	bool isBallActive = false;
	bool isGameOver = false;
};

