/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                      :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@42student.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 18:03:24 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/08 18:03:26 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat& operator=(const Bureaucrat& other);
		Bureaucrat operator++();
		Bureaucrat operator++(int);
		Bureaucrat operator--(int);
		Bureaucrat operator--();
		~Bureaucrat();
		const std::string& getName() const;
		int getGrade() const;
		void setGrade(int grade);
		void signAForm(AForm& f);
		void executeForm(AForm const & form);

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif
