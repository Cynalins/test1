#include "Logo.h"
#include "SceneManager.h"
#include "CursorManager.h"

Logo::Logo()
{

}

Logo::~Logo()
{
	Release();
}

void Logo::Start()
{
	cout << "Logo" << endl;
}

void Logo::Update()
{
	if (GetAsyncKeyState(VK_RETURN))
		SceneManager::GetInstance()->SetScene(MenuID);
}

void Logo::Render()
{
#ifdef DEBUG
	CursorManager::Renderer(0, 0, "X : ");
	CursorManager::Renderer(4, 0, Info.Position.x);
	CursorManager::Renderer(0, 1, "Y : ");
	CursorManager::Renderer(4, 1, Info.Position.y);

#endif 
	CursorManager::Renderer(Info.Position.x, Info.Position.y + 0)
}

void Logo::Release()
{

}

