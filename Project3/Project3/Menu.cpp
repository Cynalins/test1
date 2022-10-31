#include "Menu.h"
#include "SceneManager.h"

Menu::Menu()
{

}

Menu::~Menu()
{
	Release();
}

void Menu::Start()
{

}

void Menu::Update()
{
	cout << "Menu" << endl;
}

void Menu::Render()
{
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(StageID);
}

void Menu::Release()
{

}

