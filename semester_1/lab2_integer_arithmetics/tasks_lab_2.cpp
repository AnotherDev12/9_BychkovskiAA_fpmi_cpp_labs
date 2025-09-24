#include <iostream>
#include <cmath>

bool Prime(int x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;

    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
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

    int q = 0;
    int p = 2;

    while (true) {
        int mersenne = pow(2, p) - 1;

        if (mersenne > n) break;

        if (Prime(p) && Prime(mersenne)) {
            std::cout << mersenne << " ";
            q++;
        }
        p++;
    }

    std::cout << std::endl;

    if (q == 0) {
        std::cout << "No numbers found :(" << std::endl;
    }
    else {
        std::cout << "There are " << q << " numbers" << std::endl;
    }
    return 0;
}