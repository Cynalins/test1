#include <stdio.h>
#include <Windows.h>

// ** const

// ** 상수화 
//const int NUMBER = 10;

// ** 충돌처리.
// ** 생성자 & 복사생성자.





// ** 장면 관리 (scene 전환)
// ** 생성 함수.
// ** 함수 정리.





struct Vector2
{
	int x, y;

	Vector2() : x(0), y(0)
	{

	}

	Vector2(int _x, int _y) : x(_x), y(_y)
	{

	}
};

struct Object
{
	Vector2 Position;
	Vector2 Scale;
	char* Texture;
};

bool Horzontal = false;
bool Vertical = false;

void SetCursorPosition(int _x, int _y);
void ShowCursor(bool _b);
void InputKey(Object* _Object);

int main(void)
{
	ShowCursor(false);

	ULONGLONG Time = GetTickCount64();

	bool gameFlag = false;

	int count = 0;

	// ** 플레이어 초기화
	Object Player;
	Player.Position = Vector2(int(120 * 0.3333f), 40 >> 1);
	Player.Texture = (char*)"△";
	Player.Scale = Vector2((int)strlen(Player.Texture), 1);

	//Player.Position.x = int(120 * 0.3333f);
	//Player.Position.y = 40>>1;

	// ** Texture 길이를 미리 확인할 수 없다. 
	// ** Texture 를 먼저 초기화 하고 이후에 사이즈를 아래와 같이 초기화 한다.
	//Player.Scale.x = (int)strlen(Player.Texture);
	//Player.Scale.y = 1;

	// ** Enemy 초기화
	Object Enemy[128];
	bool ShowEnemy[128];
	ULONGLONG EnemyDelay = GetTickCount64();
	
	for (int i = 0; i < 128; ++i)
	{
		Enemy[i].Position = Vector2(int(120 * 0.3333f * 2), 40 >> 1);
		Enemy[i].Texture = (char*)"■";
		Enemy[i].Scale = Vector2((int)strlen(Enemy[i].Texture), 1);

		ShowEnemy[i] = false;
	}
	

	//Enemy.Position.x = int(120 * 0.3333f * 2);
	//Enemy.Position.y = 40>>1;

	//Enemy.Scale.x = (int)strlen(Enemy.Texture);
	//Enemy.Scale.y = 1;


	while (true)
	{
		if (Time + 50 < GetTickCount64())
		{
			Time = GetTickCount64();

			system("cls");

			// **  ===== Progress ===== 
			InputKey(&Player);


			// ** ===== Render ===== 

			// ** Player
			SetCursorPosition(
				Player.Position.x,
				Player.Position.y);

			printf("%s", Player.Texture);

			for (int i = 0; i < 128; ++i)
			{
				if (EnemyDelay < GetTickCount64())
				{
					if (!ShowEnemy[i])
					{
						Enemy[i].Position.x = 118;
						Enemy[i].Position.y = rand() % 40;

						ShowEnemy[i] = true;

						EnemyDelay = GetTickCount64();

						break;
					}
				}			
			}
			for (int i = 0; i < 128; ++i)
			{
				if (ShowEnemy[i])
				{
					Enemy[i].Position.x--;

					if (Enemy[i].Position.x <= 0)
					{
						ShowEnemy[i] = false;
						continue;
					}

					if (Player.Position.x + 2 > Enemy[i].Position.x &&
						Enemy[i].Position.x + 1 > Player.Position.x &&
						Player.Position.y == Enemy[i].Position.y)
					{
					
						gameFlag = true;
						break;
					}

					SetCursorPosition(Enemy[i].Position.x, Enemy[i].Position.y);
					printf("%s", Enemy[i].Texture);
				}
			}
			count++;
			SetCursorPosition(1, 1);
			printf("점수 : %d", count);
			if (gameFlag)
			{
				
				system("cls");
				SetCursorPosition(120 >> 1, 19);
				printf("★ 점수 : %d\n", count);
				SetCursorPosition((120 >> 1) - 4, 20);
				printf("★ 충돌하였습니다. ★\n\n\n\n\n\n");
				
				break;
			}
			
		}
	}

	return 0;
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