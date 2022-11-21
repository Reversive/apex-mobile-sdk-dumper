#include "include/entry_point.hpp"

int main(int argc, char **argv)
{
    auto app = new Application();
    app->Run(argc, argv);
    delete app;
    return 0;
}