/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:58:04 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/20 21:41:57 by antdelga         ###   ########.fr       */
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
	sa(stack_b, len);
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

void	ra(int *stack_a, int len)
{
	int	aux1;
	int	aux2;
	int	ini;
	int tam;

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

void	rb(int *stack_b, int len)
{
	ra(stack_b, len);
}

void	rr(int *stack_a, int *stack_b, int lenA, int lenB)
{
	ra(stack_a, lenA);
	rb(stack_b, lenB);
}

void	rra(int *stack_a, int len)
{
	int	aux1;
	int	aux2;
	int	ini;
	int	index;

	ini = stack_a[--len];
	aux1 = stack_a[0];
	index = 1;
	while(index < len)
	{
		aux2 = stack_a[index + 1];
		stack_a[index + 1] = aux1;
		aux1 = aux2;
		index++;
	}
	stack_a[0] = ini;
}

void	rrb(int *stack_b, int len)
{
	rra(stack_b, len);
}

void	rrr(int *stack_a, int *stack_b, int lenA, int lenB)
{
	rra(stack_a, lenA);
	rrb(stack_b, lenB);
}
