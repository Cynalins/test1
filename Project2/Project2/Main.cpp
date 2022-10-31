/*
* 복습
*/

#include "Headers.h"

SceneID sceneState = SceneID::LOGO;

Object* CreateObject(int _x, int _y, char* _texture);
void SetScene(Object* _player, Object* _enemy);
void SetCursorPosition(int _x, int _y);
void InputKey(Object* _object);
bool Crash(Object* _player, Object* _enemy);
void LogoPress();
void LogoRender(char* _texture[], int _size, int _x, int _y);
void MenuPress();
void MenuRender(char* _texture[], int _size, int _x, int _y);
void StagePress(Object* _player, Object* _enemy);
void StageRender(Object* _player, Object* _enemy);
void ExitPress();

int main()
{
	// time이라는 변수에 프로그램이 시작되었을때부터 0.001초의 주기로 올라감/.(초기화)
	ULONGLONG time = GetTickCount64();

	// 플레이어 정보 초기화.
	Object* pPlayer = CreateObject(int(120 >> 1), 20, (char*)"△");
	
	// 적 정보 초기화
	Object* pEnemy = CreateObject(int(120 >> 1 * 2), 20, (char*)"■");

	while (true)
	{
		// 무한 루프.
		if (time + 50 < GetTickCount64())
		{

			time = GetTickCount64();
			system("cls");

			SetScene(pPlayer, pEnemy);

		}
	}
	return 0;
}

// 오브젝트 생성 함수
Object* CreateObject(int _x, int _y, char* _texture)
{
	Object* pobj = (Object*)malloc(sizeof(Object));

	// 길이 초기화 (설정)
	pobj->Position.x = _x;
	pobj->Position.y = _y;

	// 텍스트 설정
	pobj->Texture = (char*)malloc(sizeof(strlen(_texture) + 1));
	
	// 문자열 복사
	strcpy(pobj->Texture, _texture);

	// 스케일 초기화(지정)
	pobj->Scale = Vector2((int)strlen(pobj->Texture), 1);

	return pobj;
}

// 씬 입력
void SetScene(Object* _player, Object* _enemy)
{
	switch (sceneState)
	{
	case SceneID::LOGO:
	{
		static char* TexLogo[23] = {
			(char*)"LLLLLLLLLLL",
			(char*)"L:::::::::L",
			(char*)"L:::::::::L",
			(char*)"LL:::::::LL",
			(char*)"  L:::::L                  ooooooooooo      ggggggggg   ggggg   ooooooooooo",
			(char*)"  L:::::L                oo:::::::::::oo   g:::::::::ggg::::g oo:::::::::::oo",
			(char*)"  L:::::L               o:::::::::::::::o g:::::::::::::::::go:::::::::::::::o",
			(char*)"  L:::::L               o:::::ooooo:::::og::::::ggggg::::::ggo:::::ooooo:::::o",
			(char*)"  L:::::L               o::::o     o::::og:::::g     g:::::g o::::o     o::::o",
			(char*)"  L:::::L               o::::o     o::::og:::::g     g:::::g o::::o     o::::o",
			(char*)"  L:::::L               o::::o     o::::og:::::g     g:::::g o::::o     o::::o",
			(char*)"  L:::::L         LLLLLLo::::o     o::::og::::::g    g:::::g o::::o     o::::o",
			(char*)"LL:::::::LLLLLLLLL:::::Lo:::::ooooo:::::og:::::::ggggg:::::g o:::::ooooo:::::o",
			(char*)"L::::::::::::::::::::::Lo:::::::::::::::o g::::::::::::::::g o:::::::::::::::o",
			(char*)"L::::::::::::::::::::::L oo:::::::::::oo   gg::::::::::::::g  oo:::::::::::oo ",
			(char*)"LLLLLLLLLLLLLLLLLLLLLLLL   ooooooooooo       gggggggg::::::g    ooooooooooo",
			(char*)"                                                     g:::::g",
			(char*)"                                         gggggg      g:::::g",
			(char*)"                                         g:::::gg   gg:::::g",
			(char*)"                                          g::::::ggg:::::::g",
			(char*)"                                           gg:::::::::::::g",
			(char*)"                                             ggg::::::ggg",
			(char*)"                                                gggggg" };
		LogoPress();
		LogoRender(TexLogo, 23, 20, 10);
		break;
	}

	case SceneID::MENU:
	{
		static char* TexMenu[16] = {
			(char*)"MMMMMMMM               MMMMMMMM",
			(char*)"M:::::::M             M:::::::M",
			(char*)"M::::::::M           M::::::::M",
			(char*)"M:::::::::M         M:::::::::M",
			(char*)"M::::::::::M       M::::::::::M    eeeeeeeeeeee    nnnn  nnnnnnnn    uuuuuu    uuuuuu",
			(char*)"M:::::::::::M     M:::::::::::M  ee::::::::::::ee  n:::nn::::::::nn  u::::u    u::::u",
			(char*)"M:::::::M::::M   M::::M:::::::M e::::::eeeee:::::een::::::::::::::nn u::::u    u::::u",
			(char*)"M::::::M M::::M M::::M M::::::Me::::::e     e:::::enn:::::::::::::::nu::::u    u::::u",
			(char*)"M::::::M  M::::M::::M  M::::::Me:::::::eeeee::::::e  n:::::nnnn:::::nu::::u    u::::u",
			(char*)"M::::::M   M:::::::M   M::::::Me:::::::::::::::::e   n::::n    n::::nu::::u    u::::u",
			(char*)"M::::::M    M:::::M    M::::::Me::::::eeeeeeeeeee    n::::n    n::::nu::::u    u::::u",
			(char*)"M::::::M     MMMMM     M::::::Me:::::::e             n::::n    n::::nu:::::uuuu:::::u",
			(char*)"M::::::M               M::::::Me::::::::e            n::::n    n::::nu:::::::::::::::uu",
			(char*)"M::::::M               M::::::M e::::::::eeeeeeee    n::::n    n::::n u:::::::::::::::u",
			(char*)"M::::::M               M::::::M  ee:::::::::::::e    n::::n    n::::n  uu::::::::uu:::u",
			(char*)"MMMMMMMM               MMMMMMMM    eeeeeeeeeeeeee    nnnnnn    nnnnnn    uuuuuuuu  uuuu"};
		MenuPress();
		MenuRender(TexMenu, 16, 20, 10);
		break;
	}

	case SceneID::STAGE:
		StagePress(_player, _enemy);
		StageRender(_player, _enemy);
		break;

	case SceneID::EXIT:
		exit(NULL);
		break;

	}


}

