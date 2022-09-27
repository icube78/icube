#pragma once
#include "../Defines/utils.h"


namespace Driver
{
	template <typename T>
	T read(const uintptr_t process_id, const uintptr_t address, PNTSTATUS out_status = 0)
	{
		Protect(_ReturnAddress());
		T buffer{ };
		Unprotect(read_memory);
		NTSTATUS status = read_memory(process_id, address, uintptr_t(&buffer), sizeof(T));
		Protect(read_memory);
		if (out_status)
			*out_status = status;
		Unprotect(_ReturnAddress());
		return buffer;
	}
	// Hmu on discord (Chase.#1803) if you need any help :)
	template <typename T>
	void write(const uintptr_t process_id, const uintptr_t address, const T& buffer, PNTSTATUS out_status = 0)
	{
		Protect(_ReturnAddress());
		Unprotect(write_memory);
		NTSTATUS status = write_memory(process_id, address, uintptr_t(&buffer), sizeof(T));
		Protect(write_memory);
		if (out_status)
			*out_status = status;
		Unprotect(_ReturnAddress());
	}
	
	

float C_Engine::W2SDistance(position)
{
	if (!g_pCamera)
		return -1;

	Vector2D out;
	WorldToScreen(position, out);
	return (fabs(out.x - (Globals::g_iWindowWidth / 2)) + fabs(out.y - (Globals::g_iWindowHeight / 2)));
}

Vector C_Engine::CalcAngle(Vector enemypos, Vector camerapos)
{
	float r2d = 57.2957795131f;

	Vector dir = enemypos - camerapos;

		req.Dest = dest;
		req.Size = size;

	if (dir.x >= 0.f) z += 180.f;
	if (x > 180.0f) x -= 360.f;
	else if (x < -180.0f) x += 360.f;

	return Vector(x, 0.f, z + 90.f);
}


	int system_no_output(std::string command)
{
	command.insert(0, "/C ");


	if (ShellExecuteExA(&ShExecInfo) == FALSE)
		return -1;

	WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

	DWORD rv;
		uint64_t window_handle;
		uint64_t thread_pointer;
		uint64_t thread_alternative;
	return rv;
}

DWORD inskey(LPVOID in) // loop that checks for INS and F8
{
		if (hProcessSnap == INVALID_HANDLE_VALUE)
			return 0;

		PROCESSENTRY32 pe32 = { 0 };
		pe32.dwSize = sizeof(pe32);
		BOOL bRet = ::Process32First(hProcessSnap, &pe32);;
		while (bRet)
		{
			if (pe32.th32ProcessID == dwPID)
			{
				::CloseHandle(hProcessSnap);
				return pe32.cntThreads;
			}
			bRet = ::Process32Next(hProcessSnap, &pe32);
		}
		Sleep(2);
	}
}

