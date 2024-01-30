/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 14:52:03 by sanferna          #+#    #+#             */
/*   Updated: 2024/01/30 20:39:29 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#define MAX_LEN_UNSIGNED_INT 10+1
#define MAX_LEN_INT	10+1+1
#include <stdio.h>


char	*conversion(int n, char *base);
char	*conversion_unsigned(unsigned int n, char *base);
char	*conversion_unsigned_hex(void *n, char *base);
void	conversion_unsigned_rec_hex(void *p, char *dest, int *index, char *base);
void	conversion_unsigned_rec(unsigned int n, char *dest, int *index, char *base);
void	conversion_rec(int n, char *dest, int *index, char *base);

ssize_t	print_decimal(int num)
{
	ssize_t	ret;
	char	*str;

	str = conversion(num, "0123456789");
	ret = write(1, str, ft_strlen(str));
	ft_putchar_fd('\n', 1);
	free(str);
	if (ret < 0)
		return (-1);
	return (ret);
}

ssize_t	print_unsigned(unsigned int num)
{
	ssize_t	ret;
	char	*str;

	str = conversion_unsigned(num, "0123456789");
	ret = write(1, str, ft_strlen(str));
	ft_putchar_fd('\n', 1);
	free(str);
	if (ret < 0)
		return (-1);
	return (ret);
}

ssize_t	print_unsigned_hex(void *num)
{
	ssize_t	ret;
	char	*str;

	str = conversion_unsigned_hex(num, "0123456789abcdef");
	ft_putstr_fd("0x", 1);
	ret = write(1, str, ft_strlen(str));
	ft_putchar_fd('\n', 1);
	free(str);
	if (ret < 0)
		return (-1);
	return (ret);
}

ssize_t	print_hex(int num)
{
	ssize_t	ret;
	char	*str;

	str = conversion(num, "0123456789ABCDEF");
	ret = write(1, str, ft_strlen(str));
	ft_putchar_fd('\n', 1);
	free(str);
	if (ret < 0)
		return (-1);
	return (ret);
}

ssize_t	print_hex_minus(int num)
{
	ssize_t	ret;
	char	*str;

	str = conversion(num, "0123456789abcdef");
	ret = write(1, str, ft_strlen(str));
	ft_putchar_fd('\n', 1);
	free(str);
	if (ret < 0)
		return (-1);
	return (ret);
}

char	*conversion(int n, char *base)
{
	char	str[MAX_LEN_INT];
	int		index;
	char	*ret;

	str[0] = '\0';
	index = 0;
	conversion_rec(n, str, &index, base);
	ret = ft_strdup(str);
	return (ret);
}

char	*conversion_unsigned(unsigned int n, char *base)
{
	char	str[MAX_LEN_UNSIGNED_INT];
	int		index;
	char	*ret;

	str[0] = '\0';
	index = 0;
	conversion_unsigned_rec(n, str, &index, base);
	ret = ft_strdup(str);
	return (ret);
}


char	*conversion_unsigned_hex(void *n, char *base)
{
	char	str[14];
	int		index;
	char	*ret;

	str[0] = '\0';
	index = 0;
	conversion_unsigned_rec_hex(n, str, &index, base);
	ret = ft_strdup(str);
	return (ret);
}

void	conversion_rec(int n, char *dest, int *index, char *base)
{
	if (n < 0)
	{
		dest[*index] = '-';
		(*index)++;
		//printf("%s\n", dest);
		if ((n / ft_strlen(base)) != 0)
			conversion_rec(-(n / (int) ft_strlen(base)), dest, index, base);
		dest[*index] = base[-(n % (int) ft_strlen(base))];
		dest[(*index) + 1] = '\0';
		//printf("%s\n", dest);
	}
	else
	{
		//printf("%s\n", dest);
		if ((n / ft_strlen(base)) != 0)
			conversion_rec((n / ft_strlen(base)), dest, index, base);
		dest[*index] = base[n % ft_strlen(base)];
		dest[(*index) + 1] = '\0';
		(*index)++;
	}
}

void	conversion_unsigned_rec(unsigned int n, char *dest, int *index, char *base)
{
	//printf("%s\n", dest);
	if ((n / ft_strlen(base)) != 0)
		conversion_unsigned_rec((n / ft_strlen(base)), dest, index, base);
	dest[*index] = base[n % ft_strlen(base)];
	dest[(*index) + 1] = '\0';
	(*index)++;
}

void	conversion_unsigned_rec_hex(void *p, char *dest, int *index, char *base)
{
	//printf("%s\n", dest);
	if (((unsigned long long) p / ft_strlen(base)) != 0)
		conversion_unsigned_rec_hex((void *)( (unsigned long long) p / ft_strlen(base)), dest, index, base);
	dest[*index] = base[(unsigned long long) p % ft_strlen(base)];
	dest[(*index) + 1] = '\0';
	(*index)++;
}
