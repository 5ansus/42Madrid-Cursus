/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/18 20:17:26 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/24 20:51:29 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib>

class Base {
	public:
		virtual ~Base();
};

#include "Base.tpp"


Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
