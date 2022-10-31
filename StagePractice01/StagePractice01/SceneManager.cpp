#include "SceneManager.h"

SceneManager* SceneManager::Instance = nullptr;

SceneManager::SceneManager() : SceneState(nullptr)
{

}

SceneManager::~SceneManager()
{
	Release();
}

void SceneManager::SetScene(SceneID _SceneID)
{

}

void SceneManager::Update()
{

}

void SceneManager::Render()
{

}

void SceneManager::Release()
{

}

