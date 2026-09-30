/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/29 23:58:50 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/29 23:59:46 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

#include "PmergeMe.hpp"

static void print_vector(const p_vect& v) {
	for (p_vect::size_type i = 0; i < v.size(); ++i)
		std::cout << v[i] << (i + 1 == v.size() ? '\n' : ' ');
}

int main(){
	p_vect numbers;
	int values[] = {8, 3, 5, 1, 9, 2, 7, 4, 6};

	for (int i = 0; i < 9; ++i)
		numbers.push_back(values[i]);

	std::cout << "Before: ";
	print_vector(numbers);

	PmergeMe::MergeInsertionSort(numbers);

	std::cout << "After:  ";
	print_vector(numbers);

	return 0;
}
