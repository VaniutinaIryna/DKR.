
#include <iostream>
#include "Signal.h"
#include "Logger.h"

int main() {
    Logger logger("log.txt");
    logger.log("Старт програми");

    std::vector<double> input = {2.5, 1.0, 3.5, 4.0, 2.0};
    Signal s(input);

    std::cout << "Початковий сигнал: ";
    s.print();

    s.normalize();
    logger.log("Сигнал нормалізовано");

    std::cout << "Нормалізований сигнал: ";
    s.print();

    std::cout << "Середнє значення: " << s.mean() << std::endl;
    std::cout << "Дисперсія: " << s.variance() << std::endl;

    std::vector<double> filtered = s.movingAverage(3);
    std::cout << "Фільтрований сигнал (вікно 3): ";
    for (int i = 0; i < filtered.size(); i++) {
        std::cout << filtered[i] << " ";
    }
    std::cout << std::endl;
    logger.log("Ковзне середнє виконано");

    s.saveEncrypted("signal.enc");
    logger.log("Сигнал збережено у файл з шифруванням");

    logger.log("Завершення програми");
    return 0;
}
