/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/18 19:58:44 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/18 21:25:28 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>


int main(){
	srand(time(NULL));
	Base *obj;
	for (int i = 0; i < 10; i++)
	{
		obj = generate();
		identify(*obj);
		identify(obj);
	}
}
