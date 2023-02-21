/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rot_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:38:47 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/21 20:40:54 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ra(int *stack_a, int len)
{
	int	aux1;
	int	aux2;
	int	ini;
	int tam;

	if (len < 2)
		return ;
	tam = --len;
	ini = stack_a[0];
	aux1 = stack_a[len];
	while(--len >= 0)
	{
		aux2 = stack_a[len];
		stack_a[len] = aux1;
		aux1 = aux2;
	}
	stack_a[tam] = ini;
}

void	rr(int *stack_a, int *stack_b, int len_a, int len_b)
{
	if (len_a < 2 || len_b < 2)
		return ;
	ra(stack_a, len_a);
	rb(stack_b, len_b);
}

void	rra(int *stack_a, int len)
{
	int	aux1;
	int	aux2;
	int	ini;
	int	index;

	if (len < 2)
		return ;
	ini = stack_a[--len];
	aux1 = stack_a[0];
	index = 1;
	while(index <= len)
	{
		aux2 = stack_a[index];
		stack_a[index] = aux1;
		aux1 = aux2;
		index++;
	}
	stack_a[0] = ini;
}
