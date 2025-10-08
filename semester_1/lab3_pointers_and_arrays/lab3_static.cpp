#include <iostream>
#include <random>

const int NMAX = 1000;

void inputFromKeyboard(double arr[], int n) {
    std::cout << "������� " << n << " ��������� �������:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "������� " << i + 1 << ": ";
        if (!(std::cin >> arr[i])) {
            std::cout << "������� ������ ������������ �����!";
            std::exit(0);
        }
    }
}

void fillWithRandom(double arr[], int n) {
    double a, b;
    std::cout << "������� ������� ��������� [a, b]: ";
    if (!(std::cin >> a >> b) && a < 0 && b < 0) {
        std::exit(404);
    }

    if (a > b) {
        std::swap(a, b);
    }

    std::mt19937 gen(time(0));
    std::uniform_real_distribution<double> dist(a, b);
    double x = dist(gen);

    std::cout << "���������� ������� ���������� ������� �� ��������� [" << a << ", " << b << "]:\n";
    for (int i = 0; i < n; i++) {
        arr[i] = dist(gen);
    }
}

void printArray(const double arr[], int n) {
    std::cout << "������: [";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i < n - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

int findMinAbsIndex(const double arr[], int n) {
    if (n == 0) return -1;

    double minAbs = std::abs(arr[0]);
    int maxIndex = 0;

    for (int i = 1; i < n; i++) {
        double currentAbs = std::abs(arr[i]);
        if (currentAbs < minAbs || (currentAbs == minAbs && i > maxIndex)) {
            if (currentAbs < minAbs) {
                minAbs = currentAbs;
            }
            maxIndex = i;
        }
    }

    return maxIndex;
}

double sumAfterFirstNegative(const double arr[], int n) {
    int firstNegativeIndex = -1;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            firstNegativeIndex = i;
            break;
        }
    }

    if (firstNegativeIndex == -1 || firstNegativeIndex == n - 1) {
        return 0;
    }

    double sum = 0;
    for (int i = firstNegativeIndex + 1; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}

void compressArray(double arr[], int n, double P) {
    int writeIndex = 0;


    for (int i = 0; i < n; i++) {
        if (arr[i] != P) {
            arr[writeIndex] = arr[i];
            writeIndex++;
        }
    }

    for (int i = writeIndex; i < n; i++) {
        arr[i] = 0;
    }
}

int main() {
    std::setlocale(LC_ALL, "Russian");

    double arr[NMAX];
    int n, choice;

    std::cout << "������� ���������� ��������� ������� (1 <= n <= " << NMAX << "): ";
    if (!(std::cin >> n) || n < 1 || n > NMAX) {
        std::cout << "������! ������� ����������� ����� ��������� �� 1 �� " << NMAX << "!\n";
        std::exit(0);
    }


    std::cout << "�������� ������ ���������� �������:\n";
    std::cout << "1 - ���� � ����������\n";
    std::cout << "2 - ���������� ���������� �������\n";
    std::cout << "��� �����: ";
    if (!(std::cin >> choice)) {
        std::cout << "����� ������� ���� ������ 1 ��� 2";
        std::exit(0);
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


    int minAbsIndex = findMinAbsIndex(arr, n);
    if (minAbsIndex != -1) {
        std::cout << "1. ����� ������������ �� ������ ��������: " << minAbsIndex + 1 << std::endl;
        std::cout << "(������� arr[" << minAbsIndex << "] = " << arr[minAbsIndex] << ")" << std::endl;
    }

    double sum = sumAfterFirstNegative(arr, n);
    std::cout << "2. ����� ��������� ����� ������� ��������������: " << sum << std::endl;

    double P;
    std::cout << "\n������� ����� P ��� �������� �� �������: ";
    if (!(std::cin >> P)) {
        std::cout << "������� ������ ������������ �����!";
        std::exit(0);
    }

    double arrCopy[NMAX];
    for (int i = 0; i < n; i++) {
        arrCopy[i] = arr[i];
    }

    compressArray(arrCopy, n, P);
    std::cout << "3. ������ ����� �������� ���������, ������ " << P << ":\n";
    printArray(arrCopy, n);


    return 0;
}