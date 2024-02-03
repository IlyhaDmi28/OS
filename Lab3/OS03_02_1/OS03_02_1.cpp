#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	cout << "OS03_02_1" << endl;

	for (short i = 1; i < 50; i++)
	{
		cout << "PID: " << GetCurrentProcessId() << endl;
		Sleep(1000);
	}

	system("pause");
	return 0;
}
