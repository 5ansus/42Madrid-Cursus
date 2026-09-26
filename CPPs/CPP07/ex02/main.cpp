#include "Array.hpp"

#include <iostream>

int main() {

	int * a = new int();
	std::cout << *a << std::endl;
	Array<int> datos(10);
	std::cout << datos << std::endl;
	Array<int> vacio;
	std::cout << vacio << std::endl;
	Array<int> copia = datos;
	copia[5] = 100000;
	std::cout << copia[5] << std::endl;
	std::cout << copia << std::endl;
	std::cout << datos << std::endl;
	std::cout << copia[500] << std::endl;
	delete a;
}
