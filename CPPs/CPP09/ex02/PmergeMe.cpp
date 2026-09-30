/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/29 23:58:24 by sanferna          #+#    #+#             */
/*   Updated: 2026/10/01 01:12:06 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"

IData::IData(int index, int value) : _index(index), _value(value) {};
IData::IData() : _index(-1), _value(-1) {};
IData::IData(const IData& other)
	: _index(other._index), _value(other._value) {};
IData& IData::operator=(const IData& other) {
	if (this != &other) {
		_index = other._index;
		_value = other._value;
	}
	return (*this);
};

bool IData::operator<(const IData& other) const {
	return this->_value < other._value;
}

const int& IData::operator[](int index) const {
	if (index == 1) return _value;
	return _index;
}

bool IData::is_valid() const {
	if (_index == -1) return false;
	return true;
}

p_vect PmergeMe::get_index_order(const p_vect& iter) {
	p_vect ret;
	if (iter.size() == 1) {
		ret.push_back(0);
		return ret;
	}
	p_vect_pairs original_indexes;
	for (p_vect::size_type i = 0; i < iter.size(); i++) {
		original_indexes.push_back(IData(i, iter[i]));
	}

	p_vect_pairs winners;
	p_vect_pairs lossers;
	IData extra;
	if (iter.size() % 2 != 0) extra = original_indexes[iter.size() - 1];
	for (p_vect::size_type i = 1; i < iter.size(); i += 2) {
		if (original_indexes[i] < original_indexes[i - 1]) {
			winners.push_back(original_indexes[i - 1]);
			lossers.push_back(original_indexes[i]);
		} else {
			lossers.push_back(original_indexes[i - 1]);
			winners.push_back(original_indexes[i]);
		}
	}
	p_vect winners_order = get_index_order(extract_p_vect(winners));
	p_vect_pairs winnners_ordered = get_container_ordered(winners, winners_order);
	p_vect_pairs losers_ordered = get_container_ordered(lossers, winners_order);

	p_vect_pairs iter_order = insert_with_jakobstal(winnners_ordered, losers_ordered, extra);

	p_vect permutation_to_previous_level = extract_p_indexes(iter_order);

	return (permutation_to_previous_level);
}

p_vect extract_p_vect(const p_vect_pairs& pv_data) {
	p_vect ret;
	for (p_vect::size_type i = 0; i < pv_data.size(); i++)
		ret.push_back(pv_data[i][1]);
	return ret;
}

p_vect extract_p_indexes(const p_vect_pairs& pv_data) {
	p_vect ret;
	for (p_vect::size_type i = 0; i < pv_data.size(); i++)
		ret.push_back(pv_data[i][0]);
	return ret;
}

void PmergeMe::MergeInsertionSort(p_vect& data_to_order) {
	if (data_to_order.size() == 0) return;
	p_vect data_order = get_index_order(data_to_order);
	p_vect data_odered = get_container_ordered(data_to_order, data_order);
	data_to_order = data_odered;
}

template <typename T>
T PmergeMe::get_container_ordered(T& to_order, p_vect& index_ordered) {
	T ret(to_order.size());
	for (p_vect::size_type i = 0; i < index_ordered.size(); i++)
		ret[i] = to_order[index_ordered[i]];
	return ret;
}

IData::~IData() {}
PmergeMe::~PmergeMe() {}

int jakobsthal(int n) {
	if (n == 0) return 0;
	if (n == 1) return 1;

	return jakobsthal(n - 1) + 2 * jakobsthal(n - 2);
}

int get_group_size(int iter) {
	if (iter <= 0) return -1;
	if (iter == 1) return 1;

	return jakobsthal(iter + 1) - jakobsthal(iter);
}

p_vect_pairs PmergeMe::insert_with_jakobstal(const p_vect_pairs& winners,
											 const p_vect_pairs& losers,
											 const IData& extra) {
	p_vect_pairs permutation_pairs;

	if (winners.size() == 1) {
		permutation_pairs.push_back(losers[0]);
		permutation_pairs.push_back(winners[0]);
		if (extra.is_valid()) {
			int insert_index = find_index(permutation_pairs, extra, permutation_pairs.size());
			permutation_pairs.insert(permutation_pairs.begin() + insert_index, extra);
		}
		return permutation_pairs;
	}
	permutation_pairs.push_back(losers[0]);

	for (p_vect::size_type i = 0; i < winners.size(); ++i)
		permutation_pairs.push_back(winners[i]);

	p_vect winners_ids_updated(winners.size());

	for (p_vect::size_type i = 0; i < winners.size(); ++i)
		winners_ids_updated[i] = i + 1;


	int iteration = 2;
	p_vect_pairs::size_type lower_index = 0;	// Marca el final (el inicio es el start_index) del grupo. Se actualiza con el num de indexes procesados
	int group_size;
	int start_index;

	while (lower_index < losers.size()) {
		group_size = ::get_group_size(iteration);
		start_index = std::min(
			lower_index + static_cast<p_vect_pairs::size_type>(group_size),
			losers.size() - 1);
		for (p_vect_pairs::size_type i = start_index; i > lower_index; --i) {
			IData to_insert = losers[i];
			int insert_index = find_index(permutation_pairs, to_insert, winners_ids_updated[i]);
			permutation_pairs.insert(permutation_pairs.begin() + insert_index, to_insert);
			for (p_vect::size_type j = 0; j < winners_ids_updated.size(); ++j)
			{
				if (winners_ids_updated[j] >= insert_index)
					++winners_ids_updated[j];
			}
		}
		lower_index += group_size;
		iteration++;
	}
	if (extra.is_valid()) {
		int insert_index = find_index(permutation_pairs, extra, permutation_pairs.size());
		permutation_pairs.insert(permutation_pairs.begin() + insert_index, extra);
	}
	return permutation_pairs;
}

int PmergeMe::find_index(const p_vect_pairs& vector, const IData& node, int max_index) {

	int	left = 0;
	int	right = max_index;
	while (left < right)
	{
		int mid = left + ((right - left) / 2);
		IData mid_node = vector[mid];
		if (node < mid_node)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

bool IData::operator==(const IData& other) const {
	return this->_value == other._value;
}


p_deque PmergeMe::get_index_order(const p_deque& iter) {
	p_deque ret;
	if (iter.size() == 1) {
		ret.push_back(0);
		return ret;
	}
	p_deque_pairs original_indexes;
	for (p_deque::size_type i = 0; i < iter.size(); i++) {
		original_indexes.push_back(IData(i, iter[i]));
	}

	p_deque_pairs winners;
	p_deque_pairs lossers;
	IData extra;
	if (iter.size() % 2 != 0) extra = original_indexes[iter.size() - 1];
	for (p_deque::size_type i = 1; i < iter.size(); i += 2) {
		if (original_indexes[i] < original_indexes[i - 1]) {
			winners.push_back(original_indexes[i - 1]);
			lossers.push_back(original_indexes[i]);
		} else {
			lossers.push_back(original_indexes[i - 1]);
			winners.push_back(original_indexes[i]);
		}
	}
	p_deque winners_order = get_index_order(extract_p_deque(winners));
	p_deque_pairs winnners_ordered = get_container_ordered(winners, winners_order);
	p_deque_pairs losers_ordered = get_container_ordered(lossers, winners_order);

	p_deque_pairs iter_order = insert_with_jakobstal(winnners_ordered, losers_ordered, extra);

	p_deque permutation_to_previous_level = extract_p_indexes(iter_order);

	return (permutation_to_previous_level);
}

p_deque extract_p_deque(const p_deque_pairs& pv_data) {
	p_deque ret;
	for (p_deque::size_type i = 0; i < pv_data.size(); i++)
		ret.push_back(pv_data[i][1]);
	return ret;
}

p_deque extract_p_indexes(const p_deque_pairs& pv_data) {
	p_deque ret;
	for (p_deque::size_type i = 0; i < pv_data.size(); i++)
		ret.push_back(pv_data[i][0]);
	return ret;
}

void PmergeMe::MergeInsertionSort(p_deque& data_to_order) {
	if (data_to_order.size() == 0) return;
	p_deque data_order = get_index_order(data_to_order);
	p_deque data_odered = get_container_ordered(data_to_order, data_order);
	data_to_order = data_odered;
}

template <typename T>
T PmergeMe::get_container_ordered(T& to_order, p_deque& index_ordered) {
	T ret(to_order.size());
	for (p_deque::size_type i = 0; i < index_ordered.size(); i++)
		ret[i] = to_order[index_ordered[i]];
	return ret;
}

p_deque_pairs PmergeMe::insert_with_jakobstal(const p_deque_pairs& winners,
											 const p_deque_pairs& losers,
											 const IData& extra) {
	p_deque_pairs permutation_pairs;

	if (winners.size() == 1) {
		permutation_pairs.push_back(losers[0]);
		permutation_pairs.push_back(winners[0]);
		if (extra.is_valid()) {
			int insert_index = find_index(permutation_pairs, extra, permutation_pairs.size());
			permutation_pairs.insert(permutation_pairs.begin() + insert_index, extra);
		}
		return permutation_pairs;
	}
	permutation_pairs.push_back(losers[0]);

	for (p_deque::size_type i = 0; i < winners.size(); ++i)
		permutation_pairs.push_back(winners[i]);

	p_deque winners_ids_updated(winners.size());

	for (p_deque::size_type i = 0; i < winners.size(); ++i)
		winners_ids_updated[i] = i + 1;


	int iteration = 2;
	p_deque_pairs::size_type lower_index = 0;	// Marca el final (el inicio es el start_index) del grupo. Se actualiza con el num de indexes procesados
	int group_size;
	int start_index;

	while (lower_index < losers.size()) {
		group_size = ::get_group_size(iteration);
		start_index = std::min(
			lower_index + static_cast<p_deque_pairs::size_type>(group_size),
			losers.size() - 1);
		for (p_deque_pairs::size_type i = start_index; i > lower_index; --i) {
			IData to_insert = losers[i];
			int insert_index = find_index(permutation_pairs, to_insert, winners_ids_updated[i]);
			permutation_pairs.insert(permutation_pairs.begin() + insert_index, to_insert);
			for (p_deque::size_type j = 0; j < winners_ids_updated.size(); ++j)
			{
				if (winners_ids_updated[j] >= insert_index)
					++winners_ids_updated[j];
			}
		}
		lower_index += group_size;
		iteration++;
	}
	if (extra.is_valid()) {
		int insert_index = find_index(permutation_pairs, extra, permutation_pairs.size());
		permutation_pairs.insert(permutation_pairs.begin() + insert_index, extra);
	}
	return permutation_pairs;
}

int PmergeMe::find_index(const p_deque_pairs& deque, const IData& node, int max_index) {

	int	left = 0;
	int	right = max_index;
	while (left < right)
	{
		int mid = left + ((right - left) / 2);
		IData mid_node = deque[mid];
		if (node < mid_node)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

