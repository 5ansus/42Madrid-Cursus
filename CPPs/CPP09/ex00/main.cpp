/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/27 23:20:30 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/28 19:46:28 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char *argv[]){
	try{
		DB	db("data.csv");
		if (argc != 2)
		{
			std::cerr << "Error: could not open file." << std::endl;
			return 1;
		}
		db.process_input_file(argv[1]);
	} catch(const std::runtime_error& e)
	{
		std::cerr << "ERROR while creating the Database: ";
		std::cerr << e.what() << std::endl;
		return 1;
	}
	// std::cout << argv[1] << std::endl;
	return 0;
}
