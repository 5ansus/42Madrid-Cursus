/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:06:33 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:23:25 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
	// Heap allocated zombie - persists outside function scope
	// Use when zombie needs to live beyond current scope
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;	// Must manually delete

	std::cout << std::endl;

	// Stack allocated zombie - automatically destroyed at end of scope
	// Use when zombie only needed temporarily
	randomChump("StackZombie");

	std::cout << std::endl;

	// More examples
	Zombie* zombie1 = newZombie("Zombie1");
	Zombie* zombie2 = newZombie("Zombie2");
	zombie1->announce();
	zombie2->announce();

	randomChump("TempZombie");

	delete zombie1;
	delete zombie2;

	return 0;
}
