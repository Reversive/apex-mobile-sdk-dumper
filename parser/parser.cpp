#include <parser.hpp>

bool Parser::ParseArguments(int argc, char **argv)
{
    if (argc < 2)
    {
        return false;
    }

    int opt;
    while ((opt = getopt(argc, argv, "p:g:f:")) != -1)
    {
        switch (opt)
        {
        case 'p':
            m_packageName = optarg;
            break;
        case 'g':
            m_pGObject = (void *)strtoul(optarg, NULL, 16);
            break;
        case 'f':
            m_pFNamePool = (void *)strtoul(optarg, NULL, 16);
            break;
        default:
            return false;
        }
    }
    return true;
}
