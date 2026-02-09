/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:08:29 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:08:29 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main() {
	Harl harl;

	std::cout << "Testing all complaint levels:" << std::endl;
	std::cout << std::endl;

	harl.complain("DEBUG");
	std::cout << std::endl;

	harl.complain("INFO");
	std::cout << std::endl;

	harl.complain("WARNING");
	std::cout << std::endl;

	harl.complain("ERROR");
	std::cout << std::endl;

	std::cout << "Testing invalid level:" << std::endl;
	harl.complain("INVALID");
	std::cout << std::endl;

	std::cout << "Multiple complaints:" << std::endl;
	harl.complain("DEBUG");
	std::cout << std::endl;
	harl.complain("ERROR");

	return 0;
}
