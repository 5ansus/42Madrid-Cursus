/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 20:36:43 by sanferna          #+#    #+#             */
/*   Updated: 2024/08/29 17:02:32 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		loop(t_bst **tree, t_llist *stacks[], char **args_str, int i);
static int		*validate_number(char *str);
static char		**parse_args(int argc, char **argv, int *n_numbers);

int	validate_args(int argc, char **argv, t_llist **stacks)
{
	int		n_numbers;
	char	**args_str;
	t_bst	*tree;
	int		i;

	i = 0;
	tree = NULL;
	args_str = parse_args(argc, argv, &n_numbers);
	if (args_str == NULL)
		return (ft_clear_split(args_str), -1);
	while (i < n_numbers)
	{
		if (loop(&tree, stacks, args_str, i) == -1)
			return (-1);
		i++;
	}
	ft_clear_split(args_str);
	//ft_bstprint(&tree, printer);
	bst_order(&tree);
	//ft_bstprint(&tree, printer);
	ft_bstclear(&tree, NULL);
	return (n_numbers);
}

static char	**parse_args(int argc, char **argv, int *n_numbers)
{
	char	*tmp;
	char	**ret;
	int		i;

	i = 0;
	tmp = NULL;
	while (++i < argc)
	{
		tmp = ft_concatealloc(tmp, argv[i], " ");
		if (tmp == NULL)
			return (NULL);
	}
	ret = ft_split(tmp, ' ');
	free(tmp);
	i = -1;
	while (ret[++i] != NULL)
	{
		if (ft_isstrnbr(ret[i]) == 0)
			return (ft_clear_split(ret), NULL);
	}
	*n_numbers = i;
	return (ret);
}

static int	*validate_number(char *str)
{
	ssize_t	len;
	int		*ret;
	long	tmp;

	len = ft_strlen(str);
	if (len > 11)
		return (NULL);
	tmp = ft_atol(str);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (NULL);
	ret = malloc(sizeof(int));
	if (ret == NULL)
		return (NULL);
	*ret = ft_atoi(str);
	return (ret);
}

void	standarize_spaces(unsigned int c, char *dir)
{
	c = 0;
	if (ft_isspace(*dir))
		*dir = ' ';
	c = c;
}

static int	loop(t_bst **tree, t_llist **stacks, char **args_str, int i)
{
	t_bst	*child_tree;
	t_llist	*new_node;
	int		*ret;

	ret = validate_number(args_str[i]);
	if (ret == NULL)
		return (clear(tree, stacks, args_str));
	child_tree = ft_bstnew((void *)ret);
	if (child_tree == NULL)
		return (clear(tree, stacks, args_str));
	if (ft_bstinsert(tree, child_tree, compare) != 0)
		return (ft_bstclear(&child_tree, free),
			clear(tree, stacks, args_str));
	new_node = ft_llst_new((void *)ret);
	if (new_node == NULL)
		return (clear(tree, stacks, args_str));
	ft_llst_push_bot(&(stacks[A]), new_node);
	return (0);
}
