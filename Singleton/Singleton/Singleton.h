#pragma once
#include "Player.h"
#include "Enemy.h"

class Object;
class SingletonManager
{
private:
	static SingletonManager* Instance; // ����(�޸� ����) <- ���� ������ �̸� �ö�����.
public:
	static SingletonManager* GetInstance()
	{
		if (Instance == nullptr) // <- ó�� ������ nullptr�̹Ƿ� �� ������ ���� �� Instance�� ��ȯ����. - �ι�°���ʹ� �ƴϹǷ� �׳� �Ѿ.
			Instance = new SingletonManager;
		return Instance;
	}
public:
	Object* CreatePlayer() { return new Player; }
	Object* CreateEnemy() { return new Enemy; }
private:
	SingletonManager(){}
};

SingletonManager* SingletonManager::Instance = nullptr; // <- Instance�� nullptr�� �ʱ�ȭ ������