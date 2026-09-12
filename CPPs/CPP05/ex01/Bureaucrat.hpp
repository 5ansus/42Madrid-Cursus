/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/12 18:01:15 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/12 18:01:58 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREUCRAT_HPP
#define BUREUCRAT_HPP

#include <iostream>
#include <string>

class Form;

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
	void signForm(Form& f);

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
