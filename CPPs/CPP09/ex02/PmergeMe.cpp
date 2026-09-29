/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/29 23:58:24 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/30 01:28:02 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

IData::IData(int index, int value): _index(index), _value(value){};
IData::IData(): _index(-1), _value(-1){};
IData& IData::operator=(const IData& other){
	if (this != &other){
		_index = other._index;
		_value = other._value;
	}
	return (*this);
};

bool IData::operator<(const IData& other) const {
	return this->_value < other._value;
}

p_vect& PmergeMe::get_index_order(const p_vect& iter){
	p_vect ret;
	p_vect_pairs original_indexes;
	for (int i = 0; i < iter.size(); i++){
		original_indexes.push_back(IData(i, iter[i]));
	}

	p_vect_pairs winners;
	p_vect_pairs lossers;
	IData	extra;
	if (iter.size() % 2 != 0)
		extra = original_indexes[iter.size() - 1];
	for (int i = 1; i < iter.size(); i + 2){
		if (original_indexes[i] < original_indexes[i - 1]){
			winners.push_back(original_indexes[i - 1]);
			lossers.push_back(original_indexes[i]);
		}else{
			lossers.push_back(original_indexes[i - 1]);
			winners.push_back(original_indexes[i]);
		}
	}
	p_vect winners_order = get_index_order(extract_p_vect(winners));
	p_vect winnners_ordered = get_container_ordered(winnners_ordered, winners_order);
	p_vect losers_ordered = get_container_ordered(losers_ordered, winners_order);
	//jakobstal

	p_vect iter_order;
	return (iter_order);
}

p_vect&	extract_p_vect(const p_vect_pairs& pv_data){
	p_vect ret;
	for (int i = 0; i < pv_data.size(); i++)
		ret.push_back(pv_data[i][1]);
	return ret;
}
