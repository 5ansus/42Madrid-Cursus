/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:09:50 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:10:38 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_hitPoints = _fragTrapBaseHitPoints;
	_energyPoints = _fragTrapBaseEnergyPoints;
	_attackDamage = _fragTrapBaseAttackDamage;
	std::cout << _getClassName() << " default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name) {
	_hitPoints = _fragTrapBaseHitPoints;
	_energyPoints = _fragTrapBaseEnergyPoints;
	_attackDamage = _fragTrapBaseAttackDamage;
	std::cout << _getClassName() << " " << _name << " constructor called"
			  << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << _getClassName() << " copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << _getClassName() << " copy assignment operator called"
			  << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << _getClassName() << " " << _name << " destructor called"
			  << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << _getClassName() << " " << _name
			  << " wants to high five! ¿Aceptas? (y/n): ";
	std::string respuesta;
	std::getline(std::cin, respuesta);
	if (respuesta == "y" || respuesta == "Y") {
		std::cout << _getClassName() << " " << _name
				  << " highs five with you!" << std::endl;
	} else {
		std::cout << _getClassName() << " " << _name
				  << " is sad because you let him down :(" << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << _getClassName() << " " << _name
				  << " can't be repaired because it's destroyed!" << std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << _getClassName() << " " << _name
				  << " can't be repaired because it has no energy points left!"
				  << std::endl;
		return;
	}
	if (_hitPoints == _fragTrapBaseHitPoints) {
		std::cout << _getClassName() << " " << _name << " is already full HP!"
				  << std::endl;
		return;
	}
	_energyPoints--;
	if (_hitPoints + amount > _fragTrapBaseHitPoints) {
		int repaired = _fragTrapBaseHitPoints - _hitPoints;
		_hitPoints = _fragTrapBaseHitPoints;
		std::cout << _getClassName() << " " << _name << " is repaired for "
				  << repaired << " hit points! (Current HP: " << _hitPoints
				  << ") (No overheal)" << std::endl;
	} else {
		_hitPoints += amount;
		std::cout << _getClassName() << " " << _name << " is repaired for "
				  << amount << " hit points! (Current HP: " << _hitPoints << ")"
				  << std::endl;
	}
}

std::string FragTrap::_getClassName() { return "FragTrap"; }
std::string FragTrap::_getClassOverrided() { return "FragTrap"; }
