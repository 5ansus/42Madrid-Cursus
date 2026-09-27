/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/28 23:21:10 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/28 01:03:59 by sanferna         ###   ########.fr       */
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

	public:
		DB(const std::string& filename);
		~DB();

};



// class Date{
// 	public:
// 		const unsigned int y;
// 		const unsigned int m;
// 		const unsigned int d;

// 	private:
// 		tm _date;
// 		Date();
// 		Date(const Date& other);
// 		Date& operator=(const Date& other);
// 		~Date();

// 		Date(const std::string& date_str);


// };

#endif
