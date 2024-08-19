/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:08:04 by sanferna          #+#    #+#             */
/*   Updated: 2024/08/19 18:28:44 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	order_stack(t_llist ***stacks, int size, int pos);

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
	ft_llst_print(&stacks[A], printer);
	// order_stack(&stacks, n_numbers, TOP_A);
	ft_llst_clear(&stacks[A], free);
	return (0);
}

// static void	order_stack(t_llist ***stacks, int size, int pos)
// {
// 	if (size <= 5)
// 	{

// 	}
// 	else
// 	{
// 		divide_stack(stacks, size, pos);
// 		if (pos == TOP_A || pos == BOT_A)
// 		{
// 			order_stack(stacks, size - (size / 3) * 2, -pos);
// 			order_stack(stacks, size / 3, TOP_B);
// 			order_stack(stacks, size / 3, BOT_B);
// 		}
// 		else if (pos == TOP_B || pos == BOT_B)
// 		{
// 			order_stack(stacks, size - (size / 3) * 2, TOP_A);
// 			order_stack(stacks, size / 3, BOT_A);
// 			order_stack(stacks, size / 3, -pos);
// 		}
// 	}
// }

// static void divide_stack(t_llist ***stacks, int size, int pos)
// {
// 	if (pos == TOP_A || pos == BOT_A)
// 	{
// 		order_stack(stacks, size - (size / 3) * 2, -pos);
// 		order_stack(stacks, size / 3, TOP_B);
// 		order_stack(stacks, size / 3, BOT_B);
// 	}
// }
