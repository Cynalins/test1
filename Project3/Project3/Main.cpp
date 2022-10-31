#include "Headers.h"
#include "MainUpdate.h"

int main()
{
	MainUpdate Main;

	Main.Start();

	ULONGLONG Time = GetTickCount64();

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