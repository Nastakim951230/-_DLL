#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    BOOL bAllWentWell = TRUE;
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:

        break;

    case DLL_THREAD_ATTACH:

        break;

    case DLL_THREAD_DETACH:

        break;

    case DLL_PROCESS_DETACH:
        break;
    }
    if (bAllWentWell)
        return TRUE;
    else
        return FALSE;
}
__declspec(dllimport) int MyFun(LPWSTR str, LPWSTR zag);

int MyFun(LPWSTR str, LPWSTR zag)
{
    MessageBox(NULL, str, zag, MB_OK);
    return 0;
}
__declspec(dllimport) int Summ(int a, int b);
int Summ(int a, int b)
{
    return a + b;
}