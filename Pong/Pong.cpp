﻿#include <SFML/Graphics.hpp>

#include "Framework/Defines.h"
#include "Framework/Utils.h"
#include "Framework/InputMgr.h"

#include <iostream>
#include <list>
#include <algorithm>
#include <map>
#include "Bat.h"
#include "Ball.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Pong");
    

    InputMgr::Init();

    sf::Clock clock;

    Bat bat;
    Ball ball(bat, { {0.f , 0.f}, {1920.f , 1080.f} });

    bool isBallActive = false; // true 이면 bat 붙어있음

    while (window.isOpen())
    {
        sf::Time deltatime = clock.restart();
        float dt = deltatime.asSeconds();
        InputMgr::Clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            InputMgr::UpdateEvent(event);
        }
        InputMgr::Update(dt);

        if (!isBallActive && InputMgr::GetKeyDown(sf::Keyboard::Space))
        {
            ball.Fire({0.8f , -1.f} , 1000.f); // 방향, speed
            isBallActive = true;
        }

        bat.Update(dt);

        if (!isBallActive)
        {
            ball._shape.setPosition(bat._shape.getPosition());
        }

        ball.Update(dt);

       
        if (ball.isDead)
        {
            isBallActive = true;
            ball.Fire({0.f , 0.f} , 0.f);
            // 죽으면 게임 리셋
        }
        else if (ball.isBoundBat)
        {
            // 점수 추가

        }

        window.clear();
        bat.Draw(window);
        ball.Draw(window);

        window.display();
    }

    return 0;
}