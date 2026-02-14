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

	std::cout << "ClapTrap:\n" << std::endl;
	std::cout << "Construction" << std::endl;
	ClapTrap clap1("Clappy-001");

	std::cout << "\nAttack" << std::endl;
	clap1.attack("Enemy 01");
	clap1.attack("Enemy 02");

	std::cout << "\nTake Damage" << std::endl;
	clap1.takeDamage(3);
	clap1.takeDamage(5);

	std::cout << "\nRepair" << std::endl;
	clap1.beRepaired(4);
	clap1.beRepaired(10);
	clap1.beRepaired(10);

	std::cout << "\nOut of Energy" << std::endl;
	ClapTrap clap2("Clappy-002");
	for (int i = 0; i < 11; i++) {
		clap2.attack("Dummy Target");
	}

	std::cout << "\nOut of HP" << std::endl;
	ClapTrap clap3("Clappy-003");
	clap3.takeDamage(15);
	clap3.attack("Enemy 03");
	clap3.beRepaired(5);

	std::cout << "\nCopy constructor" << std::endl;
	ClapTrap clap4("Clappy-004");
	ClapTrap clap5(clap4);

	std::cout << "--------------------------------------------" << std::endl;

	std::cout << "\nScavTrap:\n" << std::endl;
	std::cout << "Constructor" << std::endl;
	ScavTrap scav1("Scavvy-001");

	std::cout << "\nAttacks" << std::endl;
	scav1.attack("Enemy 04");
	scav1.attack("Enemy 05");

	std::cout << "\nGuard Gate" << std::endl;
	scav1.guardGate();

	std::cout << "\nTake Damage" << std::endl;
	scav1.takeDamage(30);
	scav1.takeDamage(40);

	std::cout << "\nRepair" << std::endl;
	scav1.beRepaired(25);
	scav1.beRepaired(200);
	scav1.beRepaired(100);

	std::cout << "\nClapTrap and ScavTrap" << std::endl;
	ClapTrap clap("Clappy-005");
	ScavTrap scav2("Scavvy-002");
	clap.attack("Enemy 06");
	scav2.attack("Enemy 07");

	std::cout << "\nDestructors" << std::endl;
	return 0;
}
