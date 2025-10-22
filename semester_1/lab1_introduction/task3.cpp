#include <iostream>

long long element(long long number, long long x) {
    long long result = 1;
    if (x == 0) return 1;

    while (x > 0) {
        if (x & 1) {
            result *= number;
            x--;
        }
        else {
            number *= number;
            x /= 2;
        }
    }
    return result;
}

int main() {
    int n;

    if (!(std::cin >> n) || n <= 0) {
        std::cout << "Error\n";
        std::exit(1);
    }

    long long sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += element(i, i);
    }
    std::cout << sum << '\n';
}

/*

Из условия видно, что сумма S растет очень быстро. Для n = 5, 15 выводится адекватный результат,
но уже при 100, 200, 500, 1000 мы видим неверные отрицательные и положительные ответы. Это происходит
из за переполнения типа long long уже при маленьком n = 16(программа выдает сумму при n = 15 и n = 16 равной).

Результаты выполнения для некоторых n:
5
3413
15
449317984130199828
16
449317984130199828
100
5146238793346310720
200
-4137211680396737972
500
6378643303420889616
1000
-6492551511798476564

*/