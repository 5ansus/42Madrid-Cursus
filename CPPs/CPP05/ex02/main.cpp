#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <ctime>

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

	ShrubberyCreationForm f1("TestFile");
	b_default.setGrade(1);
	std::cout << b_default << std::endl;
	f1.execute(b_default);


	std::srand(time(NULL));
	RobotomyRequestForm f2("TestRobot");
	f2.execute(b_default);
	f2.execute(b_default);
	f2.execute(b_default);
	f2.execute(b_default);
	f2.execute(b_default);

	PresidentialPardonForm f3("Testperdon");
	f3.execute(b_default);
}
