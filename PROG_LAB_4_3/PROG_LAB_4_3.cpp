#include <iostream>

// Класс комплексного числа
class Complex {
private:
    double real;
    double imag;

public:
    // Конструктор
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // Перегрузка оператора сложения
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Перегрузка оператора вычитания
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Перегрузка оператора умножения
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
    }

    // Перегрузка оператора сравнения ==
    bool operator==(const Complex& other) const {
        return (real == other.real) && (imag == other.imag);
    }

    // Перегрузка оператора сравнения !=
    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    // Дружественные функции для доступа к действительной и мнимой частям
    friend double getReal(const Complex& c);
    friend double getImag(const Complex& c);
};

// Дружественная функция для получения действительной части комплексного числа
double getReal(const Complex& c) {
    return c.real;
}

// Дружественная функция для получения мнимой части комплексного числа
double getImag(const Complex& c) {
    return c.imag;
}

int main() {
    setlocale(LC_ALL, "RUSSIAN");
    // Создание статического объекта
    Complex a(3.0, 4.0);

    // Создание динамического объекта
    Complex* b = new Complex(1.0, 2.0);

    // Выполнение операций с комплексными числами
    Complex sum = a + *b;
    Complex diff = a - *b;
    Complex prod = a * *b;

    // Вывод результатов
    std::cout << "Числа: A: " << getReal(a) << " + " << getImag(a) << "i " << "B: " << getReal(*b) << " + " << getImag(*b) << "i\n";
    std::cout << "Сумма: " << getReal(sum) << " + " << getImag(sum) << "i\n";
    std::cout << "Разность: " << getReal(diff) << " + " << getImag(diff) << "i\n";
    std::cout << "Произведение: " << getReal(prod) << " + " << getImag(prod) << "i\n";

    // Освобождение динамической памяти
    delete b;

}