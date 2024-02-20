#include "pch.h"
#include "SceneMgr.h"
#include "poong.h"

SceneMgr::~SceneMgr()
{
	Release();
}

void SceneMgr::Init()
{
	Release();

	scenes.push_back(new poong(SceneIds::SCENE_Pong));
	
	for (auto scene : scenes)
	{
		scene->Init();
	}

	currentScene = startScene;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Release()
{
	for (auto scene : scenes)
	{
		//scene->Release();
		delete scene;
	}
	scenes.clear();
}

void SceneMgr::ChangeScene(SceneIds id)
{

	scenes[(int)currentScene]->Exit();
	currentScene = id;
	scenes[(int)currentScene]->Enter();
}

void SceneMgr::Update(float dt)
{
	scenes[(int)currentScene]->Update(dt);
}

void SceneMgr::Draw(sf::RenderWindow& window)
{
	scenes[(int)currentScene]->Draw(window);
}
