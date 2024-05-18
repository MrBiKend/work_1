#include <iostream>
#include <string>

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

  // Метод для получения информации о дороге в виде строки
  std::string getInfo() const {
    return "Длина дороги: " + std::to_string(length) + " метров\n" +
           "Количество полос: " + std::to_string(lanes);
  }

  // Метод для вывода информации о дороге
  void printInfo() const {
    std::cout << getInfo() << std::endl;
  }
};

int main() {
  int length;
  int lanes;

  std::cout << "Введите длину дороги (в метрах): ";
  std::cin >> length;
  if (length <= 0) {
    std::cerr << "Ошибка: длина дороги должна быть положительным числом." << std::endl;
    return 1;
  }

  std::cout << "Введите количество полос: ";
  std::cin >> lanes;
  if (lanes <= 0) {
    std::cerr << "Ошибка: количество полос должно быть положительным числом." << std::endl;
    return 1;
  }

  // Создаем объект дороги
  Road road(length, lanes);

  // Выводим информацию о дороге
  road.printInfo();

  return 0;
}
