/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:06:16 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:06:16 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "PhoneBook.hpp"

int main() {
	PhoneBook phoneBook;
	std::string command;

	std::cout << "Welcome to My Awesome PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true) {
		std::cout << "\nEnter command: ";
		if (!std::getline(std::cin, command)) break;

		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT") {
			std::cout << "Goodbye!" << std::endl;
			break;
		} else if (!command.empty())
			std::cout << "Invalid command! Use: ADD, SEARCH, or EXIT"
					  << std::endl;
	}

	return 0;
}
