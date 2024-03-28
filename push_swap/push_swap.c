/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:08:04 by sanferna          #+#    #+#             */
/*   Updated: 2024/03/28 20:59:55 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_concatealloc(void *dst, void *src, char *sep);
int		compare(void *n1, void *n2);
void	replace_spaces(unsigned int c, char *str);
int	validate_args(int argc, char **argv, t_bst **tree, t_list **list);
int *validate_number(char *str);
int	clear(t_bst **tree, t_list **list, t_bst **extra_tree);
void	leaks(void){
	system("leaks push_swap");
}

int	main(int argc, char **argv)
{
	char *p = NULL;
	atexit(leaks);
	for(int i = 0; i < argc; i++){
		p = ft_concatealloc(p, argv[i], " ");
	}
	char **ret = ft_split(p, ' ');
	int j = 0;
	while(ret[j] != NULL){
		ft_printf("Palabra %d: %s\n", j, ret[j]);
		free(ret[j]);
		j++;
	}
	free(ret);
	ft_printf("%s tiene %d palabras\n", p, j);
	free(p);
}

void	*ft_concatealloc(void *dst, void *src, char *sep)
{
	char	*tmp;
	char	*ret;

	tmp = NULL;
	tmp = ft_strjoin(sep, src);
	if(tmp == NULL)
		return (NULL);
	ft_striteri(tmp, replace_spaces);
	ret = ft_realloc(dst, tmp);
	free(tmp);
	return (ret);
}

int	validate_args(int argc, char **argv, t_bst **tree, t_list **list)
{
	int	i;
	int	*ret;
	t_bst	*new;

	i = 2;
	while (i < argc)
	{
		ret = validate_number(argv[i]);
		if (ret == NULL)
			return clear(tree, list, NULL);
		new = ft_bstnew(ret);
		if (ft_bstinsert(tree, new, compare))
			return clear(tree, list, &new);
	}
	return 0;
}
int	compare(void *n1, void *n2)
{
	int	num1;
	int	num2;

	num1 = *((int*) n1);
	num2 = *((int*) n2);
	//ft_printf("%d -- %d\n", num1, num2);
	return (num1 - num2);
}

int	clear(t_bst **tree, t_list **list, t_bst **extra_tree)
{
	ft_bstclear(tree, free);
	ft_bstclear(extra_tree, free);
	ft_lstclear(list, free);
	return (-1);
}
int *validate_number(char *str)
{
	//long	tmp;
	int	len;

	len = ft_strlen(str);
	if(len > 11)
		return NULL;
	///ft_atoi();
	return(NULL);
}

void replace_spaces(unsigned int c, char *dir)
{
	c = 0;
	if (ft_isspace(*dir))
		*dir = ' ';
}
