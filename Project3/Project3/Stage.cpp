#include "Stage.h"
#include "SceneManager.h"

Stage::Stage()
{

}

Stage::~Stage()
{
	Release();
}

void Stage::Start()
{

}

void Stage::Update()
{
	cout << "Stage" << endl;
}

void Stage::Render()
{
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(ExitID);
}

void Stage::Release()
{

}

