/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:08:04 by sanferna          #+#    #+#             */
/*   Updated: 2024/09/02 11:34:34 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_llist	**stacks;
	int		n_numbers;

	if (argc < 2)
		return (1);
	stacks = malloc(2 * sizeof(t_llist *));
	stacks[A] = NULL;
	stacks[B] = NULL;
	n_numbers = validate_args(argc, argv, stacks);
	ft_printf("n_numbers: %d\n", n_numbers);
	if (n_numbers == -1)
		return (1);
	if (n_numbers != 0)
	{
		//ft_llst_print(&stacks[A], printer);
		order_stack(&stacks, 1, n_numbers, TOP_A);
		// ft_llst_print(&stacks[A], printer);
		// ft_llst_print(&stacks[B], printer);
		ft_llst_clear(&stacks[A], free);
		ft_llst_clear(&stacks[B], free); //En la versión final no es necesario
		free(stacks);
	}
	return (0);
}
