/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:25:55 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/23 22:29:59 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*print_bits(int octet, int num_bits) /* ESTA NO SE ENTREGA */
{
	unsigned char 	bit;
	char			str[num_bits];
	char			*dir;
	int				len;

	len = num_bits - 1;
	while (num_bits--)
	{
		bit = (octet >> num_bits & 1) + '0';
		str[len - num_bits] = bit;
	}
	dir = str;
	return (dir);
}

int	num_bits(int limit)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < limit)
	{
		if ((limit >> index & 1) == 1)
			count = index + 1;
		index++;
	}
	ft_printf("Numero de bits a comparar: %d\n", count);
	return (count);
}

void	print_stacks_by_bits(int *stack_a, int *stack_b, int size, int n_bits)
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
			ft_printf("              %s\n", print_bits(stack_b[index], n_bits));
		else if (aux_a != -1 && aux_b == -1)
			ft_printf("   %s           \n", print_bits(stack_a[index], n_bits));
		else if (aux_a != -1 && aux_b != -1)
			ft_printf("   %s          %s\n", print_bits(stack_a[index], n_bits), print_bits(stack_b[index], n_bits));
	}	
	ft_printf(" ----------------- \n\n");
}
