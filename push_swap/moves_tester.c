/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:18:09 by sanferna          #+#    #+#             */
/*   Updated: 2024/08/13 22:15:20 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// gcc -g3 llst_tester.c llist.c libft/libft.a
// valgrind --leak-check=full ./a.out

void printer(void *p)
{
	int *num;

	num = (int *)p;
	ft_printf("%d", *num);
}

int main()
{
	t_llist *stack_a;
	t_llist *stack_b = NULL;
	int a = 2;
	int b = 1;
	int c = 3;
	int d = 6;
	int e = 5;
	int f = 8;

	stack_a = ft_llst_new(&a);
	ft_llst_push_bot(&stack_a, ft_llst_new(&b));
	ft_llst_push_bot(&stack_a, ft_llst_new(&c));
	ft_llst_push_bot(&stack_a, ft_llst_new(&d));
	ft_llst_push_bot(&stack_a, ft_llst_new(&e));
	ft_llst_push_bot(&stack_a, ft_llst_new(&f));
	ft_llst_print(&stack_a, printer);
	ft_printf("-----------------------------\n");

	swap(&stack_a, STACK_A);
	push(&stack_a, &stack_b, STACK_B);
	push(&stack_a, &stack_b, STACK_B);
	push(&stack_a, &stack_b, STACK_B);
	rotate(&stack_a, STACK_A);
	rotate(&stack_b, STACK_B);
	double_reverse_rotate(&stack_a, &stack_b);
	swap(&stack_a, STACK_A);
	push(&stack_a, &stack_b, STACK_A);
	push(&stack_a, &stack_b, STACK_A);
	push(&stack_a, &stack_b, STACK_A);
	ft_printf("-----------------------------\n");
	
	ft_llst_print(&stack_a, printer);
	ft_printf("-----------------------------\n");
	return (0);
}