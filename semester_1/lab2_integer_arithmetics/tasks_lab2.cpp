#include <iostream>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "Your number must be positive!" << std::endl;
        return 1;
    }

    std::cout << "Mersenne numbers <= " << n << ":" << std::endl;

    int count = 0;
    int p = 2;

    while (true) {
        int mersenne = pow(2, p) - 1;

        if (mersenne > n) break;

        if (isPrime(p) && isPrime(mersenne)) {
            std::cout << mersenne << " ";
            count++;
        }

        p++;
    }

    std::cout << std::endl;

    if (count == 0) {
        std::cout << "No numbers found" << std::endl;
    }
    else {
        std::cout << "There are " << count << " numbers" << std::endl;
    }

    return 0;
}