#include <iostream>
#include <random>

void printArray(const double* arr, int n) {
    std::cout << "Массив: [";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i < n - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}


void inputFromKeyboard(double* arr, int n) {
    std::cout << "Введите " << n << " элементов массива:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Элемент " << i + 1 << ": ";
        if (!(std::cin >> arr[i])) {
            std::cout << "Вводите только вещественные числа!";
            std::exit(0);
        }
    }
}

void fillWithRandom(double* arr, int n) {
    double a, b;
    std::cout << "Введите границы интервала [a, b]: ";
    if (!(std::cin >> a >> b)) {
        std::cout << "Ошибка ввода!";
        std::exit(404);
    }

    if (a > b) {
        std::swap(a, b);
    }

    std::mt19937 gen(time(0));
    std::uniform_real_distribution<double> dist(a, b);

    std::cout << "Заполнение массива случайными числами из интервала [" << a << ", " << b << "]:\n";
    for (int i = 0; i < n; i++) {
        arr[i] = dist(gen);
    }
}

int findMaxAbsIndex(const double* arr, int n) {
    if (n == 0) return -1;

    double maxAbs = std::abs(arr[0]);
    int minIndex = 0;

    for (int i = 1; i < n; i++) {
        double currentAbs = std::abs(arr[i]);
        if (currentAbs > maxAbs || (currentAbs == maxAbs && i < minIndex)) {
            if (currentAbs > maxAbs) {
                maxAbs = currentAbs;
            }
            minIndex = i;
        }
    }

    return minIndex;
}

double sumBeforeFirstPositive(const double* arr, int n) {
    int firstPositiveIndex = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            firstPositiveIndex = i;
            break;
        }
    }

    if (firstPositiveIndex == -1 || firstPositiveIndex == 0) {
        return 0;
    }

    double sum = 0;
    for (int i = 0; i < firstPositiveIndex; i++) {
        sum += arr[i];
    }

    return sum;
}

double* insertAfterLastNegative(double* arr, int& n, double P) {
    int lastNegativeIndex = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            lastNegativeIndex = i;
        }
    }

    if (lastNegativeIndex == -1) {
        std::cout << "Отрицательных элементов не найдено. Вставка не выполнена.\n";
        return arr;
    }

    double* newArr = new double[n + 1];

    for (int i = 0; i <= lastNegativeIndex; i++) {
        newArr[i] = arr[i];
    }

    newArr[lastNegativeIndex + 1] = P;
    for (int i = lastNegativeIndex + 1; i < n; i++) {
        newArr[i + 1] = arr[i];
    }

    n++;

    delete[] arr;

    return newArr;
}

int main() {
    setlocale(LC_ALL, "Russian");

    int n, choice;
    std::cout << "Введите количество элементов массива: ";
    if (!(std::cin >> n) || n < 1) {
        std::cout << "Ошибка! Введите натуральное число элементов!\n";
        return 1;
    }

    double* arr = new double[n];

    std::cout << "Выберите способ заполнения массива:\n";
    std::cout << "1 - Ввод с клавиатуры\n";
    std::cout << "2 - Заполнение случайными числами\n";
    std::cout << "Ваш выбор: ";
    if (!(std::cin >> choice)) {
        std::cout << "Ошибка ввода!";
        delete[] arr;
        return 1;
    }

    if (choice == 1) {
        inputFromKeyboard(arr, n);
    }
    else if (choice == 2) {
        fillWithRandom(arr, n);
    }
    else {
        std::cout << "Неверный выбор! Используется ввод с клавиатуры.\n";
        inputFromKeyboard(arr, n);
    }


    std::cout << "Исходный ";
    printArray(arr, n);

    int maxAbsIndex = findMaxAbsIndex(arr, n);
    if (maxAbsIndex != -1) {
        std::cout << "1. Номер максимального по модулю элемента: " << maxAbsIndex + 1 << std::endl;
        std::cout << "   (элемент arr[" << maxAbsIndex << "] = " << arr[maxAbsIndex]
            << ", модуль = " << std::abs(arr[maxAbsIndex]) << ")" << std::endl;
    }

    double sum = sumBeforeFirstPositive(arr, n);
    std::cout << "2. Сумма элементов до первого положительного: " << sum << std::endl;

    double P;
    std::cout << "\nВведите число P для вставки после последнего отрицательного: ";
    if (!(std::cin >> P)) {
        std::cout << "Ошибка ввода!";
        delete[] arr;
        return 1;
    }

    arr = insertAfterLastNegative(arr, n, P);

    std::cout << "3. Массив после вставки " << P << " после последнего отрицательного:\n";
    printArray(arr, n);

    delete[] arr;

    return 0;
}