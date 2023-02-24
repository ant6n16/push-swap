/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bits_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:25:55 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/24 14:00:20 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*print_bits(int octet, int num_bits) /* ESTA NO SE ENTREGA */
{
	int 	bit;
	int		*array;
	int		len;

	array = (int *) ft_calloc(sizeof(int), num_bits);

	len = num_bits - 1;
	while (num_bits--)
	{
		bit = octet >> num_bits & 1;
		array[len - num_bits] = bit;
	}
	return (array);
}

void print_bits_single(int octet, int num_bits)
{
	int	bit;

	while (num_bits--)
	{
		bit = (octet >> num_bits & 1) + '0';
		write(1, &bit, 1);
	}
	write(1, "\n", 1);
}

int	num_bits(int limit)
{
	int	index;
	int	count;

	index = 0;
	count = 0;
	while (index < 32) /* Un entero tiene, como mucho, 32 bits */
	{
		if ((limit >> index & 1) == 1)
			count = index + 1;
		index++;
	}
	return (count);
}
