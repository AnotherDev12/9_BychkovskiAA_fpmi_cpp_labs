#include <iostream>
#include <random>

void printArray(const double* arr, int n) {
    std::cout << "������: [";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i < n - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}


void inputFromKeyboard(double* arr, int n) {
    std::cout << "������� " << n << " ��������� �������:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "������� " << i + 1 << ": ";
        if (!(std::cin >> arr[i])) {
            std::cout << "������� ������ ������������ �����!";
            std::exit(0);
        }
    }
}

void fillWithRandom(double* arr, int n) {
    double a, b;
    std::cout << "������� ������� ��������� [a, b]: ";
    if (!(std::cin >> a >> b)) {
        std::cout << "������ �����!";
        std::exit(404);
    }

    if (a > b) {
        std::swap(a, b);
    }

    std::mt19937 gen(time(0));
    std::uniform_real_distribution<double> dist(a, b);

    std::cout << "���������� ������� ���������� ������� �� ��������� [" << a << ", " << b << "]:\n";
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
        std::cout << "������������� ��������� �� �������. ������� �� ���������.\n";
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
    std::cout << "������� ���������� ��������� �������: ";
    if (!(std::cin >> n) || n < 1) {
        std::cout << "������! ������� ����������� ����� ���������!\n";
        return 1;
    }

    double* arr = new double[n];

    std::cout << "�������� ������ ���������� �������:\n";
    std::cout << "1 - ���� � ����������\n";
    std::cout << "2 - ���������� ���������� �������\n";
    std::cout << "��� �����: ";
    if (!(std::cin >> choice)) {
        std::cout << "������ �����!";
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
        std::cout << "�������� �����! ������������ ���� � ����������.\n";
        inputFromKeyboard(arr, n);
    }


    std::cout << "�������� ";
    printArray(arr, n);

    int maxAbsIndex = findMaxAbsIndex(arr, n);
    if (maxAbsIndex != -1) {
        std::cout << "1. ����� ������������� �� ������ ��������: " << maxAbsIndex + 1 << std::endl;
        std::cout << "   (������� arr[" << maxAbsIndex << "] = " << arr[maxAbsIndex]
            << ", ������ = " << std::abs(arr[maxAbsIndex]) << ")" << std::endl;
    }

    double sum = sumBeforeFirstPositive(arr, n);
    std::cout << "2. ����� ��������� �� ������� ��������������: " << sum << std::endl;

    double P;
    std::cout << "\n������� ����� P ��� ������� ����� ���������� ��������������: ";
    if (!(std::cin >> P)) {
        std::cout << "������ �����!";
        delete[] arr;
        return 1;
    }

    arr = insertAfterLastNegative(arr, n, P);

    std::cout << "3. ������ ����� ������� " << P << " ����� ���������� ��������������:\n";
    printArray(arr, n);

    delete[] arr;

    return 0;
}