#include <iostream> 

int main()
{
    int n;
    int number;
    int m = 0;

    std::cout << "Input a number: ";
    if (!(std::cin >> n)) {
        std::cout << "Input a NUMBER!!!";
        return 1;
    }
    else {
        number = n;

        while (n != 0) {
            m = (m * 10) + (n % 10);
            n /= 10;
        }

        if (number == m) {
            std::cout << number << " is a palindrome.";
        }
        else {
            std::cout << number << " is NOT a palindrome.";
        }
    }
    return 0;
}