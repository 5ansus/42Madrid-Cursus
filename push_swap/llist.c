/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 11:13:43 by sanferna          #+#    #+#             */
/*   Updated: 2024/07/28 17:35:25 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_llist	*llst_new(void *content)
{
	t_llist	*new;

	new = (t_llist *)malloc(sizeof(t_llist));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = new;
	new->prev = new;
	return (new);
}

void	llst_add_next_and_advance(t_llist **lst, t_llist *new)
{
	if (lst == NULL || new == NULL)
		return;
	//Cero elementos
	if (*lst == NULL)
	{
		*lst = new;
		new->next = *lst;
		new->prev = *lst;
		return;
	}
	// Solo está un elemento en la lista
	if (((*lst)->prev == *lst))
	{
		(*lst)->next = new;
		(*lst)->prev = new;
		new->next = *lst;
		new->prev = *lst;
	}
	else
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev->next = new;
		(*lst)->prev = new;
	}
	*lst = new;
	return;
}

void	llst_add_last_and_keep(t_llist **lst, t_llist *new)
{
	if (lst == NULL || new == NULL)
		return;
	if (*lst == NULL)
	{
		*lst = new;
		new->next = *lst;
		new->prev = *lst;
		return;
	}
	new->next = *lst;
	new->prev = (*lst)->prev;
	(*lst)->prev->next = new;
	(*lst)->prev = new;
	return ;
}

void	llst_print(t_llist **lst,void (*p)(void *))
{
	t_llist	*node;

	if (lst == NULL)
		return ;
	node = *lst;
	ft_printf("Node: %p", node);
	if (p != NULL)
		p(node->content);
	ft_printf("\nPrev %p", node->prev);
	ft_printf("\nNext %p", node->next);
	ft_printf("\n");
	while (node->next != *lst)
	{
		node = node->next;
		ft_printf("Node: %p", node);
		if (p != NULL)
			p(node->content);
		ft_printf("\nPrev %p", node->prev);
		ft_printf("\nNext %p", node->next);
		ft_printf("\n");
	}
}

void llst_delete(t_llist **lst, void (*del)(void *))
{
	t_llist	*node;
	t_llist *next_node;
	t_llist *first_node;

	if (lst == NULL || *lst == NULL)
		return ;

	first_node = *lst;
	node = *lst;
	if (del != NULL)
		del(node->content);
	next_node = node->next;
	free(node);
	node = next_node;
	while (node != first_node)
	{
		if (del != NULL)
			del(node->content);
		next_node = node->next;
		free(node);
		node = next_node;
	}
	*lst = NULL;
}

t_llist	*llst_detach_node(t_llist **lst)
{
	t_llist	*node;
	t_llist	*prev;
	t_llist	*next;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	node = *lst;
	prev = node->prev;
	next = node->next;
	if (prev == node && next == node)
	{
		*lst = NULL;
		return (node);
	}
	prev->next = next;
	next->prev = prev;
	*lst = next;
	return (node);
}
