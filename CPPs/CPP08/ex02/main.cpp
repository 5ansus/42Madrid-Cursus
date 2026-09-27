/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/27 18:34:18 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/27 19:37:43 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MutantStack.hpp"

#include <ctime>
#define SIZE_TEST 50
#define SIZE_TEST_POP 3


int main(){

	MutantStack<int>	pila;

	srand(time(NULL));
	for (int i = 0; i < SIZE_TEST; ++i)
		pila.push(i);

	std::cout << pila << std::endl;

	for (int i = 0; i < SIZE_TEST_POP; ++i)
		pila.pop();

	std::cout << pila << std::endl;
}
