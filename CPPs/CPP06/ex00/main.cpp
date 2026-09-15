/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                 +#+#+#+#+#+   +#+          */
/*   Created: 2026/09/13 11:10:32 by sanferna          #+#    #+#             */
/*   Updated: 2026/09/15 19:29:57 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Converter.hpp"

int main (int argc, char *argv[]){
	if (argc == 2)
	Converter::convert(argv[1]);
}
// int i;
// try{
// 	i = format_int();
// 	i = format_char();
// 	i = i;

// }catch{
// i == i;

// }
