#include <iostream>
#include <string>
#include <limits>

enum class LengthUnit {
    Meters,
    Kilometers
};

enum class RoadType {
    UrbanStreet,
    Highway
};

class Road {
private:
    double length;
    int totalLanes;
    int lanesPerDirection;
    RoadType type;

public:
    Road(double l, int n, int nPerDirection, RoadType t) : length(l > 0 ? l : 1), totalLanes(n > 0 ? n : 1), lanesPerDirection(nPerDirection > 0 ? nPerDirection : 1), type(t) {}

    double getLength() const { return length; }

    int getTotalLanes() const { return totalLanes; }

    int getLanesPerDirection() const { return lanesPerDirection; }

    RoadType getType() const { return type; }

    std::string getTypeString() const {
        switch (type) {
            case RoadType::UrbanStreet:
                return "Городская улица";
            case RoadType::Highway:
                return "Автострада";
            default:
                return "Неизвестный тип дороги";
        }
    }

    std::string getInfo(LengthUnit unit) const {
        std::string unitStr = (unit == LengthUnit::Meters) ? " метров" : " километров";
        return getTypeString() + "\n" +
               "Длина дороги: " + std::to_string(length) + unitStr + "\n" +
               "Количество полос в каждом направлении: " + std::to_string(lanesPerDirection) +
               " (Общее количество полос: " + std::to_string(totalLanes) + ")";
    }

    void printInfo(LengthUnit unit) const {
        std::cout << getInfo(unit) << '\n';
    }
};

// Функция для очистки буфера ввода
void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Функция для безопасного ввода целых чисел
int safeInputInt() {
    int value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cerr << "Ошибка: Введите целое число.\n";
            clearInputBuffer();
        } else {
            return value;
        }
    }
}

// Функция для безопасного ввода вещественных чисел
double safeInputDouble() {
    double value;
    while (true) {
        std::cin >> value;
        if (std::cin.fail()) {
            std::cerr << "Ошибка: Введите вещественное число.\n";
            clearInputBuffer();
        } else {
            return value;
        }
    }
}

// Функция для проверки валидности ввода типа дороги
bool isValidRoadType(char typeInput) {
    return (typeInput == 'u' || typeInput == 'U' || typeInput == 'h' || typeInput == 'H');
}

int main() {
    double length;
    int totalLanes;
    int lanesPerDirection;
    char typeInput;

    RoadType type;
    while (true) {
        std::cout << "Введите тип дороги (u - городская улица, h - автострада): ";
        std::cin >> typeInput;
        if (!isValidRoadType(typeInput)) {
            std::cerr << "Ошибка: Пожалуйста, введите 'u' для городской улицы или 'h' для автострады.\n";
            continue; // Повторить ввод типа дороги
        }
        if (typeInput == 'u' || typeInput == 'U') {
            type = RoadType::UrbanStreet;
        } else {
            type = RoadType::Highway;
        }
        break; // Выйти из цикла, если ввод корректен
    }

    std::cout << "Введите длину дороги: ";
    length = safeInputDouble();
    if (length <= 0) {
        std::cerr << "Ошибка: Пожалуйста, введите корректное положительное число для длины дороги.\n";
        return 1;
    }

    std::cout << "Введите общее количество полос: ";
    totalLanes = safeInputInt();
    if (totalLanes <= 0) {
        std::cerr << "Ошибка: Пожалуйста, введите корректное положительное число для общего количества полос.\n";
        return 1;
    }

    std::cout << "Введите количество полос в каждом направлении: ";
    lanesPerDirection = safeInputInt();
    if (lanesPerDirection <= 0 || lanesPerDirection > totalLanes) {
        std::cerr << "Ошибка: Пожалуйста, введите корректное положительное число для количества полос в каждом направлении, не превышающее общее количество полос.\n";
        return 1;
    }

    Road road(length, totalLanes, lanesPerDirection, type);
    road.printInfo(LengthUnit::Meters);

    return 0;
}
