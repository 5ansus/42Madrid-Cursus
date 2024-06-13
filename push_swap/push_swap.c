/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:08:04 by sanferna          #+#    #+#             */
/*   Updated: 2024/06/13 11:27:07 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void *ft_concatealloc(void *dst, void *src, char *sep);
int compare(void *n1, void *n2);
void replace_spaces(unsigned int c, char *str);
int validate_args(int argc, char **argv, t_bst **tree, t_list **list);
int *validate_number(char *str);
int clear(t_bst **tree, t_list **list, t_bst **extra_tree, char **numbers);
char **parse_args(int argc, char **argv, int *n_numbers);
void printer(void *p);
void ft_clear_split(char **split);

int main(int argc, char **argv)
{
	t_bst *tree;
	t_list *lista;

	if (argc < 2)
	{
		ft_printf("Args insuficientes\n");
		return 1;
	}
	tree = NULL;
	lista = NULL;
	validate_args(argc, argv, &tree, &lista);
	ft_bstprint(&tree, printer);
	bst_order(&tree);
	ft_bstprint(&tree, printer);
	ft_lstprint(&lista, printer);
	clear(&tree, &lista, NULL, NULL);
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

int validate_args(int argc, char **argv, t_bst **tree, t_list **list)
{
	int n_numbers;
	int *ret;
	char **args_str;
	t_bst *new;
	int i;
	t_list *new_list;

	i = 0;
	args_str = parse_args(argc, argv, &n_numbers);
	if (args_str == NULL)
		return (ft_clear_split(args_str), -1);
	while (i < n_numbers)
	{
		ret = validate_number(args_str[i]);
		if (ret == NULL)
			return clear(tree, list, NULL, args_str);
		new = ft_bstnew((void *)ret);
		if (ft_bstinsert(tree, new, compare) != 0)
			return clear(tree, list, &new, args_str);
		new_list = ft_lstnew((void *)ret);
		ft_lstadd_back(list, new_list);
		i++;
	}
	ft_clear_split(args_str); // podría ir en el main o no. Mirar si hay que tocar la función clear.
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

int clear(t_bst **tree, t_list **list, t_bst **extra_tree, char **numbers)
{
	// int	i;

	// i = 0;
	if (tree != NULL)
		ft_bstclear(tree, free);
	if (extra_tree != NULL)
		ft_bstclear(extra_tree, free);
	if (list != NULL)
		ft_lstclear(list, NULL);
	if (numbers != NULL)
		ft_clear_split(numbers);
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

char	**parse_args(int argc, char **argv, int *n_numbers)
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