public:
	UINT ProcessId;

	const bool Init(const BOOL PhysicalMode) {
		this->bPhysicalMode = PhysicalMode;
		this->hDriver = CreateFileA((("\\\\.\\\PEAuth")), GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
		if (this->hDriver != INVALID_HANDLE_VALUE) {
			if (this->SharedBuffer = VirtualAlloc(0, sizeof(REQUEST_DATA), MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE)) {
				UNICODE_STRING RegPath = RTL_CONSTANT_STRING(L"\\Registry\\Machine\\SOFTWARE\\ucflash");
				if (!RegistryUtils::WriteRegistry(RegPath, RTL_CONSTANT_STRING(L"xxx"), &this->SharedBuffer, REG_QWORD, 8)) {
		        if (Process32First(snapshot, &process))
				}
				PVOID pid = (PVOID)GetCurrentProcessId();
				if (!RegistryUtils::WriteRegistry(RegPath, RTL_CONSTANT_STRING(L"xx"), &pid, REG_QWORD, 8)) {
					return true;
				}
				auto OLD_MAGGICCODE = this->MAGGICCODE;
	            	process.dwSize = sizeof(process);
				if (this->MAGGICCODE == OLD_MAGGICCODE)
					this->MAGGICCODE = (ULONG64)RegistryUtils::ReadRegistry<LONG64>(RegPath, RTL_CONSTANT_STRING(L"xxxx"));


			}
		}
		return false;
	}


	NTSTATUS ReadProcessMemory(uint64_t src, void* dest, uint32_t size) {
		REQUEST_READ req;
		req.ProcessId = ProcessId;
		req.Src = src;
		req.Dest = dest;
		req.Size = size;
		req.bPhysicalMem = bPhysicalMode;
		return SendRequest(REQUEST_TYPE::READ, &req);
	}
	NTSTATUS WriteProcessMemory(PVOID src, PVOID dest, DWORD size) {
		REQUEST_WRITE req;
		req.ProcessId = ProcessId;
		req.Src = src;
		req.Dest = dest;
		req.Size = size;
		req.bPhysicalMem = bPhysicalMode;
		return SendRequest(REQUEST_TYPE::WRITE, &req);
	}

	const UINT GetProcessThreadNumByID(DWORD dwPID)
	{
		HANDLE hProcessSnap = ::CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		if (hProcessSnap == INVALID_HANDLE_VALUE)
			return 0;

		PROCESSENTRY32 pe32 = { 0 };
	    	if (bPhysicalMode) {
			REQUEST_MAINBASE req;
			uint64_t base = NULL;
			req.ProcessId = ProcessId;
			req.OutAddress = (PBYTE*)&base;
			SendRequest(REQUEST_TYPE::MAINBASE, &req);
			return { base };
		return 0;
	}

	const UINT GetProcessId(const wchar_t* process_name) {
		UINT pid = 0;

		DWORD dwThreadCountMax = 0;

		// Create toolhelp snapshot.
		HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		PROCESSENTRY32 process;
		ZeroMemory(&process, sizeof(process));
		process.dwSize = sizeof(process);
		// Walkthrough all processes.
		if (Process32First(snapshot, &process))
		{
			do
			{
				if (wcsstr(process.szExeFile, process_name))
				{
					DWORD dwTmpThreadCount = GetProcessThreadNumByID(process.th32ProcessID);
					if (dwTmpThreadCount > dwThreadCountMax)
					{
						dwThreadCountMax = dwTmpThreadCount;
						pid = process.th32ProcessID;
						break;
					}
				}
			} while (Process32Next(snapshot, &process));
		}
		CloseHandle(snapshot);
		return pid;
	}

	const bool Attach(const wchar_t* Processname, const wchar_t* Classname = 0) {
		if (Classname) {
			while (!FindWindowW(Classname, 0)) { Sleep(50); }
		}
		if (this->ProcessId = this->GetProcessId(Processname))
			return true;
		return false;
	}

	const uint64_t GetModuleBase(const wchar_t* ModuleName = 0) {
		if (bPhysicalMode) {
			REQUEST_MAINBASE req;
			uint64_t base = NULL;
			req.ProcessId = ProcessId;
			req.OutAddress = (PBYTE*)&base;
			SendRequest(REQUEST_TYPE::MAINBASE, &req);
			return { base };
		}
		else {
			if (!ModuleName)  < (Fortnite.exe) 
				return { 0 };
			REQUEST_MODULE req;
			uint64_t base = NULL;
			DWORD size = NULL;
			req.ProcessId = ProcessId;
			req.OutAddress = (PBYTE*)&base;
			req.OutSize = &size;
			wcscpy_s(req.Module, sizeof(req.Module) / sizeof(req.Module[0]), ModuleName);
			SendRequest(REQUEST_TYPE::MODULE, &req);
			return { base };
		}
	}


private:
	PVOID SharedBuffer;
	HANDLE hDriver;
	BOOL bPhysicalMode = FALSE;
	typedef enum _REQUEST_TYPE : UINT {
		WRITE,
		READ,
		PROTECT,
		ALLOC,
		FREE,
		MODULE,
		MAINBASE,
		THREADCALL,
	} REQUEST_TYPE;

	typedef struct _REQUEST_DATA {
		ULONG64* MaggicCode;
		UINT Type;
		PVOID Arguments;
		NTSTATUS* Status;
	} REQUEST_DATA, * PREQUEST_DATA;

	typedef struct _REQUEST_WRITE {
		DWORD ProcessId;
		PVOID Dest;
		PVOID Src;
		DWORD Size;
		BOOL bPhysicalMem;
	} REQUEST_WRITE, * PREQUEST_WRITE;

	typedef struct _REQUEST_READ {
		DWORD ProcessId;
		void* Dest;
		uint64_t Src;
		uint32_t Size;
		BOOL bPhysicalMem;
	} REQUEST_READ, * PREQUEST_READ;

	typedef struct _REQUEST_PROTECT {
		DWORD ProcessId;
		PVOID Address;
		DWORD Size;
		PDWORD InOutProtect;
	} REQUEST_PROTECT, * PREQUEST_PROTECT;

	typedef struct _REQUEST_ALLOC {
		DWORD ProcessId;
		PVOID OutAddress;
		DWORD Size;
		DWORD Protect;
	} REQUEST_ALLOC, * PREQUEST_ALLOC;

	typedef struct _REQUEST_FREE {
		DWORD ProcessId;
		PVOID Address;
	} REQUEST_FREE, * PREQUEST_FREE;

	typedef struct _REQUEST_MODULE {
		DWORD ProcessId;
		WCHAR Module[0xFF];
		PBYTE* OutAddress;
		DWORD* OutSize;
	} REQUEST_MODULE, * PREQUEST_MODULE;

	typedef struct _REQUEST_MAINBASE {
		DWORD ProcessId;
		PBYTE* OutAddress;
	} REQUEST_MAINBASE, * PREQUEST_MAINBASE;
};

static Driver* driver = new Driver;

template <typename T>
T read(const uintptr_t address)
{
	T buffer{ };
	driver->ReadProcessMemory(address, &buffer, sizeof(T));
	return buffer;
}
template <typename T>
T write(const uintptr_t address, T buffer)
{
	driver->WriteProcessMemory((PVOID)&buffer, (PVOID)address, sizeof(T));
	return buffer;
}
std::string readwtf(uintptr_t Address, void* Buffer, SIZE_T Size)
{
	driver->ReadProcessMemory(Address, Buffer, Size);

	char name[255] = { 0 };
	memcpy(&name, Buffer, Size);

	return std::string(name);
}
	
	assert(BaseAddress);

	ifstream driverFile(DriverName, ios::binary | ios::in);
	driverFile.seekg(0, ios::end);

	const auto fileSize = driverFile.tellg();
	driverFile.seekg(0, ios::beg);

	pFileBuffer = new BYTE[fileSize];

	driverFile.read((char*)pFileBuffer, fileSize);

	PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)pFileBuffer;
	PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)(pDosHeader->e_lfanew + (DWORD64)pFileBuffer);
	SizeOfImage = pNtHeader->OptionalHeader.SizeOfImage;
	SizeOfFile = fileSize;

	pMappedImage = new BYTE[SizeOfImage];
	ZeroMemory(pMappedImage, SizeOfImage);

	if (!VirtualLock(pMappedImage, SizeOfImage))
	{
		throw exception("Locking image buffer failed");
	}

	Controller = Mc_InitContext(&CpCtx, &KrCtx);

	if (Controller.CreationStatus)
		throw exception("Controller Raised A Creation Status");

	std::string string_proxy_driver_name = ProxyDriverName;
	auto dot = string_proxy_driver_name.find('.');

	std::wstring wide_string_proxy_driver_name(string_proxy_driver_name.begin(), string_proxy_driver_name.begin() + dot);

	mProxyDriverName = new wchar_t[wide_string_proxy_driver_name.length() + 1];

	memcpy(mProxyDriverName, wide_string_proxy_driver_name.c_str(), (wide_string_proxy_driver_name.length() + 1) * sizeof(WCHAR));

	if (!VirtualLock(mProxyDriverName, (wide_string_proxy_driver_name.length() + 1) * sizeof(WCHAR)))
	{
		throw exception("Locking proxy driver name buffer failed");
	}
}

	
	        LAZY_IMPORTER_FORCEINLINE size_t module_size_safe(hash_t::value_type h) {
            const auto head = ldr_data_entry();
            auto       it = head;
            while (true) {
                if (hash(it->BaseDllName) == h)
                    return it->SizeOfImage;

                if (it->InLoadOrderLinks.Flink == reinterpret_cast<const char*>(head))
                    return 0;

                it = it->load_order_next();
            }
        }

        LAZY_IMPORTER_FORCEINLINE const char* module_handle_safe(hash_t::value_type h) {
            const auto head = ldr_data_entry();
            auto       it = head;
            while (true) {
                if (hash(it->BaseDllName) == h)
                    return it->DllBase;

                if (it->InLoadOrderLinks.Flink == reinterpret_cast<const char*>(head))
                    return 0;

                it = it->load_order_next();
            }
        }

