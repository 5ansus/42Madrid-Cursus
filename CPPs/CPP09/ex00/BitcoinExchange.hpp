/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/28 23:21:10 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/28 02:02:40 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <ctime>
#include <sstream>

#define EXPECTED_HEADER "date,exchange_rate"

class DB{
	private:
		std::map<std::string, double>	_values;
		DB();
		DB(const DB& other);
		DB& operator=(const DB& other);
		void add_db_line(const std::string& line);
		double calculate_value(const std::string& date, double amount);
		std::string&	process_input_line(const std::string& input);

	public:
		DB(const std::string& filename);
		~DB();
		void	process_input_file(const std::string& filename);


};

#endif
