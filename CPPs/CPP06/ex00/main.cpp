/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/13 11:10:32 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/25 20:38:40 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Converter.hpp"

int main (int argc, char *argv[]){
	if (argc != 2)
	{
		std::cerr << "Usage: You have to enter only a number or char with simple quotes" << std::endl;
		return 1;
	}
	Converter::convert(argv[1]);
	return 0;
}
