/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/18 21:55:34 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/26 13:01:44 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &d1, T &d2){
	T temp = d1;
	d1 = d2;
	d2 = temp;
}

template <typename T>
T min(T d1, T d2){
	if (d2 < d1)
		return d2;
	return d1;
}

template <typename T>
T max(T d1, T d2){
	if (d2 > d1)
		return d2;
	return d1;
}

#endif
