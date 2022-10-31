#include "Headers.h"
#include "Child.h"
#include "MainUpdate.h"

void SetColor(int _color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), _color);
}

int main()
{
	SetColor(4);
	cout << "Hello ";

	SetColor(6);
	cout << "World!!" << endl;

	SetColor(15);

	ULONGLONG Time = GetTickCount64();

	MainUpdate Main;
	Main.Start();

	while (true)
	{
		if (Time < GetTickCount64())
		{
			Time = GetTickCount64();

			Main.Update();
			Main.Render();
		}
	}

	return 0;
}