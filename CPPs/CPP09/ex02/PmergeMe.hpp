/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/29 23:58:44 by sanferna          #+#    #+#             */
/*   Updated: 2026/10/01 01:12:06 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>


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
		bool	operator==(const IData& other) const;
		int	operator*();
};

typedef	std::vector<IData>	p_vect_pairs;
typedef	std::vector<int>	p_vect;

typedef	std::deque<IData>	p_deque_pairs;
typedef	std::deque<int>	p_deque;

p_vect	extract_p_vect(const p_vect_pairs& pv_data);
p_vect	extract_p_indexes(const p_vect_pairs& pv_data);

p_deque	extract_p_deque(const p_deque_pairs& pv_data);
p_deque	extract_p_indexes(const p_deque_pairs& pv_data);
int jakobsthal(int n);
int get_group_size(int n);

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);


	public:
		~PmergeMe();
		static p_vect get_index_order(const p_vect& iter);
		template <typename T>
		static T get_container_ordered(T& to_order, p_vect& index_ordered);

		static p_vect_pairs	insert_with_jakobstal(const p_vect_pairs& winners, const p_vect_pairs& losers, const IData& extra);
		static void MergeInsertionSort(p_vect& data_to_order);
		static int find_index(const p_vect_pairs& vector, const IData& node, int max_index);


		static p_deque get_index_order(const p_deque& iter);
		template <typename T>
		static T get_container_ordered(T& to_order, p_deque& index_ordered);

		static p_deque_pairs	insert_with_jakobstal(const p_deque_pairs& winners, const p_deque_pairs& losers, const IData& extra);
		static void MergeInsertionSort(p_deque& data_to_order);
		static int find_index(const p_deque_pairs& deque, const IData& node, int max_index);

};

#endif
