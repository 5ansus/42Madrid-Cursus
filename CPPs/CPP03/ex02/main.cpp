/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:10:05 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:10:06 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	std::cout << "=== Test 1: FragTrap Construction Chaining ===" << std::endl;
	FragTrap frag1("FT-001");

	std::cout << "\n=== Test 2: FragTrap High Five ===" << std::endl;
	frag1.highFivesGuys();

	std::cout << "\n=== Test 3: FragTrap Attacks ===" << std::endl;
	frag1.attack("Enemy Mech");
	frag1.attack("Boss");

	std::cout << "\n=== Test 4: All Three Classes ===" << std::endl;
	ClapTrap clap("CT-003");
	ScavTrap scav("ST-003");
	FragTrap frag2("FT-003");

	clap.attack("Target");
	scav.attack("Target");
	frag2.attack("Target");

	scav.guardGate();
	frag2.highFivesGuys();

	std::cout << "\n=== Test 5: FragTrap Combat ===" << std::endl;
	frag2.takeDamage(50);
	frag2.beRepaired(20);
	frag2.takeDamage(70);
	frag2.highFivesGuys();

	std::cout << "\n=== Destructors (reverse order) ===" << std::endl;
	return 0;
}
