#include "Logo.h"
#include "SceneManager.h"

Logo::Logo()
{

}

Logo::~Logo()
{

}

void Logo::Start()
{
	cout << "LOGO" << endl;
}

void Logo::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(MENUID);
}

void Logo::Render()
{

}

void Logo::Release()
{

}

