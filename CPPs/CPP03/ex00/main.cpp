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

	std::cout << "\nDestructors" << std::endl;
	return 0;
}
