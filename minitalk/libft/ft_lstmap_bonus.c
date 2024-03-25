/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 18:09:20 by sanferna          #+#    #+#             */
/*   Updated: 2023/04/06 20:24:29 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*node;
	t_list	*new_node;
	void	*content;

	ret = NULL;
	node = lst;
	while (node != NULL)
	{
		content = f(node->content);
		new_node = ft_lstnew(content);
		if (new_node == NULL)
		{
			del(content);
			return (ft_lstclear(&ret, del), NULL);
		}
		ft_lstadd_back(&ret, new_node);
		node = node->next;
	}
	return (ret);
}
