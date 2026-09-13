/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/12 20:08:31 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/13 15:25:47 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
#define CONVERTER_HPP
#include <iostream>
#include <string>

class Converter {
	public:

	private:
		Converter();
		Converter(const Converter& other);
		Converter& operator=(const Converter& other);
		~Converter();

	public:
		void convert(const std::string& input) const;
};

#include "Converter.tpp"
#endif
