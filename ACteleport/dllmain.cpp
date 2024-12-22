// dllmain.cpp : Definiuje punkt wejścia dla aplikacji DLL.
#include "pch.h"

struct offsets
{
    uintptr_t localPlayer{ 0x00109B74 };
    uintptr_t playerX{0x34};
    uintptr_t playerY{0x38};
    uintptr_t playerZ{0x3C};
}offset;

class vec3
{
public:
    float x, y, z;
    
    vec3()
    {
        x = 0; y = 0; z = 0;
    }
    void SetValuesFromAddres(uintptr_t xAddr, uintptr_t yAddr, uintptr_t zAddr)
    {
        x = *(float*)xAddr;
        y = *(float*)yAddr;
        z = *(float*)zAddr;
    }

    void SetValuesToAddres(uintptr_t xAddr, uintptr_t yAddr, uintptr_t zAddr)
    {   
        if (x == 0 && y == 0 && z == 0)
        {
            std::cout << "[WARNING] before teleportation set checkpoint!!!" << std::endl;
        }
        else
        {
            *(float*)xAddr = x;
            *(float*)yAddr = y;
            *(float*)zAddr = z;
        }
    }
};

DWORD WINAPI HackThread(HMODULE hModule)
{
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);
    std::cout << "Kassawin teleport cheat v1" << std::endl;
    std::cout << "[F1]     =   set checkpoint" << std::endl;
    std::cout << "[F2]     =   teleport to checkpoint" << std::endl;
    std::cout << "[INSERT] =   exit cheat menu" << std::endl;


    uintptr_t moduleAddr = (uintptr_t)GetModuleHandle(L"ac_client.exe");
    uintptr_t localPlayerAddr = moduleAddr + offset.localPlayer;
    uintptr_t localPlayer = *(uintptr_t*)localPlayerAddr;
    uintptr_t playerX = localPlayer + offset.playerX;
    uintptr_t playerY = localPlayer + offset.playerY;
    uintptr_t playerZ = localPlayer + offset.playerZ;

    vec3 playerXYZbuff;

    while (true)
    {
        if (GetAsyncKeyState(VK_INSERT) & 1)
        {
            break;
        }
        if (GetAsyncKeyState(VK_F1) & 1)
        {
            playerXYZbuff.SetValuesFromAddres(playerX, playerY, playerZ);
        }
        if (GetAsyncKeyState(VK_F2) & 1)
        {
            playerXYZbuff.SetValuesToAddres(playerX, playerY, playerZ);
        }
    }
    fclose(f);
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(0, 0, LPTHREAD_START_ROUTINE(HackThread), hModule, 0, 0);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

