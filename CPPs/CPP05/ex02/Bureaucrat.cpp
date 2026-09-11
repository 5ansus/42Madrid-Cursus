/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                       :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 18:09:46 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/08 18:09:49 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("DefaultBureucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade) {
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
	if (grade > 150) throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade) {
	// if (other._grade < 1)
	// 	throw Bureaucrat::GradeTooHighException();
	// if (other._grade > 150)
	// 	throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		return *this;
	this->_grade = other._grade;
	return *this;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "Error: The Grade would be too high (maximum grade is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "Error: The Grade would be too low (minimun grade is 150)";
}

const std::string& Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::setGrade(int grade) {
	this->_grade = grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat) {
	os << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return os;
}

Bureaucrat Bureaucrat::operator++() {
	if (_grade <= 1) throw Bureaucrat::GradeTooHighException();
	_grade -= 1;
	return *this;
}

Bureaucrat Bureaucrat::operator++(int) {
	if (_grade <= 1) throw Bureaucrat::GradeTooHighException();
	Bureaucrat ret = *this;
	_grade -= 1;
	return ret;
}

Bureaucrat Bureaucrat::operator--(int) {
	if (_grade >= 150) throw Bureaucrat::GradeTooLowException();
	Bureaucrat ret = *this;
	_grade += 1;
	return ret;
}

Bureaucrat Bureaucrat::operator--() {
	if (_grade >= 150) throw Bureaucrat::GradeTooLowException();
	_grade += 1;
	return *this;
}

void Bureaucrat::signAForm(AForm& f){

	try{
		f.beSigned(*this);
		std::cout << getName() << " signed " << f.getName() << std::endl;
	}catch (const std::exception& e)
	{
		std::cout << getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl ;
	}
}

void Bureaucrat::executeForm(AForm const & form){

	try{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}catch (const std::exception& e)
	{
		std::cout << getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl ;
	}
}
