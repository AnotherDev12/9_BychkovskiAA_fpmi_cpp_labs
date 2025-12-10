#include <iostream>
#include <string>
#include <vector>

bool isValidEvenNumber(const std::string& num) {
    if (num.empty()) return false;

    for (char c : num) {
        if (c < '0' || c > '9')
            return false;
    }

    if (num.length() > 1 && num[0] == '0')
        return false;

    char last = num.back();
    return (last == '0' || last == '2' || last == '4' || last == '6' || last == '8');
}

int main() {
    std::string str;
    std::cout << "Enter your string: ";
    std::getline(std::cin, str);

    std::vector<std::string> results;
    std::string current;

    for (char c : str) {
        if (c >= '0' && c <= '9') {
            current += c;
        }
        else {
            if (!current.empty()) {
                if (isValidEvenNumber(current)) {
                    results.push_back(current);
                }
                current.clear();
            }
        }
    }

    if (!current.empty()) {
        if (isValidEvenNumber(current)) {
            results.push_back(current);
        }
    }

    std::cout << "Your results: ";
    for (size_t i = 0; i < results.size(); ++i) {
        if (i > 0) {
            std::cout << ",,";
        }
        std::cout << results[i];
    }
    std::cout << std::endl;

    return 0;
}