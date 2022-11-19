#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>

#define PATH L"Trenirovka_DLL.dll"

typedef int(_cdecl* forReadData)(LPWSTR);

typedef int(_cdecl* Summa)(int,int);
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
	HINSTANCE hMyDLL;
	if ((hMyDLL = LoadLibrary(PATH)) == NULL) return 1;
	forReadData myFun = (forReadData)GetProcAddress(hMyDLL, "MyFun");
	

	Summa sum = (Summa)GetProcAddress(hMyDLL, "Summ");
	int rez = sum(12, 35);

	LPWSTR str = calloc(100, sizeof(WCHAR));

	swprintf(str, 100, L"Сумма равна %d", rez);
	myFun(str,L"Суммирование");

	FreeLibrary(hMyDLL);
	return 0;
}