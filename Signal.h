#ifndef SIGNAL_H
#define SIGNAL_H

#include <vector>
#include <string>

class Signal {
private:
    std::vector<double> data;

public:
    Signal(const std::vector<double>& input);

    void print();
    void normalize();
    double mean();
    double variance();
    std::vector<double> movingAverage(int windowSize);
    void saveEncrypted(const std::string& filename);
};

#endif
