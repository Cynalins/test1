#pragma once
#include "Scene.h"

class Logo : public Scene
{
private:
	Transform Info;
	int color;
	ULONGLONG Time;
	ULONGLONG DelayTime;
	int switching;
public:
	void Start()override;
	void Update()override;
	void Render()override;
	void Release()override;
public:
	Logo();
	~Logo();
};

