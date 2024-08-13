/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:34:32 by sanferna          #+#    #+#             */
/*   Updated: 2024/08/13 21:11:17 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printer(void *p)
{
	int	*num;

	num = (int *)p;
	ft_printf("%d", *num);
}

int	compare(void *n1, void *n2)
{
	int	num1;
	int	num2;

	num1 = *((int *)n1);
	num2 = *((int *)n2);
	return (num1 - num2);
}

void	*ft_concatealloc(void *dst, void *src, char *sep)
{
	char	*tmp;
	char	*ret;

	tmp = NULL;
	if (src == NULL || sep == NULL)
		return (NULL);
	tmp = ft_strjoin(sep, src);
	if (tmp == NULL)
		return (NULL);
	ft_striteri(tmp, standarize_spaces);
	ret = ft_realloc(dst, tmp);
	if (ret == dst || ret == NULL)
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (ret);
}

void	ft_clear_split(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	clear(t_bst **tree, t_llist **stack_a, t_llist **stack_b, char **split)
{
	if (tree != NULL)
		ft_bstclear(tree, free);
	if (stack_a != NULL)
		ft_llst_clear(stack_a, NULL);
	if (stack_b != NULL)
		ft_llst_clear(stack_b, NULL);
	if (split != NULL)
		ft_clear_split(split);
	return (-1);
}
