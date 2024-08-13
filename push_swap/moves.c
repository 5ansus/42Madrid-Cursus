/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:34:32 by sanferna          #+#    #+#             */
/*   Updated: 2024/08/13 22:14:19 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_llist **stack_a, t_llist **stack_b, char id_stack)
{
	t_llist	*node;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (id_stack == 'a')
	{
		if (*stack_b == NULL)
			return ;
		node = ft_llst_detach_node(stack_b);
		ft_llst_push_top(stack_a, node);
	}
	else if (id_stack == 'b')
	{
		if (*stack_a == NULL)
			return ;
		node = ft_llst_detach_node(stack_a);
		ft_llst_push_top(stack_b, node);
	}
	ft_printf("p%c\n", id_stack);
}

void	swap(t_llist **stack, char id_stack)
{
	t_llist	*top;
	t_llist	*new_top;

	top = ft_llst_detach_node(stack);
	new_top = ft_llst_detach_node(stack);
	ft_llst_push_top(stack, top);
	ft_llst_push_top(stack, new_top);
	ft_printf("s%c\n", id_stack);
}

void	double_swap(t_llist **stack_a, t_llist **stack_b)
{
	t_llist	*top;
	t_llist	*new_top;

	top = ft_llst_detach_node(stack_a);
	new_top = ft_llst_detach_node(stack_a);
	ft_llst_push_top(stack_a, top);
	ft_llst_push_top(stack_a, new_top);
	top = ft_llst_detach_node(stack_b);
	new_top = ft_llst_detach_node(stack_b);
	ft_llst_push_top(stack_b, top);
	ft_llst_push_top(stack_b, new_top);
	ft_printf("ss\n");
}
