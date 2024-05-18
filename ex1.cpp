#include <iostream>

// Класс дороги
class Road {
private:
  int length; // Длина дороги в метрах
  int lanes;  // Количество полос на дороге

public:
  // Конструктор с проверкой
  Road(int l, int n) : length(l > 0 ? l : 1), lanes(n > 0 ? n : 1) {}

  // Метод для получения длины дороги
  int getLength() const {
    return length;
  }

  // Метод для получения количества полос на дороге
  int getLanes() const {
    return lanes;
  }

  // Метод для вывода информации о дороге
  void printInfo() const {
    std::cout << "Длина дороги: " << getLength() << " метров" << std::endl;
    std::cout << "Количество полос: " << getLanes() << std::endl;
  }
};

int main() {
  // Создаем объект дороги
  Road road(1000, 2);

  // Выводим информацию о дороге
  road.printInfo();

  return 0;
}
