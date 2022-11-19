#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#define PATH L"Trenirovka_DLL.dll"


typedef int(_cdecl* ProstPotoki)(int, int,int);
typedef int(_cdecl* Prost)(int,int);
int main()
{
	system("chcp 1251>nul");
	HINSTANCE hMyDLL;
	if ((hMyDLL = LoadLibrary(PATH)) == NULL) return 1;
	int a, b,c;
	printf("¬ведите первое число: ");
	scanf_s("%d", &a);
	printf("¬ведите второе число: ");
	scanf_s("%d", &b);
	
	Prost prost = (Prost)GetProcAddress(hMyDLL, "Prtostoe");
	int rez = prost(a, b);
	printf("–езультат равен %d",rez);
	FreeLibrary(hMyDLL);

	HINSTANCE hMyDLL1;
	if ((hMyDLL1 = LoadLibrary(PATH)) == NULL) return 1;
	printf("¬ведите количество потоков: ");
	scanf_s("%d", &c);
	ProstPotoki prostpotoki=(ProstPotoki)GetProcAddress(hMyDLL1, "Show");
	prostpotoki(a, b,c);
	/*printf("–езультат равен %d", rezul);*/
	FreeLibrary(hMyDLL1);
	return 0;
}