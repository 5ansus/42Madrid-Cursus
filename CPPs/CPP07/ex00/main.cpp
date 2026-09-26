/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/18 21:54:22 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/26 13:01:48 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

#include <iostream>

void print_values(int n1, int n2){

	std::cout << "Valor de n1: " << n1 << std::endl;
	std::cout << "Valor de n2: " << n2 << std::endl;
	std::cout << "--------------------------" << std::endl;
}

int main() {
	int n1 = 5;
	int n2 = 7;

	print_values(n1, n2);
	swap(n1, n2);
	print_values(n1, n2);

	std::cout << "El min es: " << min(n1, n2) << std::endl;
	std::cout << "El max es: " << max(n1, n2) << std::endl;

}
