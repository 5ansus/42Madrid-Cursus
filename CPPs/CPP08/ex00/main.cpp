/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/27 12:47:15 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/27 14:28:13 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <list>
#include <vector>

template <typename T>
void print_container(const T& container)
{
	typename T::const_iterator end = container.end();
	for (typename T::const_iterator iter = container.begin(); iter != end; ++iter){
		std::cout << *iter << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
}

template <typename T>
void add_values(T& container)
{
	container.push_back(3);
	container.push_back(2);
	container.push_back(5);
	container.push_back(4);
	container.push_back(1);
}


int main(){
	std::list<int> lista;
	std::vector<int> vector;

	add_values(lista);
	print_container(lista);
	add_values(vector);
	print_container(vector);

	std::cout << *easyfind(lista, 1) << std::endl;
	std::cout << *easyfind(vector, 3) << std::endl;

	try{
		std::cout << *easyfind(vector, 213) << std::endl;
	} catch(std::runtime_error &e){
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	std::cout << *easyfind(lista, 213) << std::endl;

}
