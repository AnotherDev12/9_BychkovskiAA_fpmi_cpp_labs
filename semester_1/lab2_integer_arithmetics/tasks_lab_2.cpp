#include <iostream>

bool Prime(int num) {
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

    if (!(std::cin >> n) || n < 1) {
        std::cout << "Enter a posititve number!!!" << std::endl;
        return 1;
    }

    std::cout << "Mersenne numbers <= " << n << ":" << std::endl;

    int quantity = 0;
    int p = 2;

    while (true) {
        int mersenne = pow(2, p) - 1;

        if (mersenne > n) break;

        if (Prime(p) && Prime(mersenne)) {
            std::cout << mersenne << " ";
            quantity++;
        }
        p++;
    }

    std::cout << std::endl;

    if (quantity == 0) {
        std::cout << "No numbers found :(" << std::endl;
    }
    else {
        std::cout << "There are " << quantity << " numbers" << std::endl;
    }
    return 0;
}