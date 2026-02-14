/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:10:02 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:10:03 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
   private:
	static unsigned int const _fragTrapBaseHitPoints = 100;
	static unsigned int const _fragTrapBaseEnergyPoints = 100;
	static unsigned int const _fragTrapBaseAttackDamage = 30;
	static std::string _getClassName();

   protected:
	std::string _getClassOverrided();

   public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& other);
	FragTrap& operator=(const FragTrap& other);
	~FragTrap();

	void highFivesGuys(void);
	void beRepaired(unsigned int amount);
};

#endif
