/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/29 23:58:44 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/30 01:26:11 by sanferna         ###   ########.fr       */
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


	public:
		IData();
		IData(int index, int value);
		IData(const IData& other);
		IData& operator=(const IData& other);
		bool operator<(const IData& other) const;
		~IData();
		bool	is_valid() const;
		const int&	operator[](int index) const;
};

typedef	std::vector<IData>	p_vect_pairs;
typedef	std::vector<int>	p_vect;

p_vect	extract_p_vect(const p_vect_pairs& pv_data);

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);


	public:
		~PmergeMe();
		static p_vect get_index_order(const p_vect& iter);
		static p_vect	get_container_ordered(p_vect& to_order, p_vect& index_ordered);
		static p_vect	get_pairs_ordered(p_vect_pairs& to_order, p_vect& index_ordered);
		static void MergeInsertionSort(p_vect& data_to_order);
};

#endif
