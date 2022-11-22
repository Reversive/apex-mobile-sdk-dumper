#ifndef SDK_HPP
#define SDK_HPP
#include <syscall.hpp>

class SDK
{
private:
    void *m_pFNamePool;
    void *m_pUObjectArray;
    void *m_pLibUE4;
    Syscall *m_Syscall;

public:
    SDK(void *pLibUE4, void *pFNamePool, void *pUObjectArray, pid_t pid);
    ~SDK();
    bool DumpSDK();
};

#endif