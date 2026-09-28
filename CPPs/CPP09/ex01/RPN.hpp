/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/28 19:56:47 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/28 21:29:43 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPP_HPP
#define RPP_HPP

#include <iostream>
#include <stack>

class RPN {
	private:
		std::stack<int> _pila;
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();

	public:
		
};
#endif