// 위치를 알려주는 함수.
void SetCursorPosition(int _x, int _y)
{
	COORD pos = { (SHORT)_x, (SHORT)_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// 키입력
void InputKey(Object* _object)
{
	if (GetAsyncKeyState(VK_UP))
	{
		if (_object->Position.y > 0)
			_object->Position.y--;
		
		_object->Texture = (char*)"△";
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		if (_object->Position.y < 40)
			_object->Position.y++;

		_object->Texture = (char*)"▽";
	}

	if (GetAsyncKeyState(VK_LEFT))
	{
		if (_object->Position.x > 0)
			_object->Position.x--;

		_object->Texture = (char*)"◁";
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (_object->Position.x < 120)
			_object->Position.x++;

		_object->Texture = (char*)"▷";
	}
}

// 충돌판정
bool Crash(Object* _player, Object* _enemy)
{
	if (_player->Position.x + _player->Scale.x > _enemy->Position.x &&
		_enemy->Position.x + _enemy->Scale.x > _player->Position.x &&
		_player->Position.y == _enemy->Position.y)
	{
		return true;
	}
	return false;
}

void LogoPress()
{
	if (GetAsyncKeyState(VK_RETURN))
	{
		sceneState = SceneID::MENU;
	}
}

void LogoRender(char* _texture[], int _size, int _x, int _y)
{
	for (int i = 0; i < _size; ++i)
	{
		SetCursorPosition(_x, _y + i);
		printf("%s", _texture[i]);
	}
}

void MenuPress()
{
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		sceneState = SceneID::STAGE;
	}
}

void MenuRender(char* _texture[], int _size, int _x, int _y)
{
	for (int i = 0; i < _size; ++i)
	{
		SetCursorPosition(_x, _y + i);
		printf("%s", _texture[i]);
	}

}

void StagePress(Object* _player, Object* _enemy)
{
	InputKey(_player);

	if (Crash(_player, _enemy))
	{
		SetCursorPosition(int(120 >> 1), 1);
		printf("충돌입니다.");
	}
	if (GetAsyncKeyState('Q'))
	{
		sceneState = SceneID::EXIT;
	}
}

void StageRender(Object* _player, Object* _enemy)
{
	SetCursorPosition(_player->Position.x, _player->Position.y);
	printf("%s", _player->Texture);

	SetCursorPosition(_enemy->Position.x, _enemy->Position.y);
	printf("%s", _enemy->Texture);
}

void ExitPress()
{
	exit(NULL);
}
