#pragma once
#include <string>
#include <map>
#include <memory>
#include <tinyxml.h>
#include <unordered_map>

struct ModInfo {
	std::string id;
	std::unordered_map<std::string, std::string> files;
};

class ModLoader {
public:
	static ModLoader& Instance();

	bool LoadMods(const std::string& modsRootPath);
	const std::map<std::string, ModInfo>& GetMods() const;

	// Returns a pointer to the TiXmlDocument for the first mod that has the given relative path.
	// Returns nullptr if not found. Optionally, returns the mod id via outModId.
	TiXmlDocument* GetXmlByRelPath(const std::string& relPath, std::string* outModId = nullptr) const;

	void Clear();

private:
	ModLoader() = default;
	ModLoader(const ModLoader&) = delete;
	ModLoader& operator=(const ModLoader&) = delete;

	bool ParseMod(const std::string& modFolderPath);

	std::map<std::string, ModInfo> mods_;
};
