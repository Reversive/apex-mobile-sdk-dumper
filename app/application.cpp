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

    pid_t targetPid = CLI::Instance().GetPIDByPackageName(parser.PackageName());
    if (targetPid == -1)
    {
        Error("Failed to get pid of %s", parser.PackageName().c_str());
        return;
    }

    Info("%s - pid: %d", parser.PackageName().c_str(), targetPid);
}
