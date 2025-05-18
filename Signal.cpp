#include "Signal.h"
#include <iostream>
#include <fstream>

Signal::Signal(const std::vector<double>& input) {
    data = input;
}

void Signal::print() {
    for (int i = 0; i < data.size(); i++) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

void Signal::normalize() {
    double min = data[0];
    double max = data[0];

    for (int i = 1; i < data.size(); i++) {
        if (data[i] < min) min = data[i];
        if (data[i] > max) max = data[i];
    }

    for (int i = 0; i < data.size(); i++) {
        data[i] = (data[i] - min) / (max - min);
    }
}

double Signal::mean() {
    double sum = 0;
    for (int i = 0; i < data.size(); i++) {
        sum += data[i];
    }
    return sum / data.size();
}

double Signal::variance() {
    double m = mean();
    double sum = 0;
    for (int i = 0; i < data.size(); i++) {
        sum += (data[i] - m) * (data[i] - m);
    }
    return sum / data.size();
}

std::vector<double> Signal::movingAverage(int windowSize) {
    std::vector<double> result;
    for (int i = 0; i <= data.size() - windowSize; i++) {
        double sum = 0;
        for (int j = 0; j < windowSize; j++) {
            sum += data[i + j];
        }
        result.push_back(sum / windowSize);
    }
    return result;
}

void Signal::saveEncrypted(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    char key = 'K';
    for (int i = 0; i < data.size(); i++) {
        std::string line = std::to_string(data[i]) + "\n";
        for (char c : line) {
            file.put(c ^ key);
        }
    }
    file.close();
}
