/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:18:09 by sanferna          #+#    #+#             */
/*   Updated: 2024/07/28 17:36:39 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// gcc -g3 llst_tester.c llist.c libft/libft.a
// valgrind --leak-check=full ./a.out

void printer(void *p)
{
	int *num;

	num = (int *)p;
	ft_printf(" -- %d", *num);
}

int main()
{
	t_llist *lst;
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;

	lst = llst_new(&a);
	llst_add_last_and_keep(&lst, llst_new(&b));
	llst_add_last_and_keep(&lst, llst_new(&c));
	llst_add_last_and_keep(&lst, llst_new(&d));
	
	llst_add_next_and_advance(&lst, llst_new(&b));
	llst_add_next_and_advance(&lst, llst_new(&c));
	llst_add_next_and_advance(&lst, llst_new(&d));
	llst_print(&lst, printer);
	t_list *p = llst_detach_node(&lst);
	llst_print(&lst, printer);
	llst_print(&p, printer);
	llst_delete(&lst, NULL);
	llst_delete(&p, NULL);
	return (0);
}