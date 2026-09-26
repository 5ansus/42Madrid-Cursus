#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>


template <typename T>
void	iter(const T *array, const unsigned int len, void (*f)(const T &value)){
	for (unsigned int i  = 0; i < len; i++){
		f(array[i]);
	}
}

template <typename T>
void	iter(T *array, const unsigned int len, void (*f)(T &value)){
	for (unsigned int i  = 0; i < len; i++){
		f(array[i]);
	}
}

// template <typename T>
// void	iter(T* array[], const unsigned int len, void (*f)(const T &value));

#endif
