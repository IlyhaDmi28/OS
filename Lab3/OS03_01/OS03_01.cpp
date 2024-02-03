#include <iostream>
#include <windows.h>
using namespace std;

int main() 
{
    while (true) 
    {
        cout << "PID: " << GetCurrentProcessId() << std::endl;
        Sleep(1000);
    }

    return 0;
}