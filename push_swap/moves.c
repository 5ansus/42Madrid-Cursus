/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:34:32 by sanferna          #+#    #+#             */
/*   Updated: 2024/09/02 15:41:16 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_llist **stacks, int id_stack)
{
	t_llist	*node;

	if (id_stack == STACK_A)
	{
		if ((stacks[B]) == NULL)
			return ;
		node = ft_llst_detach_node(&(stacks[B]));
		ft_llst_push_top(&(stacks[A]), node);
		ft_printf("pa\n");
	}
	else if (id_stack == STACK_B)
	{
		if (stacks[A] == NULL)
			return ;
		node = ft_llst_detach_node(&(stacks[A]));
		ft_llst_push_top(&(stacks[B]), node);
		ft_printf("pb\n");
	}
}

void	swap(t_llist **stacks, int id_stack)
{
	t_llist	*top;
	t_llist	*new_top;
	t_llist	**stack;

	if (id_stack == STACK_A)
		stack = &(stacks[A]);
	if (id_stack == STACK_B)
		stack = &(stacks[B]);
	top = ft_llst_detach_node(stack);
	new_top = ft_llst_detach_node(stack);
	ft_llst_push_top(stack, top);
	ft_llst_push_top(stack, new_top);
	if (id_stack == STACK_A)
		ft_printf("sa\n");
	if (id_stack == STACK_B)
		ft_printf("sb\n");
}

void	double_swap(t_llist **stacks)
{
	t_llist	*top;
	t_llist	*new_top;

	top = ft_llst_detach_node(&(stacks[A]));
	new_top = ft_llst_detach_node(&(stacks[A]));
	ft_llst_push_top(&(stacks[A]), top);
	ft_llst_push_top(&(stacks[A]), new_top);
	top = ft_llst_detach_node(&(stacks[B]));
	new_top = ft_llst_detach_node(&(stacks[B]));
	ft_llst_push_top(&(stacks[B]), top);
	ft_llst_push_top(&(stacks[B]), new_top);
	ft_printf("ss\n");
}
