#pragma once
#include "Headers.h"

class Object
{
private:

public:
	virtual void Initialize()PURE;

	virtual void Progress()PURE;

	virtual void Render()PURE;

	virtual void Release()PURE;
};

