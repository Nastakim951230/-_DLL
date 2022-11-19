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
__declspec(dllimport) int Prtostoe(int a, int b);

int Prtostoe(int a, int b)
{
    int chek = 0;
    int kol = 0;
    for (int i = a; i <= b; i++)
    {
        for (int j = 2; j <= b; j++)
        {
            if ((i % j == 0)&&(i != j))
            {
                chek = 1;
                break;
            }

        }
        if (chek == 0)
        {
            kol++;
        }
        else
        {
            chek = 0;
        }
    }
    return kol;
}

