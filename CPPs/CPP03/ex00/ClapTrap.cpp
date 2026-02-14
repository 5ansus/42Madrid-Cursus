/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:09:16 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:09:17 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name("DefaultBot"),
	_hitPoints(_clapTrapBaseHitPoints),
	_energyPoints(_clapTrapBaseEnergyPoints),
	_attackDamage(_clapTrapBaseAttackDamage) {
	std::cout << _getClassName() << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
	: _name(name),
	_hitPoints(_clapTrapBaseHitPoints),
	_energyPoints(_clapTrapBaseEnergyPoints),
	_attackDamage(_clapTrapBaseAttackDamage) {
	std::cout << _getClassName() << " " << _name << " constructor called"
			<< std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << _getClassName() << " copy constructor called" << std::endl;
	*this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << _getClassName() << " copy assignment operator called" << std::endl;
	if (this != &other) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << _getClassName() << " " << _name << " destructor called"
			<< std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_hitPoints == 0) {
		std::cout << _getClassName() << " " << _name
				<< " can't attack because it has no hit points left!"
				<< std::endl;
		return;
	}
	if (_energyPoints == 0) {
		std::cout << _getClassName() << " " << _name
				<< " can't attack because it has no energy points left!"
				<< std::endl;
		return;
	}
	_energyPoints--;
	std::cout << _getClassName() << " " << _name << " attacks " << target
			<< ", causing " << _attackDamage << " points of damage!"
			<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0) {
		std::cout << _getClassName() << " " << _name << " is already destroyed!"
				<< std::endl;
		return;
	}
	if (amount >= _hitPoints) {
		_hitPoints = 0;
		std::cout << _getClassName() << " " << _name << " takes " << amount
				<< " points of damage and is destroyed!" << std::endl;
	} else {
		_hitPoints -= amount;
		std::cout << _getClassName() << " " << _name << " takes " << amount
				<< " points of damage! (" << _hitPoints << " HP remaining)"
				<< std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
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
	if (_hitPoints == _clapTrapBaseHitPoints){
		std::cout << _getClassName() << " " << _name << " is already full HP!"
				<< std::endl;
		return;
	}
	_energyPoints--;
	if (_hitPoints + amount > _clapTrapBaseHitPoints){
		int repaired = _clapTrapBaseHitPoints - _hitPoints;
		_hitPoints = _clapTrapBaseHitPoints;
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

std::string ClapTrap::_getClassName() { return "ClapTrap"; }
