/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:18:09 by sanferna          #+#    #+#             */
/*   Updated: 2024/08/29 17:09:44 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// gcc -g3 moves_tester.c moves.c moves_rotate.c libft/libft.a
// valgrind --leak-check=full ./a.out

void printer(void *p)
{
	int *num;

	num = (int *)p;
	ft_printf("%d", *num);
}

int main()
{
	// t_llist *stack_a;
	// t_llist *stack_b = NULL;
	t_llist **stacks;

	stacks = malloc(2 * sizeof(t_llist *));
	stacks[A] = NULL;
	stacks[B] = NULL;
	int a = 2;
	int b = 1;
	int c = 3;
	int d = 6;
	int e = 5;
	int f = 8;

	stacks[A] = ft_llst_new(&a);
	ft_llst_push_bot(&stacks[A], ft_llst_new(&b));
	ft_llst_push_bot(&stacks[A], ft_llst_new(&c));
	ft_llst_push_bot(&stacks[A], ft_llst_new(&d));
	ft_llst_push_bot(&stacks[A], ft_llst_new(&e));
	ft_llst_push_bot(&stacks[A], ft_llst_new(&f));
	ft_llst_print(&stacks[A], printer);
	ft_printf("-----------------------------\n");

	swap(stacks, STACK_A);
	push(stacks, STACK_B);
	push(stacks, STACK_B);
	push(stacks, STACK_B);
	rotate(stacks, STACK_A);
	rotate(stacks, STACK_B);
	double_reverse_rotate(stacks);
	swap(stacks, STACK_A);
	push(stacks, STACK_A);
	push(stacks, STACK_A);
	push(stacks, STACK_A);
	ft_printf("-----------------------------\n");

	ft_llst_print(&stacks[A], printer);
	ft_printf("-----------------------------\n");
	ft_llst_clear(&stacks[A], NULL);

	free(stacks);
	return (0);
}
