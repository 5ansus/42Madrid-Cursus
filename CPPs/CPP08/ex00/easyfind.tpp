/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/27 12:49:23 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/27 16:49:11 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
#define EASYFIND_TPP
#ifndef EASYFIND_HPP
#error __FILE__ has to be included only from its .hpp
#endif

template <typename T>
typename T::iterator easyfind(T& container, int target) {
	typename T::iterator	start = container.begin();
	typename T::iterator	end = container.end();
	typename T::iterator	ret = std::find(start, end, target);
	if (ret == end)
		throw(std::runtime_error("Value not found in container"));
	return (ret);
}

#endif
