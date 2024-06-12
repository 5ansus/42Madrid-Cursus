/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:08:04 by sanferna          #+#    #+#             */
/*   Updated: 2024/06/12 12:40:06 by sanferna         ###   ########.fr       */
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

	i = 0;
	args_str = parse_args(argc, argv, &n_numbers);
	if (args_str == NULL)
		return -1;
	while (i < n_numbers)
	{
		ret = validate_number(args_str[i]);
		// ft_printf("Numero malloqueado %d\n", *ret);
		if (ret == NULL)
			return clear(tree, list, NULL, args_str);
		new = ft_bstnew((void *)ret);
		// ft_printf("%d\n", ft_bstinsert(tree, new, compare));
		if (ft_bstinsert(tree, new, compare) != 0)
			return clear(tree, list, &new, args_str);

		// ft_bstprint(tree, printer);
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
		ft_lstclear(list, free);
	if (numbers != NULL)
		ft_clear_split(numbers);
	return (-1);
}

int *validate_number(char *str)
{
	// long	tmp;
	ssize_t len;
	int *ret;

	len = ft_strlen(str);
	printf("Min int %d -- %ld\n", INT_MIN, (long) INT_MIN);
	// int tmpi = -1;
	// tmpi >>= 2;
	// printf("Valor de tmpi %d\n", tmpi);
	int bucle = INT_MIN;
	bucle = bucle - 1;
	long bucle3 = bucle;
	char str2[33];
	str2[32] = 0;
	printf("Valor de bucle %d\n", bucle);
	for (int i = 31; i >= 0; i--)
	{
		str2[i] = (bucle & 1) + '0';
		bucle >>= 1;
	}
	printf("Valor de str2 %s\n", str2);
	char str3[65];
	str3[64] = 0;
	printf("Valor de bucle3 %ld\n", bucle3);
	for (int i = 63; i >= 0; i--)
	{
		str3[i] = (bucle3 & 1) + '0';
		bucle3 >>= 1;
	}
	printf("Valor de str3 %s\n", str3);
	// long tmp = (long) INT_MIN;
	// tmp >>= 33;
	// printf("Valor de tmp %ld\n", tmp);
	// tmp <<= 1;
	// printf("Valor de tmp %ld\n", tmp);
	if (len > 11)
		return NULL;
	// Comprobar que si tiene 10 no sea mayor que max int 
	// Comprobar que si es 11 no sea menor que min int
	ret = malloc(sizeof(int));
	if (ret == NULL)
		return (NULL);
	*ret = ft_atoi(str);
	// ft_printf("Atoi de %s -- da %d y guardo %d\n", str, ft_atoi(str), *ret);
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

	i = 1;
	tmp = NULL;
	while (i < argc)
	{
		tmp = ft_concatealloc(tmp, argv[i], " ");
		if (tmp == NULL)
			return NULL;
		i++;
	}
	ret = ft_split(tmp, ' ');
	// for (int j = 0; ret[j] != NULL; j++)
	// {
	// 	ft_printf("%s\n", ret[j]);
	// }
	free(tmp);
	i = 0;
	while (ret[i] != NULL)
		i++;
	*n_numbers = i;
	return (ret);
}
void printer(void *p)
{
	int *num;

	num = (int *)p;
	ft_printf("%d\n", *num);
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
