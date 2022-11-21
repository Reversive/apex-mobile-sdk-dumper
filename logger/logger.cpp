#include <logger.hpp>

void Logger::Log(LOG_LEVEL level, const char *fmt, ...)
{
    FILE *toPrint = (level >= ERROR) ? stderr : stdout;

    if (level == DEBUG)
        fprintf(toPrint, "%s[ %s ]\033[0m ", "\033[0;32m", "DEBUG");
    else if (level == INFO)
        fprintf(toPrint, "%s[ %s ]\033[0m ", "\033[0;36m", "INFO");
    else
        fprintf(toPrint, "%s[ %s ]\033[0m ", "\033[0;31m", "FATAL");

    va_list args;
    va_start(args, fmt);
    vfprintf(toPrint, fmt, args);
    va_end(args);

    fprintf(toPrint, "\n");
    if (level == FATAL)
        exit(1);
}
