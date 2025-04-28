#pragma once
#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <vector>

#define PE_START          0x0000000140001000 /* The standard PE start address */
#define PE_END            0x000000014FFFFFFF /* The scan range of the PE */


namespace hook {
	bool WriteBytes(DWORD_PTR dwAddr, const std::vector<BYTE>& bytes);
	FARPROC GetFuncAddress(LPCSTR lpLibFileName, LPCSTR lpProcName);

	class CNetworkService;
	typedef void(__fastcall* NetworkServiceLoginFunc)(CNetworkService* thisPtr);

	bool PatchClient();
	void Login();
}
