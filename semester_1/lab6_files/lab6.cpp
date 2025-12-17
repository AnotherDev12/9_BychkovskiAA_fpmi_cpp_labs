#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

bool IsEmptyFile(std::ifstream& file) {
	return file.peek() == EOF;
}

int main() {
	std::ifstream INF("input.txt");
	try {
		if (!INF.is_open()) {
			throw "Could not open the input file.\n";
		}

		if (IsEmptyFile(INF)) {
			throw "Your file is empty.\n";
		}

    std::string line;
    int max_quantity_of_numbers = 0;
    std::vector<int> matching_line_indices;
    std::vector<std::string> result;
    int i = 0;
    while (std::getline(INF, line)) { 
        const std::string& str = line;
        int current_length = 0;
        int max_in_line = 0;

        for (char c : str) {
            if (std::isdigit(c)) {
                current_length++;
                max_in_line = std::max(max_in_line, current_length);
            } else {
                current_length = 0;
            }
        }

        if (max_in_line > max_quantity_of_numbers) {
            max_quantity_of_numbers = max_in_line;
            matching_line_indices.clear();
            matching_line_indices.push_back(i);
        } else if (max_in_line == max_quantity_of_numbers && max_quantity_of_numbers > 0) {
            matching_line_indices.push_back(i);
        }
        result.push_back(str);
        ++i;
    }

    
    if (max_quantity_of_numbers == 0) {
        throw "No lines with numbers in the file.\n";
    }
    std::cout << "Most numbers in a line: " << max_quantity_of_numbers << '\n';

    std::cout << "\nFirst lines with the same length:\n";
    int count = 0;
    for (int index : matching_line_indices) {
        if (count >= 10) { 
            break;
        }
        std::cout << "Line " << (index + 1) << ": " << result[index] << '\n';
        count++;
    }
	}
	catch (const char* msg) {
		std::cerr << "Error! " << msg;
	}
	return 0; 
}
