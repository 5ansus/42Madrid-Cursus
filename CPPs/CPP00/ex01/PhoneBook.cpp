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

PhoneBook::PhoneBook() : _contactCount(0), _oldestIndex(0) {}

PhoneBook::~PhoneBook() {}

std::string PhoneBook::_formatColumn(const std::string &str) const {
	std::string out = str;

	if (out.length() > 10)
		out = out.substr(0, 9) + ".";

	if (out.length() < 10)
		out = std::string(10 - out.length(), ' ') + out;

	return out;
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
		std::cout << "Error: Invalid index" << std::endl;
		return;
	}

	std::cout << "\tFirst Name: " << _contacts[index].getFirstName() << std::endl;
	std::cout << "\tLast Name: " << _contacts[index].getLastName() << std::endl;
	std::cout << "\tNickname: " << _contacts[index].getNickname() << std::endl;
	std::cout << "\tPhone Number: " << _contacts[index].getPhoneNumber()
			  << std::endl;
	std::cout << "\tDarkest Secret: " << _contacts[index].getDarkestSecret()
			  << std::endl;
}

void PhoneBook::addContact() {
	std::string input;
	Contact newContact;

	std::cout << "\tEnter first name: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << "\tError: First name cannot be empty" << std::endl;
		return;
	}
	newContact.setFirstName(input);

	std::cout << "\tEnter last name: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << "\tError: Last name cannot be empty" << std::endl;
		return;
	}
	newContact.setLastName(input);

	std::cout << "\tEnter nickname: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << "\tError: Nickname cannot be empty" << std::endl;
		return;
	}
	newContact.setNickname(input);

	std::cout << "\tEnter phone number: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << "\tError: Phone number cannot be empty" << std::endl;
		return;
	}
	newContact.setPhoneNumber(input);

	std::cout << "\tEnter darkest secret: ";
	std::getline(std::cin, input);
	if (input.empty()) {
		std::cout << "\tError: Darkest secret cannot be empty" << std::endl;
		return;
	}
	newContact.setDarkestSecret(input);

	_contacts[_oldestIndex] = newContact;
	_oldestIndex = (_oldestIndex + 1) % 8;
	if (_contactCount < 8) _contactCount++;

	std::cout << "\tContact added successfully" << std::endl;
}

void PhoneBook::searchContact() {
	if (_contactCount == 0) {
		std::cout << "\tPhoneBook is empty" << std::endl;
		return;
	}

	_displayContactList();

	std::cout << "Enter index to display: ";
	std::string input;
	std::getline(std::cin, input);

	if (input.length() != 1 || !isdigit(input[0])) {
		std::cout << "\tError: Invalid input" << std::endl;
		return;
	}

	int index = input[0] - '0';
	_displayContact(index);
}
