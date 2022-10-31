#pragma once
#include "Scene.h"

class Menu : public Scene
{
public:
	void Start()override;
	void Update()override;
	void Render()override;
	void Release()override;
public:
	Menu();
	~Menu();
};

