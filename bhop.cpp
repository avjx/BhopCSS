#include <iostream>
#include <windows.h>

bool IsGameInFocus() {
    HWND gameWindow = FindWindow(NULL, "Counter-Strike Source");
    return GetForegroundWindow() == gameWindow;
}

void BhopThread() {
    AllocConsole();
    FILE* f;
    f = freopen("CONOUT$", "w", stdout);

    DWORD moduleBase = (DWORD)GetModuleHandle("client.dll");
    DWORD jump = moduleBase + 0x4F5D24;
    DWORD air = moduleBase + 0x4A4078;

    std::cout << "MODULE: " << std::hex << moduleBase << std::endl;
    std::cout << "JUMP: " << std::hex << jump << std::endl;
    std::cout << "AIR: " << std::hex << air << std::endl;

    while (1) {
        if (GetAsyncKeyState(VK_END) & 1) {
            break;
        }
        if (IsGameInFocus() && GetAsyncKeyState(VK_SPACE)) {
            if (*(int*)air == 0) {
                *(int*)jump = 5;
                Sleep(10);
                *(int*)jump = 4;
            }
        }
    }

    fclose(f);
}

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
    if (reason == DLL_PROCESS_ATTACH) {
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)BhopThread, 0, 0, 0);
    }

    return TRUE;
}
