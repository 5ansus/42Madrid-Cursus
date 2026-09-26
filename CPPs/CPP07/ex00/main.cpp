#include "whatever.hpp"

void print_values(int n1, int n2){

	std::cout << "Valor de n1: " << n1 << std::endl;
	std::cout << "Valor de n2: " << n2 << std::endl;
	std::cout << "--------------------------" << std::endl;
}

int main() {
	int n1 = 5;
	int n2 = 7;

	print_values(n1, n2);
	swap(n1, n2);
	print_values(n1, n2);

	std::cout << "El min es: " << min(n1, n2) << std::endl;
	std::cout << "El max es: " << max(n1, n2) << std::endl;

}
