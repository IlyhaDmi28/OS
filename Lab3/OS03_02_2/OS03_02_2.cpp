#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	cout << "OS03_02_2" << endl;

	for (short i = 0; i < 125; i++)
	{
		cout << "PID: " << GetCurrentProcessId() << endl;
		Sleep(1000);
	}

	system("pause");
	return 0;
}