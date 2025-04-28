#pragma once
#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#include <windows.h>
#include <MinHook.h>
#include <iostream>
#include "config.h"
#include "win_hook.h"
#include "winsock_hook.h"
#include "hook.h"
#include "xml_hook.h"
#include "mod_loader.h"

constexpr char CLIENT_LOCALE[] = "en-US";
FILE* fpstdout = stdout;
FILE* fpstderr = stderr;

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    auto& loader = ModLoader::Instance();
    switch (ul_reason_for_call) {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        setlocale(LC_ALL, CLIENT_LOCALE);

        config::ParseConfig();

        if (MH_Initialize() != MH_OK)
            return false;

        if (AllocConsole()) {
            AttachConsole(GetCurrentProcessId());
            ShowWindow(GetConsoleWindow(), SW_HIDE);

            // Disable QUICK_EDIT_MODE (this can cause the window to freeze)
            DWORD prev_mode;
            HANDLE hConsole = GetStdHandle(STD_INPUT_HANDLE);
            GetConsoleMode(hConsole, &prev_mode);
            SetConsoleMode(hConsole, prev_mode & ~ENABLE_QUICK_EDIT_MODE);

            // Redirect output streams
            freopen_s(&fpstdout, "CONOUT$", "w", stdout);
            freopen_s(&fpstderr, "CONOUT$", "w", stderr);
        }

        if (config::EnableConsole) {
            SetConsoleTitleA(config::WindowName.c_str());
            ShowWindow(GetConsoleWindow(), SW_RESTORE);
        }

        loader.LoadMods(config::ModsPath);

        if (!win::Hook()) {
            MessageBoxA(NULL, "Failed to hook window.", "Error", MB_ICONERROR | MB_OK);
            return FALSE;
        }

        if (!winsock::Hook()) {
            MessageBoxA(NULL, "Failed to hook winsock.", "Error", MB_ICONERROR | MB_OK);
            return FALSE;
        }

        break;

    case DLL_PROCESS_DETACH:
        FreeConsole();
        break;
    }
    return TRUE;
}