/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:59:19 by sanferna          #+#    #+#             */
/*   Updated: 2024/06/13 13:23:46 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "./libft/libft.h"

typedef struct s_llist
{
	void			*content;
	struct s_llist	*next;
	struct s_llist	*prev;
}					t_llist;

int	bst_order(t_bst **tree);
t_llist	*llst_new(void *content);
void	llst_add_front(t_llist **lst, t_llist *new);
void	llst_add_back(t_llist **lst, t_llist *new);
void	llst_print(t_llist **lst, void (*p)(void *));
void	llst_delete(t_llist **lst, void (*del)(void *));
#endif
