/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/28 23:20:59 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/28 21:20:36 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"

static bool validate_date(const std::string& date_str){
	if (date_str.find('+') != std::string::npos)
		return false;
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
		return false;
		// throw std::runtime_error("Error on the year");
	ss >> sep;
	if (ss.fail() || sep != '-')
		return false;
		// throw std::runtime_error("Error on the sep");

	ss >> month;
	if (ss.fail() || month < 0)
		// throw std::runtime_error("Error on the moth" );
		return false;
	ss >> sep;
	if (ss.fail() || sep != '-')
		return false;
		// throw std::runtime_error("Error on the sep");

	ss >> day;
	if (ss.fail() || day < 0)
		return false;
		// throw std::runtime_error("Error on the day");

	ss >> rest;
	if (!ss.eof())
		return false;
		// throw std::runtime_error("Error on the rest");

	std::memset(&date, 0, sizeof(date));

	date.tm_year = year - 1900;
	date.tm_mon = month - 1;
	date.tm_mday = day;

	std::time_t epoch = std::mktime(&date);
	if (epoch == static_cast<std::time_t>(-1))
		throw std::runtime_error("Coulnd't get the epoch time");

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
		throw std::runtime_error("Line:< " + line + " > has invalid date");

	ss >> price;
	if (ss.fail())
		throw std::runtime_error("Error while reading 'price' line:< " + line + " >");
	if (price < 0)
		throw std::runtime_error("Line:< " + line + " > has negative price");
	ss >> rest;
	if (!ss.eof())
		throw std::runtime_error("Error while reading line:< " + line + " >:Has extra characthers");

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

void DB::print_calculate(const std::string& date, double amount)
{
	double	unit_price;
	std::map<std::string, double>::iterator found = _values.lower_bound(date);

	if (found->first == date)
		unit_price = found->second;
	else if (found == _values.begin())
		unit_price = 0;
	else
		unit_price = (--found)->second;

	std::cout << date << " => " << amount << " = " << (amount * unit_price) << std::endl;
}

void	DB::process_input_line(const std::string& line){

	std::stringstream	ss;

	ss << line;

	std::string			date_str;
	char				sep;
	double				amount;
	std::string			rest;

	ss >> date_str;
	if (ss.fail())
		throw DB::ErrorInputLine("Error while reading input 'date' line:< " + line + " >");

	if (!::validate_date(date_str))
		throw DB::ErrorInputLine("bad input => " + date_str);

	ss >> sep;
	if (ss.fail())
		throw DB::ErrorInputLine("Error while reading input 'separator' line:< " + line + " >");
	if (sep != '|')
		throw DB::ErrorInputLine("wrong separator");

	ss >> amount;
	if (ss.fail())
		throw DB::ErrorInputLine("Error while reading input 'amount' line:< " + line + " >");
	if (amount < 0)
		throw DB::ErrorInputLine("not a positive number");
	if (amount > 1000)
		throw DB::ErrorInputLine("too large a number");

	ss >> rest;
	if (!ss.eof())
		throw DB::ErrorInputLine("Error while reading line:< " + line + " >:Has extra characthers");

	print_calculate(date_str, amount);
}

void	DB::process_input_file(const std::string& filename){
	std::ifstream	file(filename.c_str());
	std::string		header;

	if (!file.is_open())
		throw std::runtime_error("ERROR: Couldn't open the file" + filename);
	std::string	line;
	std::getline(file, line);
	if (line != EXPECTED_INPUT_HEADER)
		throw std::runtime_error("ERROR: " + filename + " don't have the spected header: " + EXPECTED_HEADER);

	while (std::getline(file, line)) {
		try
		{
			process_input_line(line);
		}
		catch(const DB::ErrorInputLine & e)
		{
			std::cerr << "Error: " << e.what() << "." << std::endl;
		}

	}
}

DB::ErrorInputLine::ErrorInputLine(const std::string& what_arg)
	: std::runtime_error(what_arg) {
}

DB::ErrorInputLine::~ErrorInputLine() throw() {
}
