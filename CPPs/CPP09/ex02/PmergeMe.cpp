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
IData::IData(const IData& other): _index(other._index), _value(other._value){};
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

const int&	IData::operator[](int index) const {
	if (index == 1)
		return _value;
	return _index;
}

bool	IData::is_valid() const {
	if (_index == -1)
		return false;
	return true;
}

p_vect PmergeMe::get_index_order(const p_vect& iter){

	p_vect ret;
	// if (iter.size() == 0)
	// 	return ret;
	if (iter.size() == 1){
		ret.push_back(0);
		return ret;
	}
	p_vect_pairs original_indexes;
	for (p_vect::size_type i = 0; i < iter.size(); i++){
		original_indexes.push_back(IData(i, iter[i]));
	}

	p_vect_pairs winners;
	p_vect_pairs lossers;
	IData	extra;
	if (iter.size() % 2 != 0)
		extra = original_indexes[iter.size() - 1];
	for (p_vect::size_type i = 1; i < iter.size(); i += 2){
		if (original_indexes[i] < original_indexes[i - 1]){
			winners.push_back(original_indexes[i - 1]);
			lossers.push_back(original_indexes[i]);
		}else{
			lossers.push_back(original_indexes[i - 1]);
			winners.push_back(original_indexes[i]);
		}
	}
	p_vect winners_order = get_index_order(extract_p_vect(winners));
	p_vect winnners_ordered = get_pairs_ordered(winners, winners_order);
	p_vect losers_ordered = get_pairs_ordered(lossers, winners_order);
	//jakobstal

	p_vect iter_order;
	return (iter_order);
}

p_vect	extract_p_vect(const p_vect_pairs& pv_data){
	p_vect ret;
	for (p_vect::size_type i = 0; i < pv_data.size(); i++)
		ret.push_back(pv_data[i][1]);
	return ret;
}

void PmergeMe::MergeInsertionSort(p_vect& data_to_order){
	if (data_to_order.size() == 0)
		return;
	p_vect data_order = get_index_order(data_to_order);
	p_vect data_odered = get_container_ordered(data_to_order, data_order);
	data_to_order = data_odered;
}

p_vect	PmergeMe::get_container_ordered(p_vect& to_order, p_vect& index_ordered){
	p_vect ret(to_order.size());
	for (p_vect::size_type i = 0; i < index_ordered.size(); i++)
		ret[i] = to_order[index_ordered[i]];
	return ret;
}

p_vect	PmergeMe::get_pairs_ordered(p_vect_pairs& to_order, p_vect& index_ordered){
	p_vect ret(to_order.size());
	for (p_vect::size_type i = 0; i < index_ordered.size(); i++)
		ret[i] = to_order[index_ordered[i]][0];
	return ret;
}

IData::~IData() {}
PmergeMe::~PmergeMe() {}
