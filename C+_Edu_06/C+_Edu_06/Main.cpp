#include "Headers.h"


// ** 장면 관리 (scene 전환)

// ** 생성 함수.
// ** 함수 정리.
// 키 입력 함수 수정.


// ** 장면전환을 하기위한 변수
// ** 현재 장면을 보관한다.
SceneID SceneState = SceneID::LOGO;

void SetScene(Object* _pPlayer, Object* _pEnemy);
Object* CreateObject(int _x, int _y, char* _Texture);
void SetCursorPosition(int _x, int _y);
void ShowCursor(bool _b);
void InputKey(Object* _Object);
//void Render(char* _str, int _x, int _y);

void LogoProgress();
// ** 보내는게 배열일 경우에는 무조건 사이즈를 같이 입력해 주어야한다.
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

	// ** 플레이어 초기화
	Object* pPlayer = CreateObject(int(120 * 0.3333f), 40 >> 1, (char*)"△");

	// ** Enemy 초기화
	Object* pEnemy = CreateObject(int(120 * 0.3333f * 2), 40 >> 1, (char*)"■");

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


// ** 오브젝트 생성 함수.
// 포인터를 배열로 보낼경우에는 size를 같이 줘야한다.
Object* CreateObject(int _x, int _y, char* _Texture)
{
	// 동적과 정적의 정의 -> 런타임 이전 정적, 런타임 이후 동적
	// 정적일 경우 데이터가 올라가는게 아니라 주소가 올라가는 것이다.
	// ** 동적데이터는 가르키는 주소가 바뀌기도 한다.
	// ** Object를 동적으로 생성한다.
	Object* pObj = (Object*)malloc(sizeof(Object));

	// ** 좌표를 셋팅
	pObj->Position.x = _x;
	pObj->Position.y = _y;

	// ** 동적 할당을 해준다. 동적할당을 할때 문자열의 크기 + 1만큼의 크기로 해준다.
	pObj->Texture = (char*)malloc(strlen(_Texture) + 1);
	// ** 문자열을 복사한다.
	strcpy(pObj->Texture, _Texture);

	// ** 문자열의 길이로 크기를 정한다.
	pObj->Scale = Vector2((int)strlen(pObj->Texture), 1);

	// ** 모든 셋팅이 완료되었다면.
	// ** 동적으로 생성된 Object 의 주소를 반환한다.
	return pObj;
}

// ** 커서의 위치를 이동시킨다.
void SetCursorPosition(int _x, int _y)
{
	// ** 좌표를 설정.
	COORD pos = { (SHORT)_x, (SHORT)_y };

	// ** 설정한 좌표로 이동시키는 함수.
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// ** GetStdHandle(STD_OUTPUT_HANDLE) = 현재 콘솔창의 핸들.
	// ** HANDLE : 윈도우 창의 기본 설정값을 셋팅할 수 있음.
}

// ** 커서를 보이게/안보이게 하는 함수.
// ** true 보이게, false 안보이게.
void ShowCursor(bool _b)
{
	// ** 커서의 기본정보를 생성한다.
	CONSOLE_CURSOR_INFO Info;

	// ** 커서의 기본정보를 셋팅한다.
	// ** 커서를 보이게/안보이게 한다.
	Info.bVisible = _b;

	// ** 커서의 크기를 설정한다.
	Info.dwSize = 1;

	// ** 커서의 설정을 적용시키는 함수.
	SetConsoleCursorInfo(
		GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// ** 플레이어의 키 입력을 받고, 입력에 따라 Texture 를 변경 한다.
void InputKey(Object* _Object)
{
	bool Horzontal = false;
	bool Vertical = false;

	if (GetAsyncKeyState(VK_UP) && !Horzontal)
	{
		if (_Object->Position.y > 0)
			_Object->Position.y--;

		_Object->Texture = (char*)"△";
		Vertical = true;
	}
	else
		Vertical = false;

	if (GetAsyncKeyState(VK_DOWN) && !Horzontal)
	{
		if (_Object->Position.y < 39)
			_Object->Position.y++;

		_Object->Texture = (char*)"▽";
		Vertical = true;
	}
	else
		Vertical = false;

	if (GetAsyncKeyState(VK_LEFT) && !Vertical)
	{
		if (_Object->Position.x > 0)
			_Object->Position.x--;

		_Object->Texture = (char*)"◁";
		Horzontal = true;
	}
	else
		Horzontal = false;

	if (GetAsyncKeyState(VK_RIGHT) && !Vertical)
	{
		if (_Object->Position.x < 118)
			_Object->Position.x++;

		_Object->Texture = (char*)"▷";
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
		printf("충돌입니다.");
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
	// ** 충돌
	if (_Temp->Position.x + 2 > _Dest->Position.x &&
		_Dest->Position.x + 2 > _Temp->Position.x &&
		_Temp->Position.y == _Dest->Position.y)
	{
		return true;
	}
	return false;
}