/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:59:28 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/06 18:05:22 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*node_next;

	node = *lst;
	while (node != NULL)
	{
		node_next = node->next;
		del(node->content);
		free(node);
		node = node_next;
	}
	*lst = NULL;
}
