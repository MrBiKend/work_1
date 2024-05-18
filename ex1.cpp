#include <iostream>
#include <string>
#include <limits> // Для очистки буфера ввода

class Road {
private:
    double length;
    int lanes;

public:
    Road(double l, int n) : length(l > 0 ? l : 1), lanes(n > 0 ? n : 1) {}

    double getLength() const { return length; }

    int getLanes() const { return lanes; }

    std::string getInfo() const {
        return "Длина дороги: " + std::to_string(length) + " метров\n" +
               "Количество полос: " + std::to_string(lanes);
    }

    void printInfo() const {
        std::cout << getInfo() << '\n';
    }
};

int main() {
    double length;
    int lanes;

    std::cout << "Введите длину дороги: ";
    std::cin >> length;
    if (std::cin.fail() || length <= 0) {
        std::cerr << "Ошибка: Пожалуйста, введите корректное положительное число для длины дороги.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }

    std::cout << "Введите количество полос: ";
    std::cin >> lanes;
    if (std::cin.fail() || lanes <= 0) {
        std::cerr << "Ошибка: Пожалуйста, введите корректное положительное число для количества полос.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }

    Road road(length, lanes);
    road.printInfo();

    return 0;
}
