/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/18 18:17:49 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/18 19:09:15 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr){
	uintptr_t ret = reinterpret_cast<uintptr_t>(ptr);
	return (ret);
}

Data* Serializer::deserialize(uintptr_t raw){
	Data *ret = reinterpret_cast<Data *>(raw);
	return (ret);
}
