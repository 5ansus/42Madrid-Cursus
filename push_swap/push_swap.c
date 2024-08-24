/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:08:04 by sanferna          #+#    #+#             */
/*   Updated: 2024/08/24 18:39:16 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	order_stack(t_llist *stacks[], int first, int size, int pos);
static void	divide_stack(t_llist *stacks[], int first, int size, int pos);
static void	divide_from_A(t_llist *stacks[], int first, int size, int pos);
static void	divide_from_B(t_llist *stacks[], int first, int size, int pos);
// static void	stack_of_five(t_llist *stacks[], int first, int size, int pos);
int	main(int argc, char **argv)
{
	t_llist	*stacks[2];
	int		n_numbers;

	if (argc < 2)
		return (1);
	stacks[A] = NULL;
	stacks[B] = NULL;
	n_numbers = validate_args(argc, argv, stacks);
	ft_printf("n_numbers: %d\n", n_numbers);
	if (n_numbers == -1)
		return (1);
	if (n_numbers != 0)
	{
		ft_llst_print(&stacks[A], printer);
		order_stack(stacks, 1, n_numbers, TOP_A);
		ft_llst_print(&stacks[A], printer);
		ft_llst_print(&stacks[B], printer);
		ft_llst_clear(&stacks[A], free);
	}
	return (0);
}

static void	order_stack(t_llist *stacks[], int first, int size, int pos)
{
	int	div;

	div = size / 3;
	if (size <= 5)
		// stack_of_five(stacks, first, size, pos);
		{
				if (pos == TOP_A)
		ft_printf("Ubicación: TOP_A\n");
	if (pos == BOT_A)
		ft_printf("Ubicación: BOT_A\n");
	if (pos == TOP_B)
		ft_printf("Ubicación: TOP_B\n");
	if (pos == BOT_B)
		ft_printf("Ubicación: BOT_B\n");
	ft_printf("Fin de la recursión. Rango: %d -- %d\n", first, first + size - 1);
		}
	else
	{
		ft_printf("Empezando, hay que dividir %d elementos, empezando por %d\n", size, first);
		divide_stack(stacks, first, size, pos);
		if (pos == TOP_A || pos == BOT_A)
		{
			if (pos == TOP_A && first == 1)
				order_stack(stacks, first + div * 2, size - div * 2, pos);
			else
				order_stack(stacks, first + div * 2, size - div * 2, -pos);
			order_stack(stacks, first + div, div, TOP_B);
			order_stack(stacks, first, div, BOT_B);
		}
		else if (pos == TOP_B || pos == BOT_B)
		{
			order_stack(stacks, first + div * 2, size - div * 2, TOP_A);
			order_stack(stacks, first + div, div, BOT_A);
			order_stack(stacks, first, div, -pos);
		}
	}
}

static void	divide_stack(t_llist *stacks[], int first, int size, int pos)
{
	if (pos == TOP_A || pos == BOT_A)
		divide_from_A(stacks, first, size, pos);
	if (pos == TOP_B || pos == BOT_B)
		divide_from_B(stacks, first, size, pos);
}

static void	divide_from_A(t_llist *stacks[], int first, int size, int pos)
{
	int	i;
	int	div;
	int	*content;

	i = 0;
	div = size / 3;
	while (i < size)
	{
		content = (int *) (*stacks)[A].content;
		if (pos == BOT_A)
			reverse_rotate(stacks, STACK_A);
		if (*content < 2 * div + first)
		{
			push(stacks, STACK_B);
			if (*content< div + first)
				rotate(stacks, STACK_B);
		}
		else if (pos == TOP_A)
			rotate(stacks, STACK_A);
		i++;
		ft_printf(">>%d\n", i);
	}
}

static void	divide_from_B(t_llist *stacks[], int first, int size, int pos)
{
	int	i;
	int	div;
	int	*content;

	i = 0;
	div = size / 3;
	while (i < size)
	{
		content = (int *) (*stacks)[B].content;
		if (pos == BOT_B)
			reverse_rotate(stacks, STACK_B);
		if (*content < div + first && pos == TOP_B)
			rotate(stacks, STACK_B);
		else if (*content < 2 * div + first)
		{
			push(stacks, STACK_A);
			if (*content < div + first)
				rotate(stacks, STACK_B);
		}
		i++;
	}
}

// static void	stack_of_five(t_llist *stacks[], int first, int size, int pos)
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
