#pragma once
#include <Windows.h>
#include <vector>

namespace Mem
{
    class MemHelper
    {
    private:
        HANDLE processHandle;

    public:
        MemHelper(const char* processName);

        ~MemHelper();

        DWORD GetProcessId(const char* processName);

        template <typename T>
        T ReadMemory(uintptr_t addr, bool reverse = true);

        template <typename T>
        void WriteMemory(uintptr_t addr, T value, bool reverse = true);

        uintptr_t FindDMAAddy(uintptr_t ptr, uintptr_t basePtr, std::vector<unsigned int> offsets);
    };

    template <typename T>
    T MemHelper::ReadMemory(uintptr_t addr, bool reverse)
    {
        T value;
        ReadProcessMemory(processHandle, (LPCVOID)addr, &value, sizeof(value), NULL);
        if (reverse) std::reverse((unsigned char*)&value, ((unsigned char*)&value) + sizeof(value));
        return value;
    }

    template <typename T>
    void MemHelper::WriteMemory(uintptr_t addr, T value, bool reverse)
    {
        if (reverse) std::reverse((unsigned char*)&value, ((unsigned char*)&value) + sizeof(value));
        WriteProcessMemory(processHandle, (LPVOID)addr, &value, sizeof(value), NULL);
    }
}