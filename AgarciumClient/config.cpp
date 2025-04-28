#include "config.h"
#include <iostream>

namespace config {
	bool DisableNXL = true;
	bool BypassNGS = true;

	// Custom configuration
	std::string WindowName = "MapleStory 2";
	std::string HostName = "127.0.0.1";
	unsigned short Port = 20001;

	std::string ModsPath = "";

	bool EnableMultiClient = true;

	bool EnableCefHook = true;
	bool EnableConsole = false;
	bool EnableAutoLogin = false;

	std::string Username = "";
	std::string Password = "";
	std::string Token = "";

	bool ParseConfig()
	{
		// Parse config options from the command line arguments
		// --username=<username>
		// --password=<password>
		// --token=<token>
		// --title=<title>
		// --ip=<ip>
		// --port=<port>
		// --mods=<path>
		// --autologin
		// --console

		for (int i = 1; i < __argc; ++i) {
			std::string arg = __argv[i];
			if (arg.find("--username=") == 0) {
				// Parse username
				auto username = arg.substr(11);
				if (username.empty()) {
					std::cerr << "Invalid username provided." << std::endl;
				}
				else {
					Username = username;
				}
			}
			else if (arg.find("--password=") == 0) {
				// Parse password
				auto password = arg.substr(11);
				if (password.empty()) {
					std::cerr << "Invalid password provided." << std::endl;
				}
				else {
					Password = password;
				}
			}
			else if (arg.find("--token=") == 0) {
				// Parse token
				auto token = arg.substr(8);
				if (token.empty()) {
					std::cerr << "Invalid token provided." << std::endl;
				}
				else {
					Token = token;
				}
			}
			else if (arg.find("--title=") == 0) {
				WindowName = arg.substr(8);
			}
			else if (arg.find("--ip=") == 0) {
				HostName = arg.substr(5);
			}
			else if (arg.find("--port=") == 0) {
				Port = static_cast<unsigned short>(std::stoi(arg.substr(7)));
			}
			else if (arg.find("--mods=") == 0) {
				ModsPath = arg.substr(7);
			}
			else if (arg == "--autologin") {
				EnableAutoLogin = true;
			}
			else if (arg == "--console") {
				EnableConsole = true;
			}
		}
		return true;
	}
}
