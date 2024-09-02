/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcoded_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:04:37 by sanferna          #+#    #+#             */
/*   Updated: 2024/09/02 14:17:08 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
typedef void (*t_func_type)(t_llist ***);

static void	order_five_numbers(t_llist ***stacks);
static void	order_four_numbers(t_llist ***stacks);
static void	order_three_numbers(t_llist ***stacks);
static void	order_two_numbers(t_llist ***stacks);

void	hardcoded_cases(t_llist ***stacks, int size)
{
	t_func_type order_case[4] = {order_two_numbers, order_three_numbers,
									order_four_numbers, order_five_numbers};
	order_case[size - 2](stacks);
}

static void	order_five_numbers(t_llist ***stacks)
{
	int	big_number_pos;
	big_number_pos = locate_number((*stacks)[A], 5, 5);
	if (big_number_pos == 5)
	{
		push(*stacks, STACK_B);

	}
}
static void	order_four_numbers(t_llist ***stacks)
{
	int	*content;

	if (is_ordered_numeric_stop((*stacks)[A], 4) == 1)
	{
	}

	while((*stacks)[B] != NULL)
	{
		push(*stacks, STACK_A);
		rotate(*stacks, STACK_A);
	}
	order_three_numbers(stacks);
}

static void	order_three_numbers(t_llist ***stacks)
{
	int	big_number_pos;
	
	if (is_ordered_numeric_stop((*stacks)[A], 3) == 1)
	{
		ft_printf("Ordenado f3\n");
		return ;
	}
	big_number_pos = locate_number((*stacks)[A], 3, 3);
	if (big_number_pos == 0)
		rotate(*stacks, STACK_A);
	if (big_number_pos == 1)
	{
		push(*stacks, STACK_B);
		swap(*stacks, STACK_A);
		push(*stacks, STACK_A);
	}
	
	order_two_numbers(stacks);
}

static void	order_two_numbers(t_llist ***stacks)
{
	if (is_ordered_numeric_stop((*stacks)[A], 2) == 1)
	{
		ft_printf("Ordenado f2\n");
		return ;
	}
	swap(*stacks, STACK_A);
}
