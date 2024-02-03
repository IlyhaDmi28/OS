#include <iostream>
#include <Windows.h>

using namespace std;


int main()
{
	DWORD pid = GetCurrentProcessId();
	DWORD tid = GetCurrentThreadId();

	for (short i = 1; i <= 100; ++i)
	{
		cout << i << ". PID = " << pid << "\t\tTID = " << tid << "\n";
		Sleep(1000);
	}

	system("pause");
	return 0;
}