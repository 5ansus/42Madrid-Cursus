/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/29 23:58:24 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/30 00:52:16 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

IData::IData(int index, int value): _index(index), _value(value){};

PmergeMe::p_vect& PmergeMe::get_index_order(const p_vect& iter){
	p_vect ret;
	p_vect_pairs original_indexes;
	for (int i = 0; i < iter.size(); i++){
		original_indexes.push_back(IData(i, iter[i]));
	}

	p_vect_pairs winners;
	p_vect_pairs lossers;
}
