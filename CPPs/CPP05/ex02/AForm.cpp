/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                            :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 18:09:46 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/08 18:09:49 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("DefaultAForm"), _signed(false), _gradeSign(150), _gradeExecute(150) {}

AForm::AForm(std::string name, int gradeSign, int gradeExecute)
: _name(name), _gradeSign(gradeSign), _gradeExecute(gradeExecute){
	if (gradeSign < 1 || gradeExecute < 1) throw AForm::GradeTooHighException();
	if (gradeSign > 150 || gradeExecute > 150 ) throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other)
: _name(other._name), _signed(other._signed), _gradeSign(other._gradeSign), _gradeExecute(other._gradeExecute){
	// if (other._grade < 1)
	// 	throw AForm::GradeTooHighException();
	// if (other._grade > 150)
	// 	throw AForm::GradeTooLowException();
}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other)
		return *this;
	this->_signed = other._signed;
	return *this;
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

const std::string& AForm::getName() const {
	return _name;
}

int AForm::getGradeSign() const {
	return _gradeSign;
}

int AForm::getGradeExecute() const {
	return _gradeExecute;
}

bool AForm::getSigned() const {
	return _signed;
}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() > this->_gradeSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::ostream& operator<<(std::ostream& os, const AForm& AForm) {
	os << "AForm " << AForm.getName() << " data:" << std::endl
	<< "\tIs signed: " << AForm.getSigned() << std::endl
	<< "\tGrade needed for sign: " << AForm.getGradeSign() << std::endl
	<< "\tGrade needed for execute: " << AForm.getGradeExecute() << std::endl;
	return os;
}

