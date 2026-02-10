/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:07:21 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:07:21 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int n_zombies, std::string name) {
	if (n_zombies <= 0) return NULL;

	Zombie* horde = new Zombie[n_zombies];

	for (int i = 0; i < n_zombies; i++) {
		horde[i].setName(name);
	}

	return horde;
}
