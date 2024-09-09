/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_algorithm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:33:20 by sanferna          #+#    #+#             */
/*   Updated: 2024/09/09 17:19:44 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	divide_stack(t_llist ***stacks, int first, int size, int pos);
static void	divide_from_A(t_llist ***stacks, int first, int size, int pos);
static void	divide_from_B(t_llist ***stacks, int first, int size, int pos);
// static void	stack_of_five(t_llist **stacks, int first, int size, int pos);

void	order_stack(t_llist ***stacks, int first, int size, int pos)
{
	int	div;

	div = size / 5;
	if (size <= 5)
		// stack_of_five(stacks, first, size, pos);
		{
			ft_printf("Fin de la recursión. Rango: %d -- %d\n", first, first + size - 1);
			return;
			//	if (pos == TOP_A)
		// ft_printf("Ubicación: TOP_A\n");
		// if (pos == BOT_A)
		// 	ft_printf("Ubicación: BOT_A\n");
		// if (pos == TOP_B)
		// 	ft_printf("Ubicación: TOP_B\n");
		// if (pos == BOT_B)
		// 	ft_printf("Ubicación: BOT_B\n");
		// ft_printf("Fin de la recursión. Rango: %d -- %d\n", first, first + size - 1);
		// ft_llst_print(&(*stacks)[A], printer);
		// ft_llst_print(&(*stacks)[B], printer);
		}
	else
	{
		ft_printf("Empezando, hay que dividir %d elementos, empezando por %d\n", size, first);
		divide_stack(stacks, first, size, pos);
		if (pos == TOP_A || pos == BOT_A)
		{
			order_stack(stacks, first + div + size / 3, size - div - size / 3, -pos);
			order_stack(stacks, first + div, size / 3, TOP_B);
			order_stack(stacks, first, div, BOT_B);
		}
		else if (pos == TOP_B || pos == BOT_B)
		{
			order_stack(stacks, first + div + size / 3, size - div - size / 3, TOP_A);
			order_stack(stacks, first + div, size / 3, BOT_A);
			order_stack(stacks, first, div, -pos);
		}
	}
}

static void	divide_stack(t_llist ***stacks, int first, int size, int pos)
{
	if (pos == TOP_A || pos == BOT_A)
		divide_from_A(stacks, first, size, pos);
	if (pos == TOP_B || pos == BOT_B)
		divide_from_B(stacks, first, size, pos);
}

static void	divide_from_A(t_llist ***stacks, int first, int size, int pos)
{
	int	i;
	int	div;
	int	*content;

	i = 0;
	div = size / 5;
	while (i < size)
	{
		if (pos == BOT_A)
			reverse_rotate(*stacks, STACK_A);
		content = (int *) (*stacks)[A]->content;
		//ft_printf("%c -- %d -- %d -- %d\n", (pos == BOT_A) ? 'a' : 'A',*content, first, size);
		if (*content < 2 * div + first)
		{
			push(*stacks, STACK_B);
			if (*content < div + first)
				rotate(*stacks, STACK_B);
		}
		else if (pos == TOP_A)
			rotate(*stacks, STACK_A);
		i++;
		//ft_printf(">>%d -- %X\n", i, pos);
	}
}

static void	divide_from_B(t_llist ***stacks, int first, int size, int pos)
{
	int	i;
	int	div;
	int	*content;

	i = 0;
	div = size / 5;
	while (i < size)
	{
		if (pos == BOT_B)
			reverse_rotate(*stacks, STACK_B);
		content = (int *) (*stacks)[B]->content;
		//ft_printf("%d\n", *content);
		if (*content < div + first && pos == TOP_B)
			rotate(*stacks, STACK_B);
		else if (*content < 2 * div + first)
		{
			push(*stacks, STACK_A);
			if (*content < div + first)
				rotate(*stacks, STACK_B);
		}
		i++;
		//ft_printf(">>%d -- %X\n", i, pos);
	}
}

// static void	stack_of_five(t_llist **stacks, int first, int size, int pos)
// {
// 	if (pos == TOP_A)
// 		ft_printf("Ubicación: TOP_A\n");
// 	if (pos == BOT_A)
// 		ft_printf("Ubicación: BOT_A\n");
// 	if (pos == TOP_B)
// 		ft_printf("Ubicación: TOP_B\n");
// 	if (pos == BOT_B)
// 		ft_printf("Ubicación: BOT_B\n");
// 	ft_printf("Fin de la recursión. Rango: %d -- %d\n", first, first + size - 1);
// 	ft_llst_print(&stacks[A], printer);
// 	ft_printf("-------------\n");
// }