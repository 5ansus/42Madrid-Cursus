/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:26:42 by sanferna          #+#    #+#             */
/*   Updated: 2024/09/02 14:16:40 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_llist **stacks, int id_stack)
{
	t_llist	**stack;

	if (id_stack == STACK_A)
		stack = &stacks[A];
	if (id_stack == STACK_B)
		stack = &stacks[B];
	if (*stack == NULL || *stack == (*stack)->next)
		return ;
	*stack = (*stack)->next;
	if (id_stack == STACK_A)
		ft_printf("ra\n");
	if (id_stack == STACK_B)
		ft_printf("rb\n");
}

void	double_rotate(t_llist **stacks)
{
	if (stacks[A] != NULL)
		stacks[A] = stacks[A]->next;
	if (stacks[A] != NULL)
		stacks[B] = stacks[B]->next;
	ft_printf("rr\n");
}

void	reverse_rotate(t_llist **stacks, int id_stack)
{
	t_llist	**stack;

	if (id_stack == STACK_A)
		stack = &stacks[A];
	if (id_stack == STACK_B)
		stack = &stacks[B];
	*stack = (*stack)->prev;
	if (id_stack == STACK_A)
		ft_printf("rra\n");
	if (id_stack == STACK_B)
		ft_printf("rrb\n");
}

void	double_reverse_rotate(t_llist **stacks)
{
	if (stacks[A] != NULL)
		stacks[A] = stacks[A]->prev;
	if (stacks[B] != NULL)
		stacks[B] = stacks[B]->prev;
	ft_printf("rrr\n");
}

void	clear_stack_b_to_bot_a(t_llist ***stacks)
{
	while ((*stacks)[B] != NULL)
	{
		push(*stacks, STACK_A);
		rotate(*stacks, STACK_A);
	}
}