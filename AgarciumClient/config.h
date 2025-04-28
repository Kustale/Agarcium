#pragma once
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <string>

namespace config {
	extern bool DisableNXL;
	extern bool BypassNGS;

	extern std::string WindowName;
	extern std::string HostName;
	extern unsigned short Port;

	extern std::string ModsPath;

	extern bool EnableMultiClient;

	extern bool EnableCefHook;
	extern bool EnableConsole;
	extern bool EnableAutoLogin;

	extern std::string Username;
	extern std::string Password;
	extern std::string Token;

	bool ParseConfig();
}
