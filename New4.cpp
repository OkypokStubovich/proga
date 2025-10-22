#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

/**
* Вычисляет значение функции y = sin(ln(x)) - cos(ln(x)) + 2*ln(x)
* @param x - аргумент функции
* @return значение функции в точке x
*/
double functionY(const double x);

/**
* Табулирует функцию на интервале [x0, xend] с шагом step
* @param x0 - начальное значение x
* @param xend - конечное значение x
* @param step - шаг табуляции
*/
void tabulateFunction(const double x0, const double xend, const double step);

/**
* @brief считывает значение с клавиатуры
* @return введенное значение
*/
double get();

/**
* @brief Точка входа в программу
* @return возвращает 0, если программа выполнена верно
*/

int main() {
    cout << "Введите начальное значение x: ";
    double x0 = get();
    cout << "Введите конечное значение x: ";
    double xend = get();
    cout << "Введите шаг ∆x: ";
    double step = get();
    
    if (step <= 0) {
        cout << "Шаг должен быть положительным" << endl;
        return 1;
    }
    if (x0 > xend) {
        cout << "Начальное значение не может быть больше конечного" << endl;
        return 1;
    }
    
    tabulateFunction(x0, xend, step);
    return 0;
}

void tabulateFunction(double x0, double xend, double step) {
    cout << "x | y" << endl;
    
    for (double x = x0; x <= xend + step/2; x += step) {
        cout << x << " | ";
        
        // Проверка области определения: ln(x) определен только для x > 0
        if (x <= 0) {
            cout << "Нет решения (x должен быть > 0)" << endl;
        } else {
            double y = functionY(x);
            cout << y << endl;
        }
    }
}

double functionY(double x) {
    double ln_x = log(x); // ln(x) - натуральный логарифм
    return sin(ln_x) - cos(ln_x) + (2 * ln_x);
}

double get() {
    double x = 0;
    cin >> x;
    if (cin.fail()) {
        cout << "Ошибка: введите корректное число." << endl;
        abort();
    }
    return x;
}
