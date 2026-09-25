/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/12 20:08:31 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/25 20:42:25 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONVERTER_HPP
#define CONVERTER_HPP
#include <iostream>
#include <string>

class Converter {
	private:
		Converter();
		Converter(const Converter& other);
		Converter& operator=(const Converter& other);
		~Converter();

	public:
		static void		convert(const std::string& input);
		static const int DECIMAL_PRECISION = 6;

};

void print_decimal(float number);
void print_decimal(double number);
void print_error(const std::string& msg);
bool is_special_string(const std::string& input, float *data);
bool is_special_string(const std::string& input, double *data);

#include "Converter.tpp"

#endif
