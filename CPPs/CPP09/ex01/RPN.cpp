/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/28 19:56:44 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/29 01:52:27 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Oper getOperator(char op) {
	switch (op) {
		case '+':
			return SUM;
		case '-':
			return SUB;
		case '*':
			return MUL;
		case '/':
			return DIV;
		default:
			return NONE;
	}
}

int apply_operation(std::stack<int>& pila, Oper operador){

	if (pila.empty())
		throw std::exception();
	int op2 = pila.top();
	pila.pop();
	if (pila.empty())
		throw std::exception();
	int op1 = pila.top();
	pila.pop();

	switch (operador) {
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			if (op2 == 0)
				throw std::exception();
			return op1 / op2;
		default:
			return 0;
	}
}

void RPN::process_input(const std::string& input){

	if (input.empty())
		return ;

	std::stringstream ss;
	std::stack<int> pila;
	std::string iter;
	Oper operador;


	ss << input;

	while(ss >> iter){
		if (ss.fail())
			throw std::exception();
		if (iter.empty())
			continue;
		if (iter.length() != 1)
			throw std::exception();
		if (std::isdigit(iter[0]))
		{
			pila.push(iter[0] - '0');
			continue;
		}
		operador = ::getOperator(iter[0]);
		if (operador == NONE)
			throw std::exception();
		pila.push(apply_operation(pila, operador));
	}
	if (pila.size() != 1)
		throw std::exception();
	int res = pila.top();;
	std::cout << res << std::endl;
}
