#include <iostream>
#include <string>
#include <limits> // Для очистки буфера ввода

enum class LengthUnit {
    Meters,
    Kilometers
};

class Road {
private:
    double length;
    int lanes;

public:
    Road(double l, int n) : length(l > 0 ? l : 1), lanes(n > 0 ? n : 1) {}

    double getLength() const { return length; }

    int getLanes() const { return lanes; }

    std::string getInfo(LengthUnit unit) const {
        std::string unitStr = (unit == LengthUnit::Meters) ? " метров" : " километров";
        return "Длина дороги: " + std::to_string(length) + unitStr + "\n" +
               "Количество полос: " + std::to_string(lanes);
    }

    void printInfo(LengthUnit unit) const {
        std::cout << getInfo(unit) << '\n';
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

    char unitInput;
    std::cout << "Выберите единицу измерения (m - метры, k - километры): ";
    std::cin >> unitInput;
    LengthUnit unit = (unitInput == 'k') ? LengthUnit::Kilometers : LengthUnit::Meters;

    std::cout << "Введите количество полос: ";
    std::cin >> lanes;
    if (std::cin.fail() || lanes <= 0) {
        std::cerr << "Ошибка: Пожалуйста, введите корректное положительное число для количества полос.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }

    Road road(length, lanes);
    road.printInfo(unit);

    return 0;
}
