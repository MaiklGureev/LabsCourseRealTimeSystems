// SRV_L3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <stdio.h>
#define BUFLEN 32
#define CreateProcess

using namespace std;

STARTUPINFO si;  
PROCESS_INFORMATION pi; 

HANDLE hEvent1, hEvent2,hEvent3,hEvent4;
double result;



int _tmain(int argc, _TCHAR* argv[])
{

	printf("\n Write A and B: ");
	double a, b;
	cin >> a >> b;
	HANDLE hFile;
	DWORD dw = 0;
	hFile = CreateFileA("C:\\Users\\Mikhail\\Documents\\Visual Studio 2010\\Projects\\SRV_L3\\info.txt", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, TRUNCATE_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//cout << "err=" << GetLastError() << endl;
	WriteFile(hFile, &a, sizeof(double), &dw, NULL);
	WriteFile(hFile, &b, sizeof(double), &dw, NULL);
	CloseHandle(hFile);



	hEvent1 = CreateEvent(NULL, FALSE, NULL, _T("Global\\hEvent1.txt"));
	hEvent2 = CreateEvent(NULL, FALSE, NULL, _T("Global\\hEvent2.txt"));
	hEvent3 = CreateEvent(NULL, FALSE, NULL, _T("Global\\hEvent3.txt"));
	hEvent4 = CreateEvent(NULL, FALSE, NULL, _T("Global\\hEvent4.txt"));


	//CreateProcess("C:\\Users\\Mikhail\\Documents\\Visual Studio 2010\\Projects\\Sqrt.exe", "" , NULL, NULL, TRUE, 0 , NULL, NULL, &si, &pi); 
	//CreateProcess("C:\\Users\\Mikhail\\Documents\\Visual Studio 2010\\Projects\\ADD.exe", "" , NULL, NULL, TRUE, 0 , NULL, NULL, &si, &pi); 
	//cout << "err=" << GetLastError() << endl;
	//cout << WinExec("C:\\Users\\Mikhail\\Desktop\\source\\Kvadrat.exe",SW_SHOW) << endl;
	
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));
	bool bCreateProcess=NULL;
	
	SetEvent(hEvent2);
	CreateProcess("C:\\Users\\Mikhail\\Documents\\Visual Studio 2010\\Projects\\Kvadrat.exe", "" , NULL, NULL, TRUE,CREATE_NEW_CONSOLE , NULL, NULL, &si, &pi);
	HANDLE h=OpenProcess(PROCESS_VM_OPERATION|PROCESS_VM_READ|PROCESS_VM_WRITE,
	TRUE,pi.dwProcessId);
	CloseHandle(h);
	//WinExec("C:\\Users\\Mikhail\\Documents\\Visual Studio 2010\\Projects\\Kvadrat.exe",0);
	cout<<"\n Process created 1"<<endl;

	system("pause");
	WaitForSingleObject(hEvent1, INFINITE);

	SetEvent(hEvent3);
	WinExec("C:\\Users\\Mikhail\\Documents\\Visual Studio 2010\\Projects\\ADD.exe",0);
	cout<<"\n Process created 2"<<endl;
	system("pause");
	WaitForSingleObject(hEvent1, INFINITE);

	SetEvent(hEvent4);
	WinExec("C:\\Users\\Mikhail\\Documents\\Visual Studio 2010\\Projects\\Sqrt.exe",0);
	cout<<"\n Process created 3"<<endl;
	system("pause");
	WaitForSingleObject(hEvent1, INFINITE);

	hFile = CreateFileA("C:\\Users\\Mikhail\\Documents\\Visual Studio 2010\\Projects\\SRV_L3\\info2.txt", GENERIC_READ, 0, NULL, OPEN_EXISTING, NULL, NULL);
	ReadFile(hFile, &result, sizeof(double), 0, NULL);
	CloseHandle(hFile);
	cout << "C=" << result << endl;

	system("pause");
	return 0;
}

