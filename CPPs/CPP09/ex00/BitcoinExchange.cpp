/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/28 23:20:59 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/28 02:00:10 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

static bool validate_date(const std::string& date_str){
	std::stringstream	ss;
	tm date;
	int	year;
	int	month;
	int	day;
	char			sep;
	std::string			rest;


	ss << date_str;
	ss >> year;
	if (ss.fail() || year < 0)
		throw std::runtime_error("Error on the year");
	ss >> sep;
	if (ss.fail() || sep != '-')
		throw std::runtime_error("Error on the sep");

	ss >> month;
	if (ss.fail() || month < 0)
		throw std::runtime_error("Error on the moth");
	ss >> sep;
	if (ss.fail() || sep != '-')
		throw std::runtime_error("Error on the sep");

	ss >> day;
	if (ss.fail() || day < 0)
		throw std::runtime_error("Error on the day");

	ss >> rest;
	if (!ss.eof())
		throw std::runtime_error("Error on the rest");

	std::memset(&date, 0, sizeof(date));

	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;

	std::time_t epoch = std::mktime(&date);
	if (epoch == static_cast<std::time_t>(-1))
		throw std::runtime_error("Coulnd't get the epoch time");

	if (date.tm_mday != day)
	{
		std::stringstream	ss_err;
		ss_err << "wrong day " << day << " vs " << date.tm_mday;
		throw std::runtime_error(ss_err.str());

	}
	if (date.tm_mday != day
		|| date.tm_mon != month - 1
		|| date.tm_year != year - 1900)
		return false;

	return true;
}

void	DB::add_db_line(const std::string& line){
	std::stringstream	ss;


	ss << line;
	std::string		date_str;
	double			price;
	std::string			rest;

	std::getline(ss, date_str, ',');

	if (!::validate_date(date_str))
		throw std::runtime_error("Line: " + line + " has invalid date");

	ss >> price;
	if (ss.fail())
		throw std::runtime_error("Error while reading 'price' line: " + line);
	if (price < 0)
		throw std::runtime_error("Line: " + line + " has negative price");
	ss >> rest;
	if (!ss.eof())
		throw std::runtime_error("Error while reading line: " + line + " :Has extra characthers");

	if (_values.find(date_str) != _values.end() && _values.find(date_str)->second != price){
		throw std::runtime_error("Error: duplicated key " + date_str + " with different values.");
	}

	_values.insert(std::make_pair(date_str, price));
};


DB::DB(const std::string& filename){
	std::ifstream	file(filename.c_str());
	std::string		header;

	if (!file.is_open())
		throw std::runtime_error("ERROR: Couldn't open the file" + filename);
	std::string	line;
	std::getline(file, line);
	if (line != EXPECTED_HEADER)
		throw std::runtime_error("ERROR: " + filename + " don't have the spected header: " + EXPECTED_HEADER);

	while (std::getline(file, line)) {
		try
		{
			add_db_line(line);
		}
		catch(const std::runtime_error& e)
		{
			file.close();
			throw e;
		}

	}
}

DB::~DB(){
}

double DB::calculate_value(const std::string& date, double amount)
{
	double	unit_price;
	std::map<std::string, double>::iterator found = _values.lower_bound(date);

	if (found->first == date)
		unit_price = found->second;
	else if (found == _values.begin())
		unit_price = 0;
	else
		unit_price = (--found)->second;

	return (amount * unit_price);
}
