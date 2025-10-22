#include <iostream> 

int main() {

    int n, a, b, sum, pr;
    a = 1;
    b = 1;
    sum = 0;
    pr = b;
    std::cout << "Enter your n: ";
    std::cin >> n;
    while (a <= n)
    {
        if (a % 2 == 0) {
            sum = sum + a;
        }
        a++;
    }
    std::cout << "The sum of the even numbers in the interval [1;n] = " << sum << std::endl;
    while (b <= n) {
        pr = pr * b;
        b = b + 2;
    }
    std::cout << "The product of the uneven numbers in the interval [1;n] = " << pr << std::endl;
    return 0;
}