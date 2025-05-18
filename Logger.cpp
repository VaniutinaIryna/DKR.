#include "Logger.h"
#include <fstream>
#include <ctime>

Logger::Logger(const std::string& fname) {
    filename = fname;
}

void Logger::log(const std::string& message) {
    std::ofstream file(filename, std::ios::app);
    time_t now = time(0);
    file << "[" << ctime(&now) << "]: " << message << std::endl;
    file.close();
}
