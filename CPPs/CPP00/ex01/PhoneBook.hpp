/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 21:06:27 by sanferna          #+#    #+#             */
/*   Updated: 2026/02/09 21:06:27 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

class PhoneBook {
	private:
		Contact _contacts[8];
		int _contactCount;
		int _oldestIndex;

		std::string _truncate(const std::string &str) const;
		std::string _formatColumn(const std::string &str) const;
		void _displayContactList() const;
		void _displayContact(int index) const;

	public:
		PhoneBook();
		~PhoneBook();

		void addContact();
		void searchContact();
};

#endif
