/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/26 12:00:33 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/26 12:59:49 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

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

#endif
