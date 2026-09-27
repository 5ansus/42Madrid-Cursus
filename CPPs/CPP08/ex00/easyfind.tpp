/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/27 12:49:23 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/27 14:28:11 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP
#ifndef EASYFIND_HPP
#error __FILE__ has to be included only from its .hpp
#endif

// template <typename T>
// typename T::const_iterator easyfind(const T& container, int target) {
// 	typename T::const_iterator iter = container.begin();
// 	typename T::const_iterator end = container.end();
// 	for ( ; iter != end; ++iter){
// 		if (*iter == target)
// 			return iter;
// 	}
// 	throw(std::runtime_error("Value not found in container"));
// }

template <typename T>
typename T::iterator easyfind(T& container, int target) {
	typename T::iterator iter = container.begin();
	typename T::iterator end = container.end();
	for ( ; iter != end; ++iter){
		if (*iter == target)
			return iter;
	}
	throw(std::runtime_error("Value not found in container"));
}

#endif
