/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:26:42 by sanferna          #+#    #+#             */
/*   Updated: 2024/08/14 21:01:29 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_llist **stack_a, t_llist **stack_b, int id_stack)
{
	t_llist	**stack;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (id_stack == 0)
		stack = stack_a;
	if (id_stack == !0)
		stack = stack_b;
	if (*stack == NULL || *stack == (*stack)->next)
		return ;
	*stack = (*stack)->next;
	if (id_stack == 0)
		ft_printf("sa\n");
	if (id_stack == !0)
		ft_printf("sb\n");
}

void	double_rotate(t_llist **stack_a, t_llist **stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (*stack_a != NULL)
		*stack_a = (*stack_a)->next;
	if (*stack_b != NULL)
		*stack_b = (*stack_b)->next;
	ft_printf("rr\n");
}

void	reverse_rotate(t_llist **stack_a, t_llist **stack_b, int id_stack)
{
	t_llist	**stack;

	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (id_stack == 0)
		stack = stack_a;
	if (id_stack == !0)
		stack = stack_b;
	*stack = (*stack)->prev;
	if (id_stack == 0)
		ft_printf("rra\n");
	if (id_stack == !0)
		ft_printf("rrb\n");
}

void	double_reverse_rotate(t_llist **stack_a, t_llist **stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	if (*stack_a != NULL)
		*stack_a = (*stack_a)->prev;
	if (*stack_b != NULL)
		*stack_b = (*stack_b)->prev;
	ft_printf("rrr\n");
}
