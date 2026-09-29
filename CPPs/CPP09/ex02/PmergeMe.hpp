/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/29 23:58:44 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/30 00:58:22 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>


class IData{
	private:
		int _index;
		int _value;
		IData(const IData& other);
		IData& operator=(const IData& other);

	public:
		IData();
		IData(int index, int value);
		~IData();
};

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		typedef	std::vector<int>	p_vect;
		typedef	std::vector<IData>	p_vect_pairs;

	public:
		~PmergeMe();
		p_vect& get_index_order(const p_vect& iter);
		void	order_container(p_vect& iter, p_vect& index_ordered);
};

#endif
