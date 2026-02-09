/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:09:23 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:09:24 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	std::cout << "=== Test 1: Basic Construction ===" << std::endl;
	ClapTrap clap1("CT-001");

	std::cout << "\n=== Test 2: Attacks ===" << std::endl;
	clap1.attack("Enemy");
	clap1.attack("Another Enemy");

	std::cout << "\n=== Test 3: Taking Damage ===" << std::endl;
	clap1.takeDamage(3);
	clap1.takeDamage(5);

	std::cout << "\n=== Test 4: Repairing ===" << std::endl;
	clap1.beRepaired(4);

	std::cout << "\n=== Test 5: Energy Depletion ===" << std::endl;
	ClapTrap clap2("CT-002");
	for (int i = 0; i < 11; i++) {
		clap2.attack("Target");
	}

	std::cout << "\n=== Test 6: Hit Points Depletion ===" << std::endl;
	ClapTrap clap3("CT-003");
	clap3.takeDamage(15);
	clap3.attack("Someone");
	clap3.beRepaired(5);

	std::cout << "\n=== Test 7: Copy Constructor ===" << std::endl;
	ClapTrap clap4("CT-004");
	ClapTrap clap5(clap4);

	std::cout << "\n=== Destructors ===" << std::endl;
	return 0;
}
