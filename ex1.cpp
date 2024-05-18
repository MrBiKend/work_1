#include <iostream>
#include <string>
#include <limits> // Для очистки буфера ввода

class Road {
private:
    int length;
    int lanes;

public:
    constexpr Road(int l, int n) : length(l > 0 ? l : 1), lanes(n > 0 ? n : 1) {}

    int getLength() const { return length; }

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
    int length;
    int lanes;

    std::cout << "Введите длину дороги (в метрах): ";
    std::cin >> length;
    if (std::cin.fail() || length <= 0) {
        std::cerr << "Ошибка: введено некорректное значение для длины дороги.\n";
        std::cin.clear(); // Сбрасываем флаг ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
        return 1;
    }

    std::cout << "Введите количество полос: ";
    std::cin >> lanes;
    if (std::cin.fail() || lanes <= 0) {
        std::cerr << "Ошибка: введено некорректное значение для количества полос.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;#include <iostream>
#include <string>
#include <limits> // Для очистки буфера ввода

class Road {
private:
    int length;
    int lanes;

public:
    constexpr Road(int l, int n) : length(l > 0 ? l : 1), lanes(n > 0 ? n : 1) {}

    int getLength() const { return length; }

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
    int length;
    int lanes;

    std::cout << "Введите длину дороги (в метрах): ";
    std::cin >> length;
    if (std::cin.fail() || length <= 0) {
        std::cerr << "Ошибка: введено некорректное значение для длины дороги.\n";
        std::cin.clear(); // Сбрасываем флаг ошибки
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Очищаем буфер ввода
        return 1;
    }

    std::cout << "Введите количество полос: ";
    std::cin >> lanes;
    if (std::cin.fail() || lanes <= 0) {
        std::cerr << "Ошибка: введено некорректное значение для количества полос.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }

    Road road(length, lanes);
    road.printInfo();

    return 0;
}
