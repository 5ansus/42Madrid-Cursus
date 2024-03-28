/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_extend.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:44:26 by sanferna          #+#    #+#             */
/*   Updated: 2024/03/28 15:15:36 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	scan_rec(t_bst *node);
int	bst_order(t_bst **tree)
{
	t_bst	*root;

	root = *tree;
	if (root == NULL)
		return (-1);
	scan_rec(root);
	return (0);
}

static void	scan_rec(t_bst *node)
{
	static unsigned int	i = 0;
	int	*dir;

	if (node == NULL)
		return;
	dir = (int *) node->content;
	if (dir == NULL)
		return;
	scan_rec(node->left);
	*dir = i;
	i++;
	scan_rec(node->right);
}
