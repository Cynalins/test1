#include "MainUpdate.h"
#include "SceneManager.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{
	Release();
}

void MainUpdate::Start()
{
	SceneManager::GetInstance()->SetScene(LogoID);
}

void MainUpdate::Update()
{
	SceneManager::GetInstance()->Update();
}

void MainUpdate::Render()
{
	SceneManager::GetInstance()->Render();
}

void MainUpdate::Release()
{

}

