#include "include/cli.hpp"

pid_t CLI::GetPIDByPackageName(const std::string &packageName) const
{
    std::string command = "pidof " + packageName;
    FILE *pFile = popen(command.c_str(), "r");
    if (pFile == nullptr)
    {
        return -1;
    }
    pid_t pid = -1;
    fscanf(pFile, "%d", &pid);
    pclose(pFile);
    return pid;
}

void *CLI::GetModuleBase(pid_t pid, const std::string &moduleName) const
{
    std::string command = "cat /proc/" + std::to_string(pid) + "/maps | grep " + moduleName;
    FILE *pFile = popen(command.c_str(), "r");
    if (pFile == nullptr)
    {
        return nullptr;
    }
    void *pBase = nullptr;
    fscanf(pFile, "%p", &pBase);
    pclose(pFile);
    return pBase;
}