/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanferna <sanferna@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 13:59:19 by sanferna          #+#    #+#             */
/*   Updated: 2024/08/19 18:29:19 by sanferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define STACK_A 0
# define STACK_B !0

# define TOP_A 0xA
# define TOP_B 0xB
# define BOT_A -0xA
# define BOT_B -0xB

# define A 0
# define B 1

# include <limits.h>
# include "./libft/libft.h"

int		validate_args(int argc, char **argv, t_llist *stacks[]);
int		bst_order(t_bst **tree);

void	*ft_concatealloc(void *dst, void *src, char *sep);
void	ft_clear_split(char **split);
int		clear(t_bst **tree, t_llist **stack_a, t_llist **stack_b, char **split);

void	printer(void *p);
int		compare(void *n1, void *n2);
void	standarize_spaces(unsigned int c, char *str);

void	rotate(t_llist **stack_a, t_llist **stack_b, int id_stack);
void	double_rotate(t_llist **stack_a, t_llist **stack_b);
void	reverse_rotate(t_llist **stack_a, t_llist **stack_b, int id_stack);
void	double_reverse_rotate(t_llist **stack_a, t_llist **stack_b);
void	push(t_llist **stack_a, t_llist **stack_b, int id_stack);
void	swap(t_llist **stack_a, t_llist **stack_b, int id_stack);
void	double_swap(t_llist **stack_a, t_llist **stack_b);
#endif
