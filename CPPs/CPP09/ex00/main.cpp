/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/27 23:20:30 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/28 01:48:19 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(){
	try
	{
		DB	db("data.csv");
	}
	catch(const std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
