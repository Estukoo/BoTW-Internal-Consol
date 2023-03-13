#include "mem.h"
#include "../console/console.hpp"
#include <tlhelp32.h>

using namespace Mem;

MemHelper::MemHelper(const char* processName)
{
    processHandle = OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, GetProcessId(processName));
}

MemHelper::~MemHelper()
{
	CloseHandle(processHandle);
}

DWORD MemHelper::GetProcessId(const char* processName) {
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) return 0;

    PROCESSENTRY32 process;
    process.dwSize = sizeof(process);

    if (!Process32First(snapshot, &process)) {
        CloseHandle(snapshot);
        return 0;
    }

    do {
        if (!strcmp((const char*)process.szExeFile, processName)) {
            CloseHandle(snapshot);
            return process.th32ProcessID;
        }
    } while (Process32Next(snapshot, &process));

    CloseHandle(snapshot);
    return 0;
}

// To read ppc memory / pointers and return final pointer as x86
uintptr_t Mem::MemHelper::FindDMAAddy(uintptr_t ptr, uintptr_t basePtr, std::vector<unsigned int> offsets)
{
    uintptr_t addr = ptr;
    for (unsigned int i = 0; i < offsets.size() - 1; ++i)
    {
        addr = ReadMemory<long>(addr + offsets[i]) + basePtr;
    }
    addr += offsets[offsets.size() - 1];
    return addr;
}