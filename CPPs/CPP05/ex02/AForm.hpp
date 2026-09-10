/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                            :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@42student.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 18:03:24 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/08 18:03:26 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;
		const std::string	_target;


	public:
		AForm(void);
		AForm(std::string name, int gradeSign, int gradeExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		~AForm();
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		const std::string& getName() const;
		void beSigned(const Bureaucrat& b);

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif
