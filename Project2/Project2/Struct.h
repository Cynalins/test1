#pragma once

struct Vector2
{
	int x, y;

	// 持失切
	Vector2() : x(0), y(0)
	{
	
	}

	// 差紫 持失切
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