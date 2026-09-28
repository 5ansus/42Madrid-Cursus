/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/28 19:56:51 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/29 01:42:08 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char* argv[]){
	if (argc != 2){
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try
	{
		RPN::process_input(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	return 0;
}
