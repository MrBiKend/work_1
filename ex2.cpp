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

  int getLength() const {
    return length;
  }

  int getLanes() const {
    return lanes;
  }

  void printInfo() const {
    std::cout << "Информация о дороге:" << std::endl;
    std::cout << "Длина: " << getLength() << " метров" << std::endl;
    std::cout << "Полосы: " << getLanes() << std::endl;
  }

  int calculateArea() const {
    return length * lanes;
  }

  // Новый метод для проверки, является ли дорога магистральной
  bool isHighway() const {
    return lanes >= 4;
  }
};

int main() {
  Road road;
  road.setValuesFromInput();
  road.printInfo();
  std::cout << "Общая площадь дороги: " << road.calculateArea() << " квадратных метров" << std::endl;
  
  // Проверяем, является ли дорога магистральной
  if (road.isHighway()) {
    std::cout << "Это магистральная дорога." << std::endl;
  } else {
    std::cout << "Это не магистральная дорога." << std::endl;
  }
  
  return 0;
}
