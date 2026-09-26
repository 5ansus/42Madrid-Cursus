/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/26 12:59:05 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/26 13:59:44 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class	Array{
	private:
		unsigned int	_size;
		T*				_memory;

	public:
		Array();
		Array(unsigned int elements);
		Array(const Array<T> &other);
		Array<T>& operator=(const Array<T> &other);
		~Array();
		unsigned int	size() const;
		const T&	operator[](unsigned int index) const;
		T&	operator[](unsigned int index);

		// class ArrayException : public std::exception{
		// 	public:
		// 		const char* what() const throw();
		// };
};

template <typename T>
std::ostream& operator<<(std::ostream &os, const Array<T> &array);

#include "Array.tpp"

#endif
