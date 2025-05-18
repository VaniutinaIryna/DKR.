#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger {
private:
    std::string filename;

public:
    Logger(const std::string& fname);
    void log(const std::string& message);
};

#endif
