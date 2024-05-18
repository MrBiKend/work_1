#include <iostream>
#include <string>
#include <limits> // Для очистки буфера ввода

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
    int lanes;
    int lanesPerDirection;
    RoadType type;

public:
    Road(double l, int n, int nPerDirection, RoadType t) : length(l > 0 ? l : 1), lanes(n > 0 ? n : 1), lanesPerDirection(nPerDirection > 0 ? nPerDirection : 1), type(t) {}

    double getLength() const { return length; }

    int getLanes() const { return lanes; }

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
               " (Общее количество полос: " + std::to_string(lanes) + ")";
    }

    void printInfo(LengthUnit unit) const {
        std::cout << getInfo(unit) << '\n';
    }
};

int main() {
    double length;
    int totalLanes;
    int lanesPerDirection;
    char typeInput;

    std::cout << "Введите тип дороги (u - городская улица, h - автострада): ";
    std::cin >> typeInput;
    RoadType type;
    switch (typeInput) {
        case 'u':
            type = RoadType::UrbanStreet;
            break;
        case 'h':
            type = RoadType::Highway;
            break;
        default:
            std::cerr << "Ошибка: Пожалуйста, введите 'u' для городской улицы или 'h' для автострады.\n";
            return 1;
    }

    std::cout << "Введите длину дороги: ";
    std::cin >> length;
    if (std::cin.fail() || length <= 0) {
        std::cerr << "Ошибка: Пожалуйста, введите корректное положительное число для длины дороги.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }

    std::cout << "Введите общее количество полос: ";
    std::cin >> totalLanes;
    if (std::cin.fail() || totalLanes <= 0) {
        std::cerr << "Ошибка: Пожалуйста, введите корректное положительное число для общего количества полос.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return 1;
    }

    std::cout << "Введите количество полос в каждом направлении: ";
    std::cin >> lanesPerDirection;
    if (std::cin.fail() || lanesPerDirection <= 0 || lanesPerDirection > totalLanes) {
        std::cerr << "Ошибка: Пожалуйста, введите корректное положительное число для количества полос в каждом направлении, не превышающее общее количество полос.\n";
std::cin.clear();
std::cin.ignore(std::numeric_limitsstd::streamsize::max(), '\n');
return 1;
}
Road road(length, totalLanes, lanesPerDirection, type);
road.printInfo(LengthUnit::Meters);

return 0;
