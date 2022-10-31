#include "MainUpdate.h"
#include "SceneManager.h"

MainUpdate::MainUpdate()
{

}

MainUpdate::~MainUpdate()
{

}

void MainUpdate::Start()
{
	SceneManager::GetInstance()->SetScene(LOGOID);
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

