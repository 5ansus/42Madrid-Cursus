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
	Zombie* heapZombie = newZombie("HeapZombie");
	heapZombie->announce();
	delete heapZombie;

	randomChump("StackZombie");

	Zombie* zombie1 = newZombie("Zombie1");
	Zombie* zombie2 = newZombie("Zombie2");
	zombie1->announce();
	zombie2->announce();

	randomChump("TempZombie");

	delete zombie1;
	delete zombie2;

	return 0;
}
