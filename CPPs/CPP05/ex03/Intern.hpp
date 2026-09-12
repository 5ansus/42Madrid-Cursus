/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/12 18:01:15 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/12 19:02:04 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
# define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	private:
		Intern();
		~Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);

	public:
		static AForm* makeForm(const std::string& f_type, const std::string& target);
		static AForm* newPresidentialPardonForm(const std::string &target);
		static AForm* newRobotomyRequestForm(const std::string &target);
		static AForm* newShrubberyCreationForm(const std::string &target);

		class FormNotAvailable : public std::exception {
			public:
				const char *what() const throw();
		};
};

#endif
