/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sansus <sanferna@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/27 16:52:51 by sansus            #+#    #+#             */
/*   Updated: 2026/09/27 18:09:46 by sansus           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

class Span {
	private:
		unsigned int		_maxSize;
		std::vector<int>	_data;

	public:
		Span();
		Span(const Span& other);
		Span operator=(const Span& other);
		Span(unsigned int);
		~Span();

		void	addNumber(int number);
		int		shortestSpan();
		int		longestSpan();
		template <typename T>
		void	addRange(T start, T end);

		class	SpanFull : public std::exception{
			const char* what() const throw();
		};

		class	SpanNotEnoughMembers : public std::exception{
			const char* what() const throw();
		};

		unsigned int	current_size() const;
		int operator[](unsigned int index) const;
};

std::ostream& operator<<(std::ostream &os, const Span &span);

#endif
