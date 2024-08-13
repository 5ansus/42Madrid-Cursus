/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 21:26:42 by sanferna          #+#    #+#             */
/*   Updated: 2024/08/13 21:45:00 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_llist **stack, char id_stack)
{
	if (stack == NULL || (id_stack != 'a' && id_stack != 'b') )
		return ;
	*stack = (*stack)->next;
	ft_printf("r%c", id_stack);
}

void	double_rotate(t_llist **stack_a, t_llist **stack_b)
{
	if (stack_a == NULL || stack_b == NULL )
		return ;
	*stack_a = (*stack_a)->next;
	*stack_b = (*stack_b)->next;
	ft_printf("rr");
}

void	reverse_rotate(t_llist **stack, char id_stack)
{
	if (stack == NULL || (id_stack != 'a' && id_stack != 'b') )
		return ;
	*stack = (*stack)->prev;
	ft_printf("rr%c", id_stack);
}

void	double_reverse_rotate(t_llist **stack_a, t_llist **stack_b)
{
	if (stack_a == NULL || stack_b == NULL)
		return ;
	*stack_a = (*stack_a)->prev;
	*stack_b = (*stack_b)->prev;
	ft_printf("rrr");
}