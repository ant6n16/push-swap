/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:27:22 by antdelga          #+#    #+#             */
/*   Updated: 2023/03/08 22:59:08 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_repeated_stack_a(int *stack_a, int size)
{
	int	temp;
	int	index;
	int	index2;

	index = -1;
	while (++index < (size - 1))
	{
		temp = stack_a[index];
		index2 = index;
		while (++index2 < size)
		{
			if (temp == stack_a[index2])
				return (0);
		}
	}
	return (1);
}

void	plot_stack(int *stack, int size)
{
	int	index;

	index = 0;
	while (index < size)
		ft_printf("%d\n", stack[index++]);
}

void	plot_both_stacks(int *stack_a, int *stack_b, int size)
{
	int	index;
	int	aux_a;
	int	aux_b;

	index = -1;
	ft_printf("\nStack_A     Stack_B\n");
	ft_printf(" ----------------- \n");
	while (++index < size)
	{
		aux_a = stack_a[index];
		aux_b = stack_b[index];
		if (aux_a == -1 && aux_b != -1)
			ft_printf("              %d\n", stack_b[index]);
		else if (aux_a != -1 && aux_b == -1)
			ft_printf("   %d           \n", stack_a[index]);
		else if (aux_a != -1 && aux_b != -1)
			ft_printf("   %d          %d\n", stack_a[index], stack_b[index]);
	}	
	ft_printf(" ----------------- \n\n");
}

int	len_stack(int *stack, int limit)
{
	int	index;

	index = 0;
	while (stack[index] != -1 && index < limit)
		index++;
	return (index);
}

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}
