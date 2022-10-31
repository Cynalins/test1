#include "Child.h"

Child::Child()
{
	cout << "Child 持失切" << endl;
}

Child::~Child()
{
	cout << "Child 社瑚切" << endl;
}

void Child::Start()
{
	Info.Position = Vector3(0.0f, 0.0f, 0.0f);
	Info.Rotation = Vector3(0.0f, 0.0f, 0.0f);
	Info.Scale = Vector3(0.0f, 0.0f, 0.0f);
}

void Child::Update()
{

}

void Child::Render()
{
	cout << Info.Position.x << endl
		<< Info.Position.y << endl
		<< Info.Position.z << endl;
}


void Child::Release()
{

}

