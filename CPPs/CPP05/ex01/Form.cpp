/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                       :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 18:09:46 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/08 18:09:49 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("DefaultName"), _signed(false), _gradeSign(150), _gradeExecute(150) {}

Form::Form(std::string name, int gradeSign, int gradeExecute)
: _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute){
	if (gradeSign < 1 || gradeExecute < 1) throw Form::GradeTooHighException();
	if (gradeSign > 150 || gradeExecute > 150 ) throw Form::GradeTooLowException();
}

Form::Form(const Form& other)
: _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute){
	// if (other._grade < 1)
	// 	throw Form::GradeTooHighException();
	// if (other._grade > 150)
	// 	throw Form::GradeTooLowException();
}

Form::~Form() {}

Form& Form::operator=(const Form& other) {
	if (this != &other)
		return *this;
	this->_signed = other._signed;
	return *this;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Error: The Grade would be too high (maximum grade is 1)";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Error: The Grade would be too low (minimun grade is 150)";
}

const std::string& Form::getName() const {
	return _name;
}

int Form::getGradeSign() const {
	return _gradeSign;
}

int Form::getGradeExecute() const {
	return _gradeExecute;
}

bool Form::getSigned() const {
	return _signed;
}

void Form::beSigned(Bureaucrat b) {
	if (b.getGrade() > this->_gradeSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& Form) {
	os << "Form " << Form.getName() << " data:" << std::endl
	<< "\tIs signed: " << Form.getSigned() << std::endl
	<< "\tGrade needed for sign: " << Form.getGradeSign() << std::endl
	<< "\tGrade needed for execute: " << Form.getGradeExecute() << std::endl;
	return os;
}

