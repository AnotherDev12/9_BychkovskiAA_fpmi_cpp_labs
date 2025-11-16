#include <iostream> 
#include <random>
#include <iomanip>

void input_sides(int& rows, int& columns) {
	if (!(std::cin >> rows || rows < 1)) {
		std::cout << "Invalid input!";
		std::exit(1);
	}

	if (!(std::cin >> rows || rows < 1)) {
		std::cout << "Invalid input!";
		std::exit(1);
	}
}

void allocate_matrix(int**& matrix, int rows, int columns) {
	matrix = new int* [rows];
	for (int i = 0; i < rows; ++i) {
		matrix[i] = new int[columns];
	}
}

void delete_the_matrix(int** matrix, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

void input_boundaries_for_random(int** matrix, int rows, int columns, int &lower, int &upper) {
	std::cout << "Enter the boundaries for random: ";
	if (!(std::cin >> lower >> upper)) {
		std::cout << "Invalid input!";
		delete_the_matrix(matrix, rows, columns);
		std::exit(1);
	}

	if (lower > upper) {
		std::swap(lower, upper);
	}
}

void fill_the_matrix_with_random_numbers(int** matrix, int rows, int columns, std::mt19937* gen) {
	int lower, upper;
	input_boundaries_for_random(matrix, rows, columns, lower, upper);

	std::uniform_int_distribution<int> dist(lower, upper);
	std::cout << "Filling the matrix with random numbers from the interval [" << lower << ", " << upper << "]:\n";
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			matrix[i][j] = dist(*gen);
		}
	}
}

int get_variant() {
	int variant;
	std::cout << "1 - fill with random numbers\n";
	std::cout << "2 - fill manually\n";
	if (!(std::cin >> variant)) {
		std::cout << "Next time enter 1 or 2 >:(";
		std::exit(1);
	}
	return variant;
}

void manual_input(int** matr, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (!(std::cin >> matr[i][j])) {
				std::cout << "Next time enter integers :(";
				std::exit(404);
			}
		}
	}
}

void print_matrix(int** matrix, int rows, int columns) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			std::cout << std::setw(5) << matrix[i][j];
		}
		std::cout << std::endl;
	}
}

void choosing_variants_of_input(int** matrix, int rows, int columns) {
	int variant = get_variant();

	if (variant == 1) {

		std::random_device rd;
		std::mt19937 gen(rd());
		fill_the_matrix_with_random_numbers(matrix, rows, columns, &gen);

		std::cout << "\nThis is your random numbers:\n";
		print_matrix(matrix, rows, columns);
	}
	else if (variant == 2) {

		std::cout << "Then enter your elements:\n";
		manual_input(matrix, rows, columns);

	}
	else {
		std::cout << "I asked to you enter 1 or 2 :(";
		std::exit(1);
	}
}

int sum_without_zeros(int** matrix, int rows, int columns) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		bool zero_is_found = false;
		for (int j = 0; j < columns; j++) {
			if (matrix[i][j] == 0) {
			zero_is_found = true;
			break;
		    }
		}

		if (!zero_is_found) {
			for (int j = 0; j < columns; j++) {
				sum += matrix[i][j];
			}
		}
	}


	return sum;
}
	

void swap_columns(int** matrix, int rows, int columns) {
	for (int j = 0; j < columns / 2; j++) {
		int opposite_column = columns - 1 - j;
		for (int i = 0; i < rows; i++) {
			std::swap(matrix[i][j], matrix[i][opposite_column]);
		}
	}
}

int main() {
	int** matrix;
	int rows;
	int columns;
	std::cout << "Please, enter the matrix measurments: ";
	std::cin >> rows;
	std::cin >> columns;
	allocate_matrix(matrix, rows, columns);
	choosing_variants_of_input(matrix, rows, columns);
	sum_without_zeros(matrix, rows, columns);
	std::cout << "Sum of the elements in rows without 0 = " << sum_without_zeros(matrix, rows, columns);
	std::cout << std::endl;
	swap_columns(matrix, rows, columns);
	print_matrix(matrix, rows, columns);
	delete_the_matrix(matrix, rows, columns);
	return 0;
}