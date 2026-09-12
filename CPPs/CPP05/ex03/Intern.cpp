/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/12 18:01:15 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/12 19:02:15 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"


AForm* Intern::newPresidentialPardonForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::newRobotomyRequestForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::newShrubberyCreationForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

const char* Intern::FormNotAvailable::what() const throw()
{
	return "ERROR: Form doesn't exists";
}

AForm* Intern::makeForm(const std::string& f_type, const std::string& target)
{
	std::string catalog[] = {
		NAME_PRED,
		NAME_ROB,
		NAME_SHRU,
	};

	AForm* (*f_catalog[])(const std::string& target) = {
		newPresidentialPardonForm,
		newRobotomyRequestForm,
		newShrubberyCreationForm,
	};

	int num_forms_disp = sizeof(f_catalog) / sizeof(f_catalog[0]);

	for (int i = 0; i < num_forms_disp; i++)
	{
		if (f_type == catalog[i])
			return (f_catalog[i](target));
	}
	throw Intern::FormNotAvailable();
	return NULL;
}
