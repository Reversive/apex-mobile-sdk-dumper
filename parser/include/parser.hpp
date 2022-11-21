#ifndef PARSER_HPP
#define PARSER_HPP
#include <string>
#include <sys/types.h>
#include <logger.hpp>
#include <getopt.h>

class Parser
{
private:
    void *m_pGObject;
    void *m_pFNamePool;
    std::string m_packageName;
    Parser() {}

public:
    bool ParseArguments(int argc, char **argv);
    void *&GObject() { return m_pGObject; }
    void *&FNamePool() { return m_pFNamePool; }
    std::string &PackageName() { return m_packageName; }
    static Parser &Instance()
    {
        static Parser parser;
        return parser;
    }
};

#endif