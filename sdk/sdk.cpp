#include "include/sdk.hpp"

SDK::SDK(void *pLibUE4, void *pFNamePool, void *pUObjectArray, pid_t pid) : m_pFNamePool(pFNamePool), m_pUObjectArray(pUObjectArray), m_pLibUE4(pLibUE4)
{
    m_Syscall = new Syscall(pid);
}

SDK::~SDK()
{
    delete m_Syscall;
}

bool SDK::DumpSDK(const std::string &outputFilename)
{

    return true;
}