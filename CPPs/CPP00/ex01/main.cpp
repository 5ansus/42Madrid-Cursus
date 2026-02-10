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

#include "PhoneBook.hpp"

int main() {
	PhoneBook phoneBook;
	std::string command;

	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true) {
		std::cout << "Enter command: ";
		if (!std::getline(std::cin, command)) break;

		for (size_t i = 0; i < command.length(); i++) {
			command[i] = std::toupper(command[i]);
		}
		if (command == "ADD")
			phoneBook.addContact();
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else if (command == "EXIT") {
			std::cout << "\tExiting..." << std::endl;
			break;
		} else if (command.empty())
			std::cout << "\tError: Please, type a command" << std::endl;
		else
			std::cout << "\tError: Invalid command" << std::endl;
	}

	return 0;
}
