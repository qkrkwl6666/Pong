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

    AddGo(_bat);
    AddGo(_ball);
    AddGo(_Ui);
    AddGo(_GameOver);

    fontResMgr.Load("font/DS-DIGI.ttf");
    _Ui->SetFont(fontResMgr.Get("font/DS-DIGI.ttf"));
    _Ui->SetString("Score : " + std::to_string(_score) +
        "  Lives : " + std::to_string(_lives));
    _GameOver->SetFont(fontResMgr.Get("font/DS-DIGI.ttf"));
    _GameOver->SetCharacterSize(75);
    _GameOver->SetPosition({ 1920.f / 2 , 1080.f / 2 });
    _GameOver->SetString("GameOver Enter To Restart");
    _GameOver->SetOrigin(Origins::MC);
    _GameOver->SetActive(false);
  
    for (GameObject* obj : gameObjects)
    {
        obj->Init();
    }
}

void poong::Release()
{

}

void poong::Reset()
{
    FRAMEWORK.SetTimeScale(1.f);
    _score = 0;
    _lives = 3;
    isGameOver = false;
    _GameOver->SetActive(false);
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
    Shot();

	if (!isBallActive)
    {
        _ball->SetPosition(_bat->GetPosition());
    }
    else
    {
       // _ball->Update(dt);
    }

    if (_ball->isDead)
    {
        isBallActive = false;
        _ball->Fire( {0.f, 0.f}, 0.f );
        _lives--;
        _score = 0;
        // 게임 재시작 대기
    }

    if (_ball->isBoundBat)
    {
        _score++;
    }

    if (_lives <= 0)
    {
        FRAMEWORK.SetTimeScale(0.f);
        _GameOver->SetActive(true);
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

    Scene::Update(dt);

}

void poong::Draw(sf::RenderWindow& window)
{
    Scene::Draw(window);
}

void poong::Shot()
{
    if (!isBallActive && InputMgr::GetKeyDown(sf::Keyboard::Space))
    {
        _ball->Fire({ 1.f, -1.f }, 1000.f);
        isBallActive = true;
    }
}
