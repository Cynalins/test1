#pragma once
#include "Headers.h"

class CursorManager
{
public:
	static void Renderer(float _x, float _y, string _str)
	{
		COORD pos = { (SHORT)_x, (SHORT)_y };

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		cout << _str;
	}

	static void Renderer(float _x, float _y, int _value)
	{
		COORD pos = { (SHORT)_x, (SHORT)_y };
		
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		cout << _value;
	}

private:
	CursorManager() {};
public:
	~CursorManager() {};

};
