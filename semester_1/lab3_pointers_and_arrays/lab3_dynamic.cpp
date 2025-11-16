#include <iostream>
#include <random>

void printArray(const double* arr, int n) {
    std::cout << "Your array: [";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i < n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}


void inputFromKeyboard(double* arr, int n) {
    std::cout << "Enter " << n << " array elements:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Element " << i + 1 << ": ";
        if (!(std::cin >> arr[i])) {
            throw "Enter only real numbers";
        }
    }
}

void fillWithRandom(double* arr, int n) {
    double lower, upper;
    std::cout << "Enter interval boundaries [lower, upper]: ";
    if (!(std::cin >> lower >> upper)) {
        throw "Input error!";
    }

    if (lower > upper) {
        std::swap(lower, upper);
    }

    std::mt19937 gen(time(0));
    std::uniform_real_distribution<double> dist(lower, upper);

    std::cout << "Filling the array with random numbers from thr interval [" << lower << ", " << upper << "]:\n";
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
        std::cout << "No negative numbers.\n";
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

    int n, choice;
    try {
        std::cout << "Enter the amount of the elements: ";
        if (!(std::cin >> n)) {
            throw "Enter the amount of elements!";
        }

        if (n < 1) {
            throw "Amount of elements can not be less than 1.";
        }


        double* arr = new double[n];

        std::cout << "Choose how your array will be filled:\n";
        std::cout << "1 - Enter by hand\n";
        std::cout << "2 - Filling by random numbers\n";
        std::cout << "Your choice: ";
        if (!(std::cin >> choice)) {
            throw "Enter a number.";
        }

        if (choice == 1) {
            inputFromKeyboard(arr, n);
        }
        else {
            if (choice == 2) {
                fillWithRandom(arr, n);
            }

            else {
                throw "Your task was to enter 1 or 2!!!";
            }
        }

        std::cout << "Original ";
        printArray(arr, n);

        int maxAbsIndex = findMaxAbsIndex(arr, n);
        if (maxAbsIndex != -1) {
            std::cout << "1. Number of the max element: " << maxAbsIndex + 1 << std::endl;
            std::cout << "   (element arr[" << maxAbsIndex << "] = " << arr[maxAbsIndex]
                << ", abs = " << std::abs(arr[maxAbsIndex]) << ")" << std::endl;
        }

        double sum = sumBeforeFirstPositive(arr, n);
        std::cout << "2. Sum of the elements before the first positive: " << sum << std::endl;

        double P;
        std::cout << "\nEnter P: ";
        if (!(std::cin >> P)) {
            throw "Enter a number for compression!!!";
        }

        arr = insertAfterLastNegative(arr, n, P);

        std::cout << "3.Your array after insertig  " << P << " after the last negative:\n";
        printArray(arr, n);

        delete[] arr;
    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
    return 0;
}