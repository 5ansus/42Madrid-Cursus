#include "iter.hpp"

template <typename T>
void print_values(T* array, int len){

	for (int i  = 0; i < len; i++){
		std::cout << "Valor de n" << i << ": " << array[i] << std::endl;
	}
	std::cout << "--------------------------" << std::endl;
}

template <typename T>
void add_one(T &value){
	value += 1;
}

template <typename T>
void print_one(const T &value){
	std::cout << value << std::endl;
}

int main() {
	const int const_values[] = {1, 2, 3, 4};
	int values[] = {-1, -2, -3, -4};
	int *values_ptr = new int[4];
	values_ptr[0] = 0;
	values_ptr[1] = 10;
	values_ptr[2] = 20;
	values_ptr[3] = 30;
	iter<int>(values, 4, print_one);
	std::cout << "--------------------------" << std::endl;
	iter<int>(const_values, 4, print_one);
	std::cout << "--------------------------" << std::endl;
	iter<int>(values_ptr, 4, print_one);
	std::cout << "--------------------------" << std::endl;

	iter<int>(values, 4, add_one);
	print_values(values, 4);
	// iter<int>(const_values, 4, add_one);
	// print_values(const_values, 4);
	iter<int>(values_ptr, 4, add_one);
	print_values(values_ptr, 4);
	delete[] values_ptr;
}
