#include <iostream>
#include <Windows.h>
#include "TlHelp32.h"
#include <iomanip>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	DWORD pid = GetCurrentProcessId();
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, 0);	// делает снапшот текущих процессов системы
	// 1-ый параметр: флаг TH32CS_SNAPALL включает в снапшот все процессы и потоки системы, а также кучу и модули процесса th32ProcessID (второй параметр)
	// 2-ой параметр: PID процесса, включаемого в снапшот. 0 - текущий процесс
	PROCESSENTRY32 peProcessEntry;						// структура со списком процессов из снапшота
	peProcessEntry.dwSize = sizeof(PROCESSENTRY32);		// явное указание размера
	wcout << L"Текущий PID: " << pid << endl;

	try
	{
		// извлекает инфу о первом процессе снапшота. возвращает true, если первая 
		// запись снапшота списка процессов была скопирована в буфер, иначе false
		if (!Process32First(snapshot, &peProcessEntry))
			throw L"Process32First";
		do
		{
			if (peProcessEntry.th32ProcessID == pid)	// если один ин PID в снапшоте равен записанному PID текущего процесса
				wcout << "  ! Текущие запущеные процессы !" << endl;
			wcout << L"Имя\t\t" << peProcessEntry.szExeFile << endl;
			wcout << L"PID\t\t" << peProcessEntry.th32ProcessID << endl;
			wcout << L"PPID\t\t" << peProcessEntry.th32ParentProcessID << endl;
			wcout << L"--------------------------------------" << endl;

		} while (Process32Next(snapshot, &peProcessEntry));	// итератор по снапшоту
	}
	catch (char* err)
	{
		wcout << L"[ERROR] " << err;
	}

	system("pause");
	return 0;
}