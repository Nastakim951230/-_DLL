#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>

#define PATH L"Trenirovka_DLL.dll"

typedef int(_cdecl* forReadData)(LPWSTR);

typedef int(_cdecl* Prost)(int,int);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	HINSTANCE hMyDLL;
	if ((hMyDLL = LoadLibrary(PATH)) == NULL) return 1;
	forReadData myFun = (forReadData)GetProcAddress(hMyDLL, "MyFun");
	

	Prost prost = (Prost)GetProcAddress(hMyDLL, "Prtostoe");
	int rez = prost(1, 35);

	LPWSTR str = calloc(100, sizeof(WCHAR));

	swprintf(str, 100, L"Результат равен %d", rez);
	myFun(str,L"Результат");

	FreeLibrary(hMyDLL);
	return 0;
}