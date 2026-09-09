
#include "Form.hpp"

int main () {
	Bureaucrat b_default = Bureaucrat();
	std::cout << b_default << std::endl;
	try
	{
		b_default--;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception found:" << std::endl;

		std::cerr << '\t' << e.what() << std::endl;
	}

	std::cout << b_default << std::endl;
	b_default++;
	std::cout << b_default << std::endl;

	Form f_default = Form();
	std::cout << f_default << std::endl;

}
