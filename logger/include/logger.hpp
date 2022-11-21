#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum
{
    DEBUG = 0,
    INFO,
    ERROR,
    FATAL
} LOG_LEVEL;

class Logger
{
private:
    Logger() {}

public:
    Logger(Logger const &) = delete;
    void operator=(Logger const &) = delete;
    void Log(LOG_LEVEL level, const char *fmt, ...);

    static Logger &Instance()
    {
        static Logger instance;
        return instance;
    }
};

#define Debug(fmt, ...) Logger::Instance().Log(DEBUG, fmt, ##__VA_ARGS__)
#define Info(fmt, ...) Logger::Instance().Log(INFO, fmt, ##__VA_ARGS__)
#define Error(fmt, ...) Logger::Instance().Log(ERROR, fmt, ##__VA_ARGS__)
#define Fatal(fmt, ...) Logger::Instance().Log(FATAL, fmt, ##__VA_ARGS__)

#endif