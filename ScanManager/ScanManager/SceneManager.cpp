#include "SceneManager.h"

#include "Logo.h"
#include "Menu.h"
#include "Stage.h"

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
	if (SceneState != nullptr)
	{
		delete SceneState;
		SceneState = nullptr;
	}

	switch (_SceneID)
	{
	case LOGOID:
		SceneState = new Logo;
		break;
	case MENUID:
		SceneState = new Menu;
		break;
	case EXITID:
		exit(NULL);
		break;
	}

	SceneState->Start();
}

void SceneManager::Update()
{
	SceneState->Update();
}

void SceneManager::Render()
{
	SceneState->Render();
}

void SceneManager::Release()
{

}

