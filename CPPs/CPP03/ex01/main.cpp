/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:09:38 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:09:38 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	std::cout << "=== Test 1: Construction Chaining ===" << std::endl;
	ScavTrap scav1("ST-001");

	std::cout << "\n=== Test 2: ScavTrap Attacks ===" << std::endl;
	scav1.attack("Enemy Robot");
	scav1.attack("Another Enemy");

	std::cout << "\n=== Test 3: Guard Gate ===" << std::endl;
	scav1.guardGate();

	std::cout << "\n=== Test 4: Taking Damage ===" << std::endl;
	scav1.takeDamage(30);
	scav1.takeDamage(40);

	std::cout << "\n=== Test 5: Repairing ===" << std::endl;
	scav1.beRepaired(25);

	std::cout << "\n=== Test 6: ClapTrap vs ScavTrap ===" << std::endl;
	ClapTrap clap("CT-002");
	ScavTrap scav2("ST-002");
	clap.attack("Target");
	scav2.attack("Target");

	std::cout << "\n=== Destructors (reverse order) ===" << std::endl;
	return 0;
}
