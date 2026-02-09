/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:07:09 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:07:10 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	int hordeSize = 5;

	std::cout << "Creating a horde of " << hordeSize << " zombies..."
			  << std::endl;
	Zombie* horde = zombieHorde(hordeSize, "HordeZombie");

	if (horde == NULL) {
		std::cout << "Failed to create zombie horde" << std::endl;
		return 1;
	}

	std::cout << std::endl;
	std::cout << "Zombies announcing themselves:" << std::endl;
	for (int i = 0; i < hordeSize; i++) {
		std::cout << "Zombie " << i << ": ";
		horde[i].announce();
	}

	std::cout << std::endl;
	std::cout << "Destroying the horde..." << std::endl;
	delete[] horde;

	std::cout << std::endl;
	std::cout << "Creating another horde..." << std::endl;
	Zombie* horde2 = zombieHorde(3, "Walker");
	for (int i = 0; i < 3; i++) {
		horde2[i].announce();
	}
	delete[] horde2;

	return 0;
}
