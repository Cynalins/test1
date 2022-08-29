#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

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
	Vector2 position;
	Vector2 scale;
	char* texture;
};

void SetCursorPosition(int _x, int _y);
void PlayerPosition(Object* _player);

int main()
{
	ULONGLONG time = GetTickCount64();

	Object player;
	player.position = Vector2(1, 1);
	player.texture = (char*)"¡â";
	player.scale = Vector2((int)strlen(player.texture), 1);

	Object enemy;
	srand(GetTickCount64() * GetTickCount64());
	enemy.position = Vector2(118, rand() % 40);
	enemy.texture = (char*)"¡Ú";
	enemy.scale = Vector2((int)strlen(enemy.texture), 1);


	while (true)
	{
		if (time + 50 < GetTickCount64())
		{

			time = GetTickCount64();
			system("cls");

			PlayerPosition(&player);

			SetCursorPosition(player.position.x, player.position.y);
			printf("%s", player.texture);

		}
	}
	
	

	return 0;
}

void SetCursorPosition(int _x, int _y)
{
	COORD pos = { (SHORT)_x, (SHORT)_y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void PlayerPosition(Object* _player)
{
	if (GetAsyncKeyState(VK_UP))
	{
		if (_player->position.y > 0)
		{
			_player->position.y--;
		}	
	}
	if (GetAsyncKeyState(VK_DOWN))
	{
		if (_player->position.y > 0)
		{
			_player->position.y++;
		}
	}
	if (GetAsyncKeyState(VK_LEFT))
	{
		if (_player->position.x > 0)
		{
			_player->position.x--;
		}
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		if (_player->position.x > 0)
		{
			_player->position.x++;
		}
	}
}



