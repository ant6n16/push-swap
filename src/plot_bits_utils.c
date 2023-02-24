/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot_bits_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:46:05 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/24 20:05:21 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_single_last(int *array, int len)
{
	int	index;

	index = 0;
	ft_printf("              ");
	while (index < len)
	{
		ft_printf("%d", array[index]);
		index++;
	}
	ft_printf("\n");
}

void	print_single_one(int *array, int len)
{
	int	index;

	index = 0;
	ft_printf("   ");
	while (index < len)
	{
		ft_printf("%d", array[index]);
		index++;
	}
	ft_printf("           ");
	ft_printf("\n");
}

void	print_both(int *array1, int *array2, int len)
{
	int	index;

	index = 0;
	ft_printf("   ");
	while (index < len)
	{
		ft_printf("%d", array1[index]);
		index++;
	}
	ft_printf("          ");
	index = 0;
	while (index < len)
	{
		ft_printf("%d", array2[index]);
		index++;
	}
	ft_printf("\n");
}

void	print_stacks_by_bits(int *stack_a, int *stack_b, int size, int n_bits)
{
	int	index;
	int	aux_a;
	int	aux_b;
	int	*array_a;
	int	*array_b;

	index = -1;
	ft_printf("\nStack_A     Stack_B\n");
	ft_printf(" ----------------- \n");
	while (++index < size)
	{
		aux_a = stack_a[index];
		aux_b = stack_b[index];
		array_a = print_bits(aux_a, n_bits);
		array_b = print_bits(aux_b, n_bits);
		if (aux_a == -1 && aux_b != -1)
			print_single_last(array_b, n_bits);
		else if (aux_a != -1 && aux_b == -1)
			print_single_one(array_a, n_bits);
		else if (aux_a != -1 && aux_b != -1)
			print_both(array_a, array_b, n_bits);
	}	
	ft_printf(" ----------------- \n\n");
}
