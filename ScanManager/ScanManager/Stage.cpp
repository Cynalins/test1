#include "Stage.h"
#include "SceneManager.h"

Stage::Stage()
{

}

Stage::~Stage()
{

}

void Stage::Start()
{
	cout << "Stage" << endl;
}

void Stage::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(EXITID);
}

void Stage::Render()
{

}

void Stage::Release()
{

}

