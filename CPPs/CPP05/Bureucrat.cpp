/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureucrat.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 18:09:46 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/08 18:09:49 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureucrat.hpp"

Bureucrat::Bureucrat()
	:_name("DefaultName"),
	_grade(0)
{
}

Bureucrat::Bureucrat(std::string name, int grade)
	:_name(name),
	_grade(grade)
{
}

Bureucrat::Bureucrat(const Bureucrat& other)
	:_name(other._name),
	_grade(other._grade)
{
}

Bureucrat::~Bureucrat()
{
}

Bureucrat& Bureucrat::operator=(const Bureucrat& other)
{
	this->_grade = other._grade;
	return *this;
}

const std::string& Bureucrat::getName() const
{
	return _name;
}

const int Bureucrat::getGrade() const
{
	return _grade;
}

std::ostream& operator<<(std::ostream& os, const Bureucrat& Bureucrat)
{
	os << Bureucrat.getName() << ", bureucrat grade" << Bureucrat.getGrade();
	return os;
}

Bureucrat& Bureucrat::operator++()
{
	_grade +=1;
	return *this;
}

Bureucrat& Bureucrat::operator--()
{
	_grade -=1;
	return *this;
}
