#ifndef SDK_HPP
#define SDK_HPP
#include <syscall.hpp>
#include <string>

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
    bool DumpSDK(const std::string &outputFilename);
};

#endif