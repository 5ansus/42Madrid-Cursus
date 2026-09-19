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

// float	Converter::is_special_float(const std::string& input){
// 	if (input == "+inff")
// 		return std::numeri

// }

void Converter::convert(const std::string& input){

	// float	special_float = Converter::is_special_float(input);

	// if (special_float != 0)
	// 	return print_to_all_types(special_float);
std::stringstream ss("-inff");
float f;

if (ss >> f)
    std::cout << "Es un float" << std::endl;
else
    std::cout << "No es un float" << std::endl;
	if (genericConversion<int>(input))
		return ;
	std::cerr << "No es un int" << std::endl;
	if (genericConversion<float>(input))
		return ;
	std::cerr << "No es un float" << std::endl;
	if (genericConversion<double>(input))
		return ;
	std::cerr << "No es un double" << std::endl;
}
