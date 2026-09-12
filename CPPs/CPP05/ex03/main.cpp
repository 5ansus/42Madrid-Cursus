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
#include "Intern.hpp"
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

	AForm *f1, *f2, *f3, *f4;
	f1 = Intern::makeForm("ShrubberyCreationForm", "TestForest");
	b_default.setGrade(1);
	std::cout << b_default << std::endl;
	f1->beSigned(b_default);
	f1->beSigned(b_default);
	f1->execute(b_default);


	std::srand(time(NULL));
	f2 = Intern::makeForm("RobotomyRequestForm", "TestRobot");
	f2->beSigned(b_default);
	f2->execute(b_default);
	f2->execute(b_default);
	f2->execute(b_default);
	f2->execute(b_default);
	f2->execute(b_default);

	f3 = Intern::makeForm("PresidentialPardonForm", "Testperdon");
	f3->beSigned(b_default);
	f3->execute(b_default);

	f4 = Intern::makeForm("Noexisteeee", "TargetDummy");
}
