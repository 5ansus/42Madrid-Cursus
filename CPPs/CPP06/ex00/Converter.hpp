/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/12 20:08:31 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/15 19:31:18 by sanferna         ###   ########.fr       */
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
		static const int DECIMAL_PRECISION = 10;

	public:
		static void		convert(const std::string& input);
		static float	is_special_float(const std::string& input);
};

#include "Converter.tpp"
#endif
