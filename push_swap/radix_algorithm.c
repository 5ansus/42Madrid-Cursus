/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:39:47 by sanferna          #+#    #+#             */
/*   Updated: 2024/09/02 15:22:13 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ceiling_logarithm(int argument, int base);
static void	send_to_b(t_llist ***stacks, int size, int iteration);

void	order_stack(t_llist ***stacks, int size)
{
	int	max_digit;
	int	iteration;

	if (size <= 5)
	{
		hardcoded_cases(stacks, size);
		return ;
	}
	iteration = 0;
	max_digit = ceiling_logarithm(size, 2);
	while(iteration < max_digit)
	{
		send_to_b(stacks, size, iteration);
		while ((*stacks)[B] != NULL)
			push(*stacks, STACK_A);
		iteration++;
	}
}

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

static void	send_to_b(t_llist ***stacks, int size, int iteration)
{
	int	i;
	int	*content;
	int	number;

	i = 0;
	while (i < size)
	{
		content = (int *) ((*stacks)[A])->content;
		number = (*content) << (31 - iteration);
		// ft_printf("%d\n", number);
		// ft_printf("%d\n", *content);
		if (number < 0)
			rotate(*stacks, STACK_A);
		else
			push(*stacks, STACK_B);
		i++;
	}
}
