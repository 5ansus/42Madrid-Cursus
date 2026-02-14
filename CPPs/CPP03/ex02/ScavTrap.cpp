/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:09:44 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:09:44 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_hitPoints = _scavTrapBaseHitPoints;
	_energyPoints = _scavTrapBaseEnergyPoints;
	_attackDamage = _scavTrapBaseAttackDamage;
	std::cout << _getClassName() << " default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name) {
	_hitPoints = _scavTrapBaseHitPoints;
	_energyPoints = _scavTrapBaseEnergyPoints;
	_attackDamage = _scavTrapBaseAttackDamage;
	std::cout << _getClassName() << " " << _name << " constructor called"
			<< std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << _getClassName() << " copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << _getClassName() << " copy assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}


ScavTrap::~ScavTrap() {
	std::cout << _getClassName() << " " << _name << " destructor called"
			<< std::endl;
}

void ScavTrap::guardGate() {
	if (_hitPoints == 0) {
		std::cout << _getClassName() << " " << _name
				<< " can't guardGate because it has no hit points left!"
				<< std::endl;
		return;
	}
	std::cout << _getClassName() << " " << _name
			<< " is now in Gate keeper mode!" << std::endl;
}


void ScavTrap::beRepaired(unsigned int amount) {
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
	if (_hitPoints == _scavTrapBaseHitPoints){
		std::cout << _getClassName() << " " << _name << " is already full HP!"
				<< std::endl;
		return;
	}
	_energyPoints--;
	if (_hitPoints + amount > _scavTrapBaseHitPoints){
		int repaired = _scavTrapBaseHitPoints - _hitPoints;
		_hitPoints = _scavTrapBaseHitPoints;
		std::cout << _getClassName() << " " << _name << " is repaired for "
				<< repaired << " hit points! (Current HP: " << _hitPoints << ") (No overheal)"
				<< std::endl;
	}
	else
	{
		_hitPoints += amount;
		std::cout << _getClassName() << " " << _name << " is repaired for "
				<< amount << " hit points! (Current HP: " << _hitPoints << ")"
				<< std::endl;
	}
}

std::string ScavTrap::_getClassName() { return "ScavTrap"; }
std::string ScavTrap::_getClassOverrided() { return "ScavTrap"; }
