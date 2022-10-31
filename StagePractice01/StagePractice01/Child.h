#pragma once
#include "Object.h"

class Child : public Object
{
public:
	void Start()override;
	void Update()override;
	void Render()override;
	void Release()override;
public:
	Child();
	virtual ~Child();
};

