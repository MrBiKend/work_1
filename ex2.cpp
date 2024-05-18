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

  // Новый метод для расчета общей площади дороги
  int calculateArea() const {
    return length * lanes;
  }
};

int main() {
  Road road;
  road.setValuesFromInput();
  road.printInfo();
  
  // Выводим общую площадь дороги
  std::cout << "Общая площадь дороги: " << road.calculateArea() << " квадратных метров" << std::endl;
  
  return 0;
}
