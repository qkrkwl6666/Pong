#include "pch.h"
#include "poong.h"
#include "Bat.h"
#include "Ball.h"
#include "TextGo.h"

poong::poong(SceneIds ids) : Scene(ids)
{

}

void poong::Init()
{
	_bat = new Bat();
	_ball = new Ball(*_bat, { { 0.f, 0.f }, { 1920.f, 1080.f } });
    _Ui = new TextGo("UI");
    _GameOver = new TextGo("GameOver");

    fontResMgr.Load("font/DS-DIGI.ttf");
    _Ui->SetFont(fontResMgr.Get("font/DS-DIGI.ttf"));
    _Ui->SetString("Score : " + std::to_string(_score) +
        "  Lives : " + std::to_string(_lives));
    _GameOver->SetFont(fontResMgr.Get("font/DS-DIGI.ttf"));
    _GameOver->SetCharacterSize(75);
    _GameOver->SetPosition({ 1920.f / 2 , 1080.f / 2 });
    _GameOver->SetString("");
    _GameOver->SetOrigin(Origins::MC);
    _GameOver->SetActive(false);
}

void poong::Release()
{

}

void poong::Reset()
{
    _score = 0;
    _lives = 3;
    isGameOver = false;
    _GameOver->SetString("");
    isBallActive = false;
    _ball->Fire( {0.f, 0.f}, 0.f );
}

void poong::Enter()
{

}

void poong::Exit()
{

}

void poong::Update(float dt)
{
	if (!isBallActive && InputMgr::GetKeyDown(sf::Keyboard::Space))
    {
        _ball->Fire({ 1.f, -1.f }, 1000.f);
        isBallActive = true;
    }

    _bat->Update(dt);

	if (!isBallActive)
    {
        _ball->shape.setPosition(_bat->shape.getPosition());
    }
    else
    {
        _ball->Update(dt);
    }

    if (_ball->isDead)
    {
        isBallActive = false;
        _ball->Fire( {0.f, 0.f}, 0.f );
        _lives--;
        // 게임 재시작 대기
    }
    else if (_ball->isBoundBat)
    {
        _score++;
    }
    if (_lives <= 0)
    {
        _GameOver->SetString("GameOver Enter To Restart");
        isGameOver = true;
    }

    if (isGameOver)
    {
        if(InputMgr::GetKeyDown(sf::Keyboard::Enter))
        {
            Reset();
        }
    }

    _Ui->SetString("Score : " + std::to_string(_score) +
        "  Lives : " + std::to_string(_lives));

}

void poong::Draw(sf::RenderWindow& window)
{
	window.draw(_ball->shape); 
	window.draw(_bat->shape); 
    _Ui->Draw(window);
    _GameOver->Draw(window);
}
