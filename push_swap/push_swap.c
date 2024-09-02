/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:08:04 by sanferna          #+#    #+#             */
/*   Updated: 2024/09/02 15:04:17 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//static int	is_ordered(t_llist *stack);

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
	//ft_printf("n_numbers: %d\n", n_numbers);
	if (n_numbers == -1)
		return (1);
	if (n_numbers != 0)
	{
		//ft_llst_print(&stacks[A], printer); 
		if (is_ordered_numeric_stop(stacks[A], n_numbers) == 1)
			return (ft_llst_clear(&stacks[A], free), free(stacks), 0);
		order_stack(&stacks, n_numbers);
		//ft_llst_print(&stacks[A], printer);
		// ft_llst_print(&stacks[B], printer);
		// if (is_ordered_numeric_stop(stacks[A], n_numbers) == 1)
		// {
		// 	ft_printf("Ordenado\n");
		// 	return (ft_llst_clear(&stacks[A], free), free(stacks), 0);
		// }
		ft_llst_clear(&stacks[A], free);
		free(stacks);
	}
	return (0);
}

// static int	is_ordered(t_llist *stack)
// {
// 	t_llist	*node;
// 	int		*content;
// 	int		*prev_content;

// 	node = stack->next;
// 	prev_content = (int *) stack->content;
// 	while(node != NULL && node != stack)
// 	{
// 		content = (int *) node->content;
// 		if (*prev_content > *content)
// 			return (0);
// 		prev_content = content;
// 		node = node->next;
// 	}
// 	return (1);
// }

int	is_ordered_numeric_stop(t_llist *stack, int size)
{
	t_llist	*node;
	int		*content;
	int		*prev_content;
	int		i;

	i = 1;
	node = stack->next;
	prev_content = (int *) stack->content;
	while(i < size)
	{
		content = (int *) node->content;
		if (*prev_content > *content)
			return (0);
		prev_content = content;
		node = node->next;
		i++;
	}
	return (1);
}
