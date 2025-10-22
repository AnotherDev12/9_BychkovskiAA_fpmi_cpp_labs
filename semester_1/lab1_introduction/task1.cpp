#include <iostream>

int main() {
    int a; int b; int d;
    if (b < a) {
        int n = a;
        a = b;
        b = n;
    }
    else if (d == 0) {
        std::cout << "d can't be equal 0!\n";
        std::exit(1);
    }

    while (b > a) {
        if ((a % 3) == 0) {
            std::cout << a << " ";
        }
        a += d;
    }

    std::cout << "\n";
}
