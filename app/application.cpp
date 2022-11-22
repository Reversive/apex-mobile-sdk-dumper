#include "include/application.hpp"

void Application::Run(int argc, char **argv)
{
    Parser parser = Parser::Instance();
    if (!parser.ParseArguments(argc, argv))
    {
        Error("Failed to parse arguments");
        Error("Usage: %s -p <package_name> -g <gobject> -f <fnamepool>", argv[0]);
        return;
    }

    Info("package: %s - gobject: %p - fnamepool: %p", parser.PackageName().c_str(), parser.GObject(), parser.FNamePool());

    CLI cli = CLI::Instance();
    pid_t targetPid = cli.GetPIDByPackageName(parser.PackageName());
    if (targetPid == -1)
    {
        Error("Failed to get pid of %s", parser.PackageName().c_str());
        return;
    }

    Info("%s - pid: %d", parser.PackageName().c_str(), targetPid);

    void *pLibUE4 = cli.GetModuleBase(targetPid, "libUE4.so");
    if (pLibUE4 == nullptr)
    {
        Error("Failed to get libUE4.so base address");
        return;
    }

    Info("libUE4.so - base: %p", pLibUE4);

    SDK sdk = new SDK(pLibUE4, parser.FNamePool(), parser.GObject(), targetPid);
    if (!sdk.DumpSDK())
    {
        return;
    }

    Info("Dumped SDK");
}
