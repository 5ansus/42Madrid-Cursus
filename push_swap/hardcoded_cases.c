/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcoded_cases.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:04:37 by sanferna          #+#    #+#             */
/*   Updated: 2024/09/02 15:43:43 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	order_five_numbers(t_llist ***stacks);
static void	order_four_numbers(t_llist ***stacks);
static void	order_three_numbers(t_llist ***stacks);
static int	locate_number(t_llist *stack, int size, int number);

void	hardcoded_cases(t_llist ***stacks, int size)
{
	const t_func_type	order_case[] = {order_three_numbers,
		order_four_numbers, order_five_numbers};

	if (size == 2)
	{
		if (is_ordered_numeric_stop((*stacks)[A], 2) != 1)
			swap(*stacks, STACK_A);
		return ;
	}
	order_case[size - 3](stacks);
}

static void	order_five_numbers(t_llist ***stacks)
{
	int	big_number_pos;

	big_number_pos = locate_number((*stacks)[A], 5, 5);
	if (big_number_pos == 0)
		push(*stacks, STACK_B);
	if (big_number_pos == 1 || big_number_pos == 2)
	{
		if (big_number_pos == 2)
			rotate(*stacks, STACK_A);
		rotate(*stacks, STACK_A);
		push(*stacks, STACK_B);
	}
	if (big_number_pos == 3 || big_number_pos == 4)
	{
		if (big_number_pos == 3)
			reverse_rotate(*stacks, STACK_A);
		reverse_rotate(*stacks, STACK_A);
		push(*stacks, STACK_B);
	}
	order_four_numbers(stacks);
}

static void	order_four_numbers(t_llist ***stacks)
{
	int	big_number_pos;

	if (is_ordered_numeric_stop((*stacks)[A], 4) == 1)
		return (clear_stack_b_to_bot_a(stacks));
	big_number_pos = locate_number((*stacks)[A], 4, 4);
	if (big_number_pos == 0)
		push(*stacks, STACK_B);
	if (big_number_pos == 1 || big_number_pos == 2)
	{
		if (big_number_pos == 2)
			rotate(*stacks, STACK_A);
		rotate(*stacks, STACK_A);
		push(*stacks, STACK_B);
	}
	if (big_number_pos == 3)
	{
		reverse_rotate(*stacks, STACK_A);
		push(*stacks, STACK_B);
	}
	order_three_numbers(stacks);
}

static void	order_three_numbers(t_llist ***stacks)
{
	int	big_number_pos;
	int	*content;

	if (is_ordered_numeric_stop((*stacks)[A], 3) == 1)
		return (clear_stack_b_to_bot_a(stacks));
	big_number_pos = locate_number((*stacks)[A], 3, 3);
	content = (int *)(*stacks)[A]->content;
	if (big_number_pos == 0)
	{
		rotate(*stacks, STACK_A);
		if (is_ordered_numeric_stop((*stacks)[A], 2) != 1)
			swap(*stacks, STACK_A);
		clear_stack_b_to_bot_a(stacks);
		return ;
	}
	if (big_number_pos == 1 && *content == 1)
	{
		swap(*stacks, STACK_A);
		rotate(*stacks, STACK_A);
	}
	if (big_number_pos == 1 && *content == 2)
		reverse_rotate(*stacks, STACK_A);
	if (big_number_pos == 2 && is_ordered_numeric_stop((*stacks)[A], 2) != 1)
		swap(*stacks, STACK_A);
	clear_stack_b_to_bot_a(stacks);
}

int	locate_number(t_llist *stack, int size, int number)
{
	int		i;
	int		*content;
	t_llist	*node;

	i = 0;
	node = stack;
	while (node != NULL && i < size)
	{
		content = (int *) node->content;
		if (*content == number)
			return (i);
		i++;
		node = node->next;
	}
	return (-1);
}
