#pragma once
#include "Headers.h"

class Object;

class MainUpdate
{
private:
	Object* ObjectList[2];
public:
	void Initailize();

	void Progress();

	void Render();

	void Release();

public:
	MainUpdate();
	~MainUpdate();
};

