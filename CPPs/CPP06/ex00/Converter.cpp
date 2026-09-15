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

void Converter::convert(const std::string& input){
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
