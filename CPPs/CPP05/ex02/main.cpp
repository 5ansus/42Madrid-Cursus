/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/12 18:01:15 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/12 18:38:24 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	f1.beSigned(b_default);
	f1.beSigned(b_default);
	f1.execute(b_default);


	std::srand(time(NULL));
	RobotomyRequestForm f2("TestRobot");
	f2.beSigned(b_default);
	f2.execute(b_default);
	f2.execute(b_default);
	f2.execute(b_default);
	f2.execute(b_default);
	f2.execute(b_default);

	PresidentialPardonForm f3("Testperdon");
	f3.beSigned(b_default);
	f3.execute(b_default);
}
