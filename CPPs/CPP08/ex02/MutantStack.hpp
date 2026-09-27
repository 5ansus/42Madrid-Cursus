/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/27 18:34:18 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/27 19:34:06 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP
#include <algorithm>
#include <deque>
#include <iostream>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
   public:
	MutantStack();
	MutantStack(const MutantStack<T, Container>& other);
	~MutantStack();
	MutantStack<T, Container>& operator=(
		const MutantStack<T, Container>& other);

	typedef
		typename std::stack<T, Container>::container_type::iterator iterator;
	iterator begin();
	iterator end();

	typedef typename std::stack<T, Container>::container_type::const_iterator
		const_iterator;
	const_iterator begin() const;
	const_iterator end() const;

	typedef typename std::stack<T, Container>::container_type::reverse_iterator
		reverse_iterator;
	reverse_iterator rbegin();
	reverse_iterator rend();

	typedef
		typename std::stack<T,
							Container>::container_type::const_reverse_iterator
			const_reverse_iterator;
	const_reverse_iterator rbegin() const;
	const_reverse_iterator rend() const;
};

template <typename T, typename Container>
std::ostream& operator<<(std::ostream& os,
						 const MutantStack<T, Container>& stack);

#include "MutantStack.tpp"

#endif
