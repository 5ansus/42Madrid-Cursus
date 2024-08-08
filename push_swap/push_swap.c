/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:08:04 by sanferna          #+#    #+#             */
/*   Updated: 2024/08/08 16:33:44 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void *ft_concatealloc(void *dst, void *src, char *sep);
int compare(void *n1, void *n2);
void replace_spaces(unsigned int c, char *str);
int validate_args(int argc, char **argv, t_llist **stack_a);
int *validate_number(char *str);
int clear(t_bst **tree, t_llist **stack_a, t_llist **stack_b, char **split);
char **parse_args(int argc, char **argv, int *n_numbers);
void printer(void *p);
void ft_clear_split(char **split);

int main(int argc, char **argv)
{
	t_llist *stack_a;

	if (argc < 2)
	{
		ft_printf("Args insuficientes\n");
		return 1;
	}
	stack_a = NULL;
	validate_args(argc, argv, &stack_a);
	ft_llst_print(&stack_a, printer);
	ft_llst_clear(&stack_a, free);
	// clear(&tree, &lista, NULL, NULL);
	return 0;
}

void *ft_concatealloc(void *dst, void *src, char *sep)
{
	char *tmp;
	char *ret;

	tmp = NULL;
	if (src == NULL || sep == NULL)
		return (NULL);
	tmp = ft_strjoin(sep, src);
	if (tmp == NULL)
		return (NULL);
	ft_striteri(tmp, replace_spaces);
	ret = ft_realloc(dst, tmp);
	if (ret == dst || ret == NULL)
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	return (ret);
}

int validate_args(int argc, char **argv, t_llist **stack_a)
{
	int n_numbers;
	int *ret;
	char **args_str;
	t_bst *tree;
	t_bst *child_tree;
	int i;
	t_llist *new_node;

	i = 0;
	tree = NULL;
	args_str = parse_args(argc, argv, &n_numbers);
	if (args_str == NULL)
		return (ft_clear_split(args_str), -1);
	while (i < n_numbers)
	{
		ret = validate_number(args_str[i]);
		if (ret == NULL)
			return clear(&tree, stack_a, NULL, args_str);
		child_tree = ft_bstnew((void *)ret);
		if (child_tree == NULL)
			return clear(&tree, stack_a, NULL, args_str);
		if (ft_bstinsert(&tree, child_tree, compare) != 0)
			return clear(&tree, stack_a, NULL, args_str);
		new_node = ft_llst_new((void *)ret);
		if (new_node == NULL)
			return clear(&tree, stack_a, NULL, args_str);
		ft_llst_push_bot(stack_a, new_node);
		i++;
	}
	ft_clear_split(args_str);
	ft_bstprint(&tree, printer);
	bst_order(&tree);
	ft_bstprint(&tree, printer);
	ft_bstclear(&tree, NULL);
	return 0;
}
int compare(void *n1, void *n2)
{
	int num1;
	int num2;

	num1 = *((int *)n1);
	num2 = *((int *)n2);
	// ft_printf("%d -- %d\n", num1, num2);
	return (num1 - num2);
}

int clear(t_bst **tree, t_llist **stack_a, t_llist **stack_b, char **split)
{
	// int	i;

	// i = 0;
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

int *validate_number(char *str)
{
	// long	tmp;
	ssize_t len;
	int *ret;
	long tmp;

	len = ft_strlen(str);
	if (len > 11)
		return NULL;

	tmp = ft_atol(str);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (NULL);
	ret = malloc(sizeof(int));
	if (ret == NULL)
		return (NULL);
	*ret = ft_atoi(str);
	return (ret);
}

void replace_spaces(unsigned int c, char *dir)
{
	c = 0;
	if (ft_isspace(*dir))
		*dir = ' ';
	c = c;
}

char **parse_args(int argc, char **argv, int *n_numbers)
{
	char *tmp;
	char **ret;
	int i;

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

void printer(void *p)
{
	int *num;

	num = (int *)p;
	ft_printf("%d", *num);
}

void ft_clear_split(char **split)
{
	int i;

	i = 0;
	if (split == NULL)
		return;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}
