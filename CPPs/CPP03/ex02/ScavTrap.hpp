/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:09:46 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:09:47 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
	private:
		static unsigned int const _scavTrapBaseHitPoints = 100;
		static unsigned int const _scavTrapBaseEnergyPoints = 50;
		static unsigned int const _scavTrapBaseAttackDamage = 20;
		static std::string _getClassName();

	protected:
		std::string _getClassOverrided();

	public:
		ScavTrap();
		ScavTrap(const std::string& name);
		ScavTrap(const ScavTrap& other);
		ScavTrap& operator=(const ScavTrap& other);
		~ScavTrap();
		void guardGate();
		void beRepaired(unsigned int amount);
};

#endif
