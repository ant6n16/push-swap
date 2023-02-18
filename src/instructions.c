/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:58:04 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/18 20:40:25 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(int *stack_a, int len)
{
	int	aux;

	if (len < 2)
		return ;
	aux = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = aux;
}

void	sb(int *stack_b, int len)
{
	int	aux;

	if (len < 2)
		return ;
	aux = stack_b[0];
	stack_b[0] = stack_b[1];
	stack_b[1] = aux;
}

void	ss(int *stack_a, int *stack_b, int lenA, int lenB)
{
	sa(stack_a, lenA);
	sb(stack_b, lenB);
}

void	pb(int *stack_a, int *stack_b, int lenA, int lenB)
{
	int	index;
	
	if (lenA == 0)
		return ;
	while (lenB > 0)
	{
		stack_b[lenB] = stack_b[lenB - 1];
		lenB--;
	}
	stack_b[0] = stack_a[0];
	index = 0;
	while (index < (lenA - 1))
	{
		stack_a[index] = stack_a[index + 1];
		index++;
	}
	stack_a[index] = -1;
}

void	pa(int *stack_a, int *stack_b, int lenA, int lenB)
{
	pb(stack_b, stack_a, lenB, lenA);
}
