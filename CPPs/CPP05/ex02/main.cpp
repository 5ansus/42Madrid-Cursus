#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

	AForm f1 = AForm("AFormularioLevel1", 1, 1);
	std::cout << f1 << std::endl;
	b_default.signAForm(f1);
	std::cout << f1 << std::endl;

	AForm f_default;
	std::cout << f_default << std::endl;
	b_default.signAForm(f_default);
	std::cout << f_default << std::endl;


}
