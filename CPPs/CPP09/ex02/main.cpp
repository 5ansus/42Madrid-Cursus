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

template <typename T>
static void print_data(const T& data) {
	for (typename T::const_iterator i = data.begin(); i != data.end(); ++i)
		std::cout << *i << " " ;
	std::cout << std::endl;
}

template <typename T>
static double exec_pmerge(T& data) {
	clock_t start = clock();
		PmergeMe::MergeInsertionSort(data);
	clock_t end = clock();

	double ms = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000.0;
	return ms;
}

#include <ctime>

int main(int argc, char* argv[]) {

	if (argc < 2){
		std::cerr << "Error" << std::endl;
		return 1;
	}
	p_vect numbers;
	p_deque numbers_deque;
	std::stringstream	ss;
	std::string	extra;
	int	num;

	if (argc == 2)
	{
		ss << argv[1];
		while (ss >> num){
			if (num < 0){
				std::cerr << "Error" << std::endl;
				return 1;
			}
			numbers.push_back(num);
			numbers_deque.push_back(num);
		}
		if (!ss.eof()) {
			std::cerr << "Error" << std::endl;
			return 1;
		}
	}else{
		for (int i = 1; i < argc; ++i){
			if (argv[i][0] == '\0')
				continue;
			ss.clear();
			ss << argv[i];
			ss >> num;
			if (num < 0 || !ss.eof()){
				std::cerr << "Error" << std::endl;
				return 1;
			}
			numbers.push_back(num);
			numbers_deque.push_back(num);
		}
	}
	std::cout << "Before: ";
	print_data(numbers);
	std::cout << std::endl;

	double ms_vector = exec_pmerge(numbers);
	double ms_deque = exec_pmerge(numbers_deque);

	std::cout << "After:  ";
	print_data(numbers);
	std::cout << std::endl;

	std::cout << "Time to process a range of " << numbers.size() << " elements with std::vector : "<< ms_vector << " ms\n";
	std::cout << "Time to process a range of " << numbers_deque.size() << " elements with std::deque : "<< ms_deque << " ms\n";

	return 0;
}

