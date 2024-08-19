/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:08:04 by sanferna          #+#    #+#             */
/*   Updated: 2024/08/19 16:46:36 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_stack(t_llist **stack_a, t_llist **stack_b, int size, int pos);

int	main(int argc, char **argv)
{
	t_llist	*stack_a;
	t_llist	*stack_b;
	int		n_numbers;

	if (argc < 2)
		return (1);
	stack_a = NULL;
	n_numbers = validate_args(argc, argv, &stack_a);
	ft_printf("n_numbers: %d\n", n_numbers);
	if (n_numbers == -1)
		return (1);
	// ft_llst_print(&stack_a, printer);
	order_stack(&stack_a, &stack_b, n_numbers, TOP_A);
	ft_llst_clear(&stack_a, free);
	return (0);
}

static void	order_stack(t_llist **stack_a, t_llist **stack_b, int size, int pos)
{
	if (size <= 5)
	{

	}
	else
	{
		divide_stack(stack_a, stack_b, size, pos);
		if (pos == TOP_A || pos == BOT_A)
		{
			order_stack(stack_a, stack_b, size - (size / 3) * 2, -pos);
			order_stack(stack_a, stack_b, size / 3, TOP_B);
			order_stack(stack_a, stack_b, size / 3, BOT_B);
		}
		else if (pos == TOP_B || pos == BOT_B)
		{
			order_stack(stack_a, stack_b, size - (size / 3) * 2, TOP_A);
			order_stack(stack_a, stack_b, size / 3, BOT_A);
			order_stack(stack_a, stack_b, size / 3, -pos);
		}
	}
}

static void divide_stack(t_llist **stack_a, t_llist **stack_b, int size, int pos)
{
	if (pos == TOP_A || pos == BOT_A)
	{
		order_stack(stack_a, stack_b, size - (size / 3) * 2, -pos);
		order_stack(stack_a, stack_b, size / 3, TOP_B);
		order_stack(stack_a, stack_b, size / 3, BOT_B);
	}
}
