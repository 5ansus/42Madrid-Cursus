/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:52:03 by sanferna          #+#    #+#             */
/*   Updated: 2024/02/18 17:29:24 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	cnv_rec(int num, char *dest, int *index, char *base);
void	cnv_rec_un(unsigned long long num, char *dest, int *index, char *base);
void	cnv_rec_uint(unsigned int num, char *dest, int *index, char *base);

void	cnv(t_arg_types num, char mode, char **ret, int *count_zeros)
{
	char	str[22];
	int		index;
	char	*p;

	str[0] = '\0';
	index = 0;
	if (mode == TO_INT)
		cnv_rec(num.i, str, &index, "0123456789");
	else if (mode == TO_UNS)
		cnv_rec_un(num.u, str, &index, "0123456789");
	else if (mode == TO_HEX_MIN)
		cnv_rec_uint(num.i, str, &index, "0123456789abcdef");
	else if (mode == TO_HEX_CAPS)
		cnv_rec_uint(num.i, str, &index, "0123456789ABCDEF");
	else if (mode == TO_POINTER)
	{
		ft_memmove(str, "0x", 2);
		index = 0;
		p = &(str[2]);
		cnv_rec_un(num.ul, p, &index, "0123456789abcdef");
	}
	if (realloc_printf(ret, str, ft_strlen(str), count_zeros) == GNL_ERR)
		*ret = NULL;
}

void	cnv_rec(int num, char *dest, int *index, char *base)
{
	if (num < 0)
	{
		dest[*index] = '-';
		(*index)++;
		if ((num / (int) ft_strlen(base)) != 0)
			cnv_rec(-(num / (int) ft_strlen(base)), dest, index, base);
		dest[*index] = base[-(num % (int) ft_strlen(base))];
		dest[(*index) + 1] = '\0';
	}
	else
	{
		if ((num / ft_strlen(base)) != 0)
			cnv_rec((num / ft_strlen(base)), dest, index, base);
		dest[*index] = base[num % ft_strlen(base)];
		dest[(*index) + 1] = '\0';
		(*index)++;
	}
}

void	cnv_rec_un(unsigned long long num, char *dest, int *index, char *base)
{
	if ((num / ft_strlen(base)) != 0)
		cnv_rec_un((num / ft_strlen(base)), dest, index, base);
	dest[*index] = base[num % ft_strlen(base)];
	dest[(*index) + 1] = '\0';
	(*index)++;
}

void	cnv_rec_uint(unsigned int num, char *dest, int *index, char *base)
{
	if ((num / ft_strlen(base)) != 0)
		cnv_rec_un((num / ft_strlen(base)), dest, index, base);
	dest[*index] = base[num % ft_strlen(base)];
	dest[(*index) + 1] = '\0';
	(*index)++;
}
