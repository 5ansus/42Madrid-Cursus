/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:46:01 by sanferna          #+#    #+#             */
/*   Updated: 2024/09/02 12:10:28 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	ceiling_logarithm(int argument, int base)
{
	int					exponent;
	unsigned int	argument_conv;
	unsigned int	current_value;

	if (argument <= 0)
		return (-1);
	if (argument == 1)
		return (0);
	argument_conv = (unsigned int) argument;
	current_value = (unsigned int) base;
	exponent = 1;
	while (argument_conv > current_value)
	{
		current_value = current_value * base;
		exponent++;
	}
	return (exponent);
}
int main(){
	int max;
	max = ceiling_logarithm(100, 2);
	printf("%d\n", max);
	printf("%d\n", ceiling_logarithm(0, 2));
	printf("%d\n", ceiling_logarithm(1, 2));
	printf("%d\n", ceiling_logarithm(500, 2));
	printf("%d\n", ceiling_logarithm(512, 2));
	printf("%d\n", ceiling_logarithm(1024, 2));
	printf("%d\n", ceiling_logarithm(2046, 2));
	printf("%d\n", ceiling_logarithm(2047, 2));
	printf("%d\n", ceiling_logarithm(2048, 2));
	printf("%d\n", ceiling_logarithm(2049, 2));
	printf("%d\n", ceiling_logarithm(2050, 2));
}