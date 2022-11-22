#ifndef CLI_HPP
#define CLI_HPP
#include <string>
#include <stdio.h>

class CLI
{
private:
    CLI() {}

public:
    pid_t GetPIDByPackageName(const std::string &packageName) const;
    void *GetModuleBase(pid_t pid, const std::string &moduleName) const;
    static CLI &Instance()
    {
        static CLI cli;
        return cli;
    }
};

#endif