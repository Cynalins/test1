#pragma once
#include "Headers.h"

class Object;
class ObjectManager
{
private:
	static ObjectManager* Instance;
public:
	static ObjectManager* GetInstance()
	{
		if (Instance == nullptr)
			Instance = new ObjectManager();
		return Instance;
	}
private:
	Object* Player;
public:
	void SetPlayer(Object* _Player) { Player = _Player; }
	Object* GetPlayer() { return Player; }



private:
	ObjectManager();
public:
	~ObjectManager();
};

