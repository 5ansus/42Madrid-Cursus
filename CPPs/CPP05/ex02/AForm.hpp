/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/12 18:01:15 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/12 18:01:58 by sanferna         ###   ########.fr       */
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
		const std::string	_target;
		bool				_signed;
		const int			_gradeSign;
		const int			_gradeExecute;

	public:
		AForm(void);
		AForm(std::string name, std::string target, int gradeSign, int gradeExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();
		bool getSigned() const;
		int getGradeSign() const;
		int getGradeExecute() const;
		const std::string& getName() const;
		const std::string& getTarget() const;
		void beSigned(const Bureaucrat& b);
		virtual void execute(Bureaucrat const & executor) const = 0;

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
