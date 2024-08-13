/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:08:04 by sanferna          #+#    #+#             */
/*   Updated: 2024/08/13 21:10:20 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_llist	*stack_a;

	if (argc < 2)
	{
		ft_printf("Args insuficientes\n");
		return (1);
	}
	stack_a = NULL;
	if (validate_args(argc, argv, &stack_a) == -1)
		return (1);
	ft_llst_print(&stack_a, printer);
	ft_llst_clear(&stack_a, free);
	return (0);
}
