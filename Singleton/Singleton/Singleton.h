#pragma once
#include "Player.h"
#include "Enemy.h"

class Object;
class SingletonManager
{
private:
	static SingletonManager* Instance; // 변수(메모리 변수) <- 정적 데이터 미리 올라가있음.
public:
	static SingletonManager* GetInstance()
	{
		if (Instance == nullptr) // <- 처음 들어갈때는 nullptr이므로 새 공간을 만든 후 Instance를 반환해줌. - 두번째부터는 아니므로 그냥 넘어감.
			Instance = new SingletonManager;
		return Instance;
	}
public:
	Object* CreatePlayer() { return new Player; }
	Object* CreateEnemy() { return new Enemy; }
private:
	SingletonManager(){}
};

SingletonManager* SingletonManager::Instance = nullptr; // <- Instance를 nullptr로 초기화 시켜줌