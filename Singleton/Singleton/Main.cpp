#include "MainUpdate.h"

int main()
{
	MainUpdate Main;
	Main.Initailize();

	ULONGLONG time = GetTickCount64();

	while (true)
	{
		if (time < GetTickCount64())
		{
			time = GetTickCount64();

			Main.Progress();
			Main.Render();

			if (GetAsyncKeyState('Q'))
				break;
		}
	}



	return 0;
}