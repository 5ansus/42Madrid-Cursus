/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:18:09 by sanferna          #+#    #+#             */
/*   Updated: 2024/08/08 16:33:44 by sanferna         ###   ########.fr       */
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

	lst = ft_llst_new(&a);
	ft_llst_push_bot(&lst, ft_llst_new(&b));
	ft_llst_push_bot(&lst, ft_llst_new(&c));
	ft_llst_push_bot(&lst, ft_llst_new(&d));
	ft_llst_print(&lst, printer);
	ft_printf("-----------------------------\n");
	ft_llst_clear(&lst, NULL);
	ft_llst_push_top(&lst, ft_llst_new(&a));
	ft_llst_push_top(&lst, ft_llst_new(&b));
	ft_llst_push_top(&lst, ft_llst_new(&c));
	ft_llst_push_top(&lst, ft_llst_new(&d));
	ft_llst_print(&lst, printer);

	ft_printf("-----------------------------\n");
	ft_printf("Detach node\n");
	t_llist *p = ft_llst_detach_node(&lst);
	ft_llst_print(&lst, printer);
	ft_printf("Detached:\n");
	ft_llst_print(&p, printer);
	ft_llst_clear(&lst, NULL);
	ft_llst_clear(&p, NULL);
	return (0);
}
