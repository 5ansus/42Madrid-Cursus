/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/28 19:56:47 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/29 01:38:53 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPP_HPP
#define RPP_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <stack>

enum Oper {
	NONE = 0,
	SUM = '+',
	SUB = '-',
	MUL = '*',
	DIV = '/',
};

Oper getOperator(char op);
int apply_operation(std::stack<int>& pila, Oper operador);

class RPN {
	private:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

	public:
		~RPN();
		static void process_input(const std::string& input);

};

#endif
