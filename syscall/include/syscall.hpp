#ifndef SYSCALL_HPP
#define SYSCALL_HPP
#include <sys/types.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/uio.h>

class Syscall
{
private:
    pid_t m_pid;

public:
    Syscall(pid_t pid) : m_pid(pid) {}
    bool Read(void *pAddress, void *pBuffer, size_t size);
};

#endif