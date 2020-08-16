// ADD.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;
HANDLE hEvent1, hEvent3;
double result;

double add(double a, double b)
{
	return (double)a + (double)b;
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "RUSSIAN");
	hEvent1 = CreateEvent(NULL, FALSE, NULL, _T("Global\\hEvent1.txt"));
	hEvent3 = CreateEvent(NULL, FALSE, NULL, _T("Global\\hEvent3.txt"));
	while (1)
	{
		printf("\n Wait... \n");
		WaitForSingleObject(hEvent3, INFINITE);
		printf("\nЗапуск процесса ADD\n");
		HANDLE hFile;
		DWORD dw = 0;
		hFile = CreateFileA("C:\\Users\\Mikhail\\Documents\\Visual Studio 2010\\Projects\\SRV_L3\\info.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, NULL, NULL);
		double a, b;
		ReadFile(hFile, &a, sizeof(double), 0, NULL);
		ReadFile(hFile, &b, sizeof(double), 0, NULL);
		CloseHandle(hFile);
		printf("Выполнение...\n");
		result = add(a, b);
		printf("Результат: ");
		cout << result << endl;
		

		hFile = CreateFileA("C:\\Users\\Mikhail\\Documents\\Visual Studio 2010\\Projects\\SRV_L3\\info2.txt", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		WriteFile(hFile, &result, sizeof(double), &dw, NULL);
		CloseHandle(hFile);
		hEvent3 = CreateEvent(NULL, FALSE, FALSE, _T("Global\\hEvent3.txt"));
		SetEvent(hEvent1);
	}
	system("pause");
	return 0;
}

