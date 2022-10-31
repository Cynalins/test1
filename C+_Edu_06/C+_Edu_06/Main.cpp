#include "Headers.h"


// ** ��� ���� (scene ��ȯ)

// ** ���� �Լ�.
// ** �Լ� ����.
// Ű �Է� �Լ� ����.


// ** �����ȯ�� �ϱ����� ����
// ** ���� ����� �����Ѵ�.
SceneID SceneState = SceneID::LOGO;

void SetScene(Object* _pPlayer, Object* _pEnemy);
Object* CreateObject(int _x, int _y, char* _Texture);
void SetCursorPosition(int _x, int _y);
void ShowCursor(bool _b);
void InputKey(Object* _Object);
//void Render(char* _str, int _x, int _y);

void LogoProgress();
// ** �����°� �迭�� ��쿡�� ������ ����� ���� �Է��� �־���Ѵ�.
void LogoRender(char* _str, int _x, int _y);

void MenuProgress();
void MenuRender(char* _str, int _x, int _y);

void StageProgress(Object* _player, Object* _Enemy);
void StageRender(Object* _player, Object* _Enemy);

bool Collision(Object* _Temp, Object* _Dest);



int main(void)
{
	ShowCursor(false);

	ULONGLONG Time = GetTickCount64(); 

	// ** �÷��̾� �ʱ�ȭ
	Object* pPlayer = CreateObject(int(120 * 0.3333f), 40 >> 1, (char*)"��");

	// ** Enemy �ʱ�ȭ
	Object* pEnemy = CreateObject(int(120 * 0.3333f * 2), 40 >> 1, (char*)"��");

	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			SetScene(pPlayer, pEnemy);
		}
	}

	return 0;
}


void SetScene(Object* _pPlayer, Object* _pEnemy)
{
	switch (SceneState)
	{
	case SceneID::LOGO:
		Render((char*)"LOGO", 58, 20);
		if (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_ESCAPE))
			SceneState = SceneID::MENU;
		break;
	case SceneID::MENU:
		Render((char*)"MENU", 58, 20);

		if (GetAsyncKeyState('S'))
			SceneState = SceneID::STAGE;
		break;
	case SceneID::STAGE:
		// ** ===== Progress ===== 
		InputKey(_pPlayer);

		// ** =====  Render  ===== 
		// ** Player
		Render(_pPlayer->Texture,
			_pPlayer->Position.x,
			_pPlayer->Position.y);

		// ** Enemy
		Render(_pEnemy->Texture,
			_pEnemy->Position.x,
			_pEnemy->Position.y);

		

		if (GetAsyncKeyState('Q'))
			SceneState = SceneID::EXIT;
		break;
	case SceneID::EXIT:
		exit(NULL);
		break;
	}
}


// ** ������Ʈ ���� �Լ�.
// �����͸� �迭�� ������쿡�� size�� ���� ����Ѵ�.
Object* CreateObject(int _x, int _y, char* _Texture)
{
	// ������ ������ ���� -> ��Ÿ�� ���� ����, ��Ÿ�� ���� ����
	// ������ ��� �����Ͱ� �ö󰡴°� �ƴ϶� �ּҰ� �ö󰡴� ���̴�.
	// ** ���������ʹ� ����Ű�� �ּҰ� �ٲ�⵵ �Ѵ�.
	// ** Object�� �������� �����Ѵ�.
	Object* pObj = (Object*)malloc(sizeof(Object));

	// ** ��ǥ�� ����
	pObj->Position.x = _x;
	pObj->Position.y = _y;

	// ** ���� �Ҵ��� ���ش�. �����Ҵ��� �Ҷ� ���ڿ��� ũ�� + 1��ŭ�� ũ��� ���ش�.
	pObj->Texture = (char*)malloc(strlen(_Texture) + 1);
	// ** ���ڿ��� �����Ѵ�.
	strcpy(pObj->Texture, _Texture);

	// ** ���ڿ��� ���̷� ũ�⸦ ���Ѵ�.
	pObj->Scale = Vector2((int)strlen(pObj->Texture), 1);

	// ** ��� ������ �Ϸ�Ǿ��ٸ�.
	// ** �������� ������ Object �� �ּҸ� ��ȯ�Ѵ�.
	return pObj;
}

