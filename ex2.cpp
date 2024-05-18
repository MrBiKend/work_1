#include <iostream>

class Road {
private:
  int length;
  int lanes;

public:
  Road() {}

  void setValuesFromInput() {
    std::cout << "Введите длину дороги (в метрах): ";
    std::cin >> length;

    std::cout << "Введите количество полос: ";
    std::cin >> lanes;
  }

  int getLength() {
    return length;
  }

  int getLanes() {
    return lanes;
  }

  // Новый метод для вывода информации о дороге
  void printInfo() {
    std::cout << "Информация о дороге:" << std::endl;
    std::cout << "Длина: " << getLength() << " метров" << std::endl;
    std::cout << "Полосы: " << getLanes() << std::endl;
  }
};

int main() {
  Road road;
  road.setValuesFromInput();
  road.printInfo();
  return 0;
}
