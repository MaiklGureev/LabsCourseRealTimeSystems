// Kvadrat.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h>
#include <stdio.h>
#include <iostream>
using namespace std;
HANDLE hEvent1, hEvent2;
double result1,result2;

double mul(double e)
{
	return (double)pow(e,2);
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "GHBDTN" << endl;
	setlocale(LC_ALL, "RUSSIAN");
	hEvent1 = CreateEvent(NULL, FALSE, NULL, _T("Global\\hEvent1.txt"));
	cout << "err=" << GetLastError() << endl;
	hEvent2 = CreateEvent(NULL, FALSE, NULL, _T("Global\\hEvent2.txt"));
	cout << "err=" << GetLastError() << endl;
	int err = GetLastError ();
	while (1)
	{
		

		printf("\n Wait... \n");
		WaitForSingleObject(hEvent2, INFINITE);
		printf("\nЗапуск процесса Kvadrat\n");
		HANDLE hFile;
		DWORD dw = 0;
		hFile = CreateFileA("C:\\Users\\Mikhail\\Documents\\Visual Studio 2010\\Projects\\SRV_L3\\info.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, NULL, NULL);
		//cout << "err=" << GetLastError() << endl;
		double a, b;
		DWORD c;
		DWORD k;
		ReadFile(hFile, &a, sizeof(double), &k, NULL);
		ReadFile(hFile, &b, sizeof(double), &c, NULL);
		CloseHandle(hFile);
		printf("Выполнение...\n");
		result1 = mul(a);
		result2 = mul(b);
		printf("Результат: ");
		cout <<"\na="<<result1<<endl;
		cout <<"b="<<result2<<endl;

		hFile = CreateFileA("C:\\Users\\Mikhail\\Documents\\Visual Studio 2010\\Projects\\SRV_L3\\info.txt", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		WriteFile(hFile, &result1, sizeof(double), &dw, NULL);
		WriteFile(hFile, &result2, sizeof(double), &dw, NULL);
		CloseHandle(hFile);
		hEvent2 = CreateEvent(NULL, FALSE, NULL, _T("Global\\hEvent2.txt"));
		SetEvent(hEvent1);
	}
	system("pause");
	return 0;
}

