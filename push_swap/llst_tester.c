/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llst_tester.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:18:09 by sanferna          #+#    #+#             */
/*   Updated: 2024/06/13 13:35:56 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void printer(void *p)
{
	int *num;

	num = (int *)p;
	ft_printf("%d", *num);
}

int main()
{
	t_llist *lst;
	int a = 1;
	int b = 2;
	int c = 3;
	int d = 4;

	lst = llst_new(&a);
	llst_add_back(&lst, llst_new(&b));
	llst_add_back(&lst, llst_new(&c));
	llst_add_back(&lst, llst_new(&d));
	llst_print(&lst, printer);
	llst_delete(&lst, NULL);
	return (0);
}