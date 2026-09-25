/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/12 20:08:23 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/15 19:46:44 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"

static std::string format_decimal(double number) {
	std::stringstream output;
	output << std::fixed << std::setprecision(Converter::DECIMAL_PRECISION)
		   << number;
	std::string result = output.str();
	std::string::size_type point = result.find('.');

	if (point != std::string::npos) {
		std::string::size_type end = result.size();
		while (end > point + 1 && result[end - 1] == '0') --end;
		result.erase(end);
		if (result[result.size() - 1] == '.') result += '0';
	} else
		result += ".0";
	return result;
}

void Converter::convert(const std::string& input) {
	if (special_conversion<float>(input)) return;
		#ifdef DEBUG
			std::cerr << "No es un special float" << std::endl;
		#endif
	if (special_conversion<double>(input)) return;
		#ifdef DEBUG
			std::cerr << "No es un special double" << std::endl;
		#endif

	if (genericConversion<char>(input)) return;
		#ifdef DEBUG
			std::cerr << "No es un char" << std::endl;
		#endif
	if (genericConversion<int>(input)) return;
		#ifdef DEBUG
			std::cerr << "No es un int" << std::endl;
		#endif
	if (genericConversion<float>(input)) return;
		#ifdef DEBUG
			std::cerr << "No es un float" << std::endl;
		#endif
	if (genericConversion<double>(input)) return;
		#ifdef DEBUG
			std::cerr << "No es un double" << std::endl;
		#endif
	std::cerr << "Entered value: <" << input << "> not a supported type" << std::endl;
}

void print_char(char number) {
	std::cout << "char:" << format_decimal(number) << "f" << std::endl;
}

void print_decimal(float number) {
	std::cout << "float: " << format_decimal(number) << "f" << std::endl;
}

void print_decimal(double number) {
	std::cout << "double: " << format_decimal(number) << std::endl;
}

void print_error(const std::string& msg) { std::cerr << msg << std::endl; }

bool is_special_string(const std::string& input, double* data) {
	const std::string special_strings[] = {"-inf", "+inf", "nan", ""};

	double special_values[] = {
		-std::numeric_limits<double>::infinity(),
		std::numeric_limits<double>::infinity(),
		std::numeric_limits<double>::quiet_NaN()
	};

	for (int i = 0; !special_strings[i].empty(); i++) {
		if (special_strings[i] == input) {
			*data = special_values[i];
			return true;
		}
	}

	return false;
}

bool is_special_string(const std::string& input, float* data) {
	const std::string special_strings[] = {"-inff", "+inff", "nanf", ""};

	float special_values[] = {
		-std::numeric_limits<float>::infinity(),
		std::numeric_limits<float>::infinity(),
		std::numeric_limits<float>::quiet_NaN()
	};

	for (int i = 0; !special_strings[i].empty(); i++) {
		if (special_strings[i] == input) {
			*data = special_values[i];
			return true;
		}
	}

	return false;
}
