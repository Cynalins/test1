#include "Menu.h"
#include "SceneManager.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::Start()
{
	cout << "Menu" << endl;
}

void Menu::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(STAGEID);
}

void Menu::Render()
{

}

void Menu::Release()
{

}

