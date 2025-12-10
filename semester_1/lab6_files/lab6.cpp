#include <iostream>
#include <fstream>
#include <string>


bool IsEmptyFile(std::ifstream& file) {
	return file.peek() == EOF;
}

int main() {

	std::ifstream INF("input.txt");
	std::ofstream OUTF("output.txt");
	try {
		if (!INF.is_open()) {
			throw "Could not open the input file.";
		}

		if (!OUTF.is_open()) {
			throw "Could not open the output file.";
		}

		if (IsEmptyFile(INF)) {
			throw "Your file is empty.";
		}

		std::string line;
		while (std::getline(INF, line)) {

		}



	}
	catch (const char* msg) {
		std::cerr << "Error! " << msg;
	}
	return 0;