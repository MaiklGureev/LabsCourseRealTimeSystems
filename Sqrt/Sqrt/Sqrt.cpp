// Sqrt.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;
HANDLE hEvent1, hEvent4;
double result;

double m_sqrt(double v)
{
	return sqrt(v);
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "RUSSIAN");
	hEvent1 = CreateEvent(NULL, FALSE, NULL, _T("Global\\hEvent1.txt"));
	hEvent4 = CreateEvent(NULL, FALSE, NULL, _T("Global\\hEvent4.txt"));
	while (1)
	{
		printf("\n Wait... \n");
		WaitForSingleObject(hEvent4, INFINITE);
		printf("\nЗапуск процесса SQRT\n");
		HANDLE hFile;
		DWORD dw = 0;
		hFile = CreateFileA("C:\\Users\\Mikhail\\Documents\\Visual Studio 2010\\Projects\\SRV_L3\\info2.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, NULL, NULL);
		double v1;
		ReadFile(hFile, &v1, sizeof(double), 0, NULL);
		CloseHandle(hFile);
		printf("Выполнение...\n");
		result = m_sqrt(v1);
		printf("Результат: ");
		cout << result << endl;

		hFile = CreateFileA("C:\\Users\\Mikhail\\Documents\\Visual Studio 2010\\Projects\\SRV_L3\\info2.txt", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		WriteFile(hFile, &result, sizeof(double), &dw, NULL);
		CloseHandle(hFile);
		hEvent4 = CreateEvent(NULL, FALSE, FALSE, _T("Global\\hEvent4.txt"));
		SetEvent(hEvent1);
	}
	system("pause");
	return 0;
}