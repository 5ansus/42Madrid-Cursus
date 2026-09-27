/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sansus <sanferna@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/27 16:52:33 by sansus            #+#    #+#             */
/*   Updated: 2026/09/27 18:28:36 by sansus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <ctime>
#define SIZE_TEST 50

int main(){

	Span	span(SIZE_TEST);

	srand(time(NULL));
	for (int i = 0; i < SIZE_TEST; ++i)
		span.addNumber(rand() % 200);

	std::cout << span << std::endl;
	std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
	std::cout << "Longest span: " << span.longestSpan() << std::endl;
}
