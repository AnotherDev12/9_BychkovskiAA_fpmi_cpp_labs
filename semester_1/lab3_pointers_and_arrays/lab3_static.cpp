#include <iostream>
#include <random>
#include <math.h>

const int NMAX = 1000;

void inputFromKeyboard(double* arr, int n) {
    std::cout << "Enter " << n << " array elements:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "Element " << i + 1 << ": ";
        if (!(std::cin >> arr[i])) {
            throw "Enter only real numbers!";
        }
    }
}

void fillWithRandom(double* arr, int n) {
    double lower, upper;
    std::cout << "Enter interval boundaries [lower, upper]: ";
    if (!(std::cin >> lower >> upper)) {
        throw "Error! Enter real numbers for boundaries.";
    }

    if (lower > upper) {
        std::swap(lower, upper);
    }

    std::mt19937 gen(time(0));
    std::uniform_real_distribution<double> dist(lower, upper);
    double x = dist(gen);

    std::cout << "Filling the array with random [" << lower << ", " << upper << "]:\n";
    for (int i = 0; i < n; i++) {
        arr[i] = dist(gen);
    }
}

void printArray(const double* arr, int n) {
    std::cout << "Your array: [";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i];
        if (i < n - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

int findMinAbsIndex(const double* arr, int n) {
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

double sumAfterFirstNegative(const double* arr, int n) {
    int firstNegativeIndex = -1;
    double sum = 0.0;

    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            firstNegativeIndex = i;
            break;
        }
    }

    if (firstNegativeIndex == -1) {
        throw "No negative elements\n";
    }
    if (firstNegativeIndex == n - 1) {
        throw "No elements after first negative\n";
    }

    for (int i = firstNegativeIndex + 1; i < n; i++) {
        sum += arr[i];
    }

    return sum;
}


void CompressArray(double* arr, int n, double P) {
    int writeIndex = 0;
    double epsilon = 1e-12;

    for (int i = 0; i < n; i++) {
        if (fabs(arr[i] - P) >= epsilon) {
            arr[writeIndex] = arr[i];
            writeIndex++;
        }
    }

    for (int i = writeIndex; i < n; i++) {
        arr[i] = 0.0;
    }
}

int main() {
  double arr[NMAX];
  int n, choice;

   try {
        std::cout << "Enter the number of elements (1 <= n <= " << NMAX << "): ";

        if (!(std::cin >> n)) {
            throw "Error! Enter an integer number.";
        }

        if (n < 1) {
            throw "Error! Number of array elements must be more than 0";
        }

        if (n > NMAX) {
            throw "Error! Number of array elements can not be more than the constant value!";
        }

        std::cout << "Choose how your array will be filled:\n";
        std::cout << "1 - Enter by hand\n";
        std::cout << "2 - Filling by random numbers\n";
        std::cout << "Your choice: ";
        if (!(std::cin >> choice)) {
            throw "Enter a natural number!";
        }

        if (choice == 1) {
            inputFromKeyboard(arr, n);
        }
        else if (choice == 2) {
            fillWithRandom(arr, n);
        }
        else {
            throw "Incorrect option! Choose 1 or 2!";
        }

        std::cout << "Original: ";
        printArray(arr, n);


        int minAbsIndex = findMinAbsIndex(arr, n);
        if (minAbsIndex != -1) {
            std::cout << "1. Number of the min element: " << minAbsIndex + 1 << std::endl;
            std::cout << "(element arr[" << minAbsIndex << "] = " << arr[minAbsIndex] << ")" << std::endl;
        }
        try {
            std::cout << "2. Sum of the elements after the first negative: " << sumAfterFirstNegative(arr, n) << std::endl;
        }
        catch (const char* msg) {
            std::cerr << msg << "\n";
        }

        double P;
        std::cout << "\nEnter P for deleting: ";
        if (!(std::cin >> P)) {
            throw "Enter a real number for compression!";
        }

        double arrCopy[NMAX];
        for (int i = 0; i < n; i++) {
            arrCopy[i] = arr[i];
        }
        try {
            CompressArray(arrCopy, n, P);
            std::cout << "3. Your array after deleting elements equal to " << P << ":\n";
            printArray(arrCopy, n);
        }
        catch (const char* msg) {
            std::cerr << msg << "\n";
        }
    }
    catch (const char* msg) {
        std::cerr << msg << "\n";
    }
    return 0;
}