// ** Ŀ���� ��ġ�� �̵���Ų��.
void SetCursorPosition(int _x, int _y)
{
	// ** ��ǥ�� ����.
	COORD pos = { (SHORT)_x, (SHORT)_y };

	// ** ������ ��ǥ�� �̵���Ű�� �Լ�.
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// ** GetStdHandle(STD_OUTPUT_HANDLE) = ���� �ܼ�â�� �ڵ�.
	// ** HANDLE : ������ â�� �⺻ �������� ������ �� ����.
}

// ** Ŀ���� ���̰�/�Ⱥ��̰� �ϴ� �Լ�.
// ** true ���̰�, false �Ⱥ��̰�.
void ShowCursor(bool _b)
{
	// ** Ŀ���� �⺻������ �����Ѵ�.
	CONSOLE_CURSOR_INFO Info;

	// ** Ŀ���� �⺻������ �����Ѵ�.
	// ** Ŀ���� ���̰�/�Ⱥ��̰� �Ѵ�.
	Info.bVisible = _b;

	// ** Ŀ���� ũ�⸦ �����Ѵ�.
	Info.dwSize = 1;

	// ** Ŀ���� ������ �����Ű�� �Լ�.
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// ** �÷��̾��� Ű �Է��� �ް�, �Է¿� ���� Texture �� ���� �Ѵ�.
void InputKey(Object* _Object)
{
	bool Horzontal = false;
	bool Vertical = false;

	if (GetAsyncKeyState(VK_UP) && !Horzontal)
	{
		if (_Object->Position.y > 0)
			_Object->Position.y--;

		_Object->Texture = (char*)"��";
		Vertical = true;
	}
	else
		Vertical = false;

	if (GetAsyncKeyState(VK_DOWN) && !Horzontal)
	{
		if (_Object->Position.y < 39)
			_Object->Position.y++;

		_Object->Texture = (char*)"��";
		Vertical = true;
	}
	else
		Vertical = false;

	if (GetAsyncKeyState(VK_LEFT) && !Vertical)
	{
		if (_Object->Position.x > 0)
			_Object->Position.x--;

		_Object->Texture = (char*)"��";
		Horzontal = true;
	}
	else
		Horzontal = false;

	if (GetAsyncKeyState(VK_RIGHT) && !Vertical)
	{
		if (_Object->Position.x < 118)
			_Object->Position.x++;

		_Object->Texture = (char*)"��";
		Horzontal = true;
	}
	else
		Horzontal = false;
}
void LogoProgress()
{
	if (GetAsyncKeyState(VK_RETURN) || GetAsyncKeyState(VK_ESCAPE))
		SceneState = SceneID::MENU;
}

void LogoRender(char* _str, int _x, int _y)
{
	SetCursorPosition(_x, _y);
	printf("%s", _str);
}

void MenuProgress()
{
	
}

void MenuRender(char* _str, int _x, int _y)
{
	SetCursorPosition(_x, _y);
	printf("%s", _str);
}

void StageProgress(Object* _player, Object* _Enemy)
{
	InputKey(_player);

	if (Collision(_player, _Enemy))
	{
		SetCursorPosition(120>>1, 1);
		printf("�浹�Դϴ�.");
	}
}

void StageRender(Object* _player, Object* _Enemy)
{
	SetCursorPosition(_player->Position.x, _player->Position.y);
	printf("%s", _player->Texture);

	SetCursorPosition(_Enemy->Position.x, _Enemy->Position.y);
	printf("%s", _Enemy->Texture);
}

bool Collision(Object* _Temp, Object* _Dest)
{
	// ** �浹
	if (_Temp->Position.x + 2 > _Dest->Position.x &&
		_Dest->Position.x + 2 > _Temp->Position.x &&
		_Temp->Position.y == _Dest->Position.y)
	{
		return true;
	}
	return false;
}