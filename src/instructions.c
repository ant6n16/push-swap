/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:58:04 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/28 00:34:31 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(int *stack_a, int len, int verbose)
{
	int	aux;

	if (len < 2)
		return ;
	aux = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = aux;
	if (verbose == 1)
		ft_printf("sa\n");
}

void	sb(int *stack_b, int len, int verbose)
{
	sa(stack_b, len, 0);
	if (verbose == 1)
		ft_printf("sb\n");
}

void	ss(int *stack_a, int *stack_b, int len_a, int len_b)
{
	if (len_a < 2 || len_b < 2)
		return ;
	sa(stack_a, len_a, 0);
	sb(stack_b, len_b, 0);
	ft_printf("ss\n");
}

void	pb(int *stack_a, int *stack_b, int len_a, int len_b, int verbose)
{
	int	index;
	
	if (len_a == 0)
		return ;
	while (len_b > 0)
	{
		stack_b[len_b] = stack_b[len_b - 1];
		len_b--;
	}
	stack_b[0] = stack_a[0];
	index = 0;
	while (index < (len_a - 1))
	{
		stack_a[index] = stack_a[index + 1];
		index++;
	}
	stack_a[index] = -1;
	if (verbose == 1)
		ft_printf("pb\n");
}

void	pa(int *stack_a, int *stack_b, int len_a, int len_b)
{
	pb(stack_b, stack_a, len_b, len_a, 0);
	ft_printf("pa\n");
}
