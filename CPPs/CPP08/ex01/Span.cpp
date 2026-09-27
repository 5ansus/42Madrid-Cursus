/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/27 16:53:37 by sansus            #+#    #+#             */
/*   Updated: 2026/09/27 18:29:11 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0) {};
Span::Span(unsigned int N) : _maxSize(N) {};
Span::Span(const Span& other) : _maxSize(other._maxSize), _data(other._data) {};
Span	Span::operator=(const Span& other){
	if (this != &other)
		return (*this);
	_maxSize = other._maxSize;
	_data = other._data;
	return (*this);
};

void	Span::addNumber(int number){
	if (_data.size() >= _maxSize)
		throw Span::SpanFull();
	_data.push_back(number);
}

int	Span::longestSpan(){
	if (_data.size() < 2)
		throw Span::SpanNotEnoughMembers();
	int	max = *std::max_element(_data.begin(), _data.end());
	int	min = *std::min_element(_data.begin(), _data.end());
	return (max - min);
}

int	Span::shortestSpan(){
	if (_data.size() < 2)
		throw Span::SpanNotEnoughMembers();
	unsigned int	min_span = INT_MAX;
	unsigned int	temp_diff = 0;
	std::vector<int> ordered = _data;
	std::sort(ordered.begin(), ordered.end());
	for (unsigned int i = 0; i < _data.size() - 1; ++i){
		temp_diff = _data[i + 1] - _data[i];
		if (temp_diff < min_span)
			min_span = temp_diff;
	}
	return min_span;
}

template <typename T>
void	Span::addRange(T start, T end){
	unsigned int	numbers_to_add = 0;
	for (T iter = start; iter != end; ++iter)
		++numbers_to_add;
	if (_data.size() + numbers_to_add > _maxSize)
		throw Span::SpanFull();
	for (T iter = start; iter != end; ++iter)
		_data.push_back(*iter);
}

const char* Span::SpanFull::what() const throw() {
	return "ERROR: The insert couldn't be done. The Span is at it full (or would overflow if you're using range)";
}

const char* Span::SpanNotEnoughMembers::what() const throw() {
	return "ERROR: Span operation doesn't make sense as there are less than 2 members";
}

std::ostream& operator<<(std::ostream &os, const Span &span){
	os << "Span - Size(" << span.current_size() << "): {";
	for (unsigned int i = 0; i < span.current_size(); i++)
		os << " " << span[i];
	os << " }";
	return os;
}

unsigned int Span::current_size() const{
	return	_data.size();
}

int Span::operator[](unsigned int index) const{
	if (index >= current_size())
		throw std::runtime_error("Index overflow (at this moment)");
	return _data[index];
}

Span::~Span(){};
