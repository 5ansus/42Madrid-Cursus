/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:06:25 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:06:25 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook() : _contactCount(0), _oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::_truncate(const std::string& str) const {
	if (str.length() > 10) return str.substr(0, 9) + ".";
	return str;
}

std::string PhoneBook::_formatColumn(const std::string& str) const {
	std::string truncated = _truncate(str);
	std::stringstream ss;
	ss << std::setw(10) << truncated;
	return ss.str();
}

void PhoneBook::_displayContactList() const {
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	for (int i = 0; i < 8; i++) {
		if (_contacts[i].isEmpty()) continue;

		std::cout << std::setw(10) << i << "|";
		std::cout << _formatColumn(_contacts[i].getFirstName()) << "|";
		std::cout << _formatColumn(_contacts[i].getLastName()) << "|";
		std::cout << _formatColumn(_contacts[i].getNickname()) << std::endl;
	}
}

void PhoneBook::_displayContact(int index) const {
	if (index < 0 || index >= 8 || _contacts[index].isEmpty()) {
		std::cout << "Error: Invalid index!" << std::endl;
		return;
	}

	std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << _contacts[index].getPhoneNumber()
			  << std::endl;
	std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret()
			  << std::endl;
}

void PhoneBook::addContact() {
	std::string input;
	Contact newContact;

	std::cout << "Enter first name: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << "Error: First name cannot be empty!" << std::endl;
		return;
	}
	newContact.setFirstName(input);

	std::cout << "Enter last name: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << "Error: Last name cannot be empty!" << std::endl;
		return;
	}
	newContact.setLastName(input);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << "Error: Nickname cannot be empty!" << std::endl;
		return;
	}
	newContact.setNickname(input);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << "Error: Phone number cannot be empty!" << std::endl;
		return;
	}
	newContact.setPhoneNumber(input);

	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << "Error: Darkest secret cannot be empty!" << std::endl;
		return;
	}
	newContact.setDarkestSecret(input);

	_contacts[_oldestIndex] = newContact;
	_oldestIndex = (_oldestIndex + 1) % 8;
	if (_contactCount < 8) _contactCount++;

	std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact() {
	if (_contactCount == 0) {
		std::cout << "PhoneBook is empty!" << std::endl;
		return;
	}

	_displayContactList();

	std::cout << "Enter index to display: ";
	std::string input;
	std::getline(std::cin, input);

	if (input.length() != 1 || !isdigit(input[0])) {
		std::cout << "Error: Invalid input!" << std::endl;
		return;
	}

	int index = input[0] - '0';
	_displayContact(index);
}
