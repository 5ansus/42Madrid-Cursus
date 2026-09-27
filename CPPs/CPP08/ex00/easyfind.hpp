/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/27 12:49:14 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/27 14:28:29 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

// template <typename T>
// typename T::const_iterator easyfind(const T& container, int target);

template <typename T>
typename T::iterator easyfind(T& container, int target);
#include "easyfind.tpp"

#endif
