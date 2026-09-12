/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/12 18:01:15 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/12 18:01:58 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"

#include "Bureaucrat.hpp"

Form::Form()
	: _name("DefaultForm"),
	  _signed(false),
	  _gradeSign(150),
	  _gradeExecute(150) {}

Form::Form(std::string name, int gradeSign, int gradeExecute)
	: _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute) {
	if (gradeSign < 1 || gradeExecute < 1) throw Form::GradeTooHighException();
	if (gradeSign > 150 || gradeExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
	: _name(other._name),
	  _signed(other._signed),
	  _gradeSign(other._gradeSign),
	  _gradeExecute(other._gradeExecute) {
	// if (other._grade < 1)
	// 	throw Form::GradeTooHighException();
	// if (other._grade > 150)
	// 	throw Form::GradeTooLowException();
}

Form::~Form() {}

Form& Form::operator=(const Form& other) {
	if (this != &other) return *this;
	this->_signed = other._signed;
	return *this;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const std::string& Form::getName() const { return _name; }

int Form::getGradeSign() const { return _gradeSign; }

int Form::getGradeExecute() const { return _gradeExecute; }

bool Form::getSigned() const { return _signed; }

void Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_gradeSign) throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& Form) {
	os << "Form " << Form.getName() << " data:" << std::endl
	   << "\tIs signed: " << Form.getSigned() << std::endl
	   << "\tGrade needed for sign: " << Form.getGradeSign() << std::endl
	   << "\tGrade needed for execute: " << Form.getGradeExecute() << std::endl;
	return os;
}
