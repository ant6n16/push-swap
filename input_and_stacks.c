/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_and_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:03:53 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/13 19:14:15 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_input(int argc, char **argv, int *stack_a)
{
	int			index;
	long int	aux;

	if (argc < 2)
		return (0);
	index = 0;
	while (++index < argc)
	{
		aux = ft_atoi_long(argv[index]);
		if ((aux > 2147483647) || (aux < -2147483648))
			return (0);
		stack_a[index - 1] = ft_atoi(argv[index]);
	}
	return (1);
}

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

int	*create_stack_b_filled(int size)
{
	int	*stack_b;
	int	index;

	stack_b = (int *) ft_calloc(sizeof(int), size);
	if (!stack_b)
		return (NULL);
	index = -1;
	while (++index < size)
		stack_b[index] = -1;
	return (stack_b);
}

int	*value_to_index(int *stack_a, int size, int min_aux)
{
	int	index;
	int	index2;
	int	*aux;

	aux = (int *) ft_calloc(sizeof(int), size);
	if (!aux)
		return (NULL);
	index = -1;
	index2 = -1;
	while (++index2 < size)
	{
		while (++index < size)
		{
			if (stack_a[index] < min_aux)
			{
				aux[index] = index2;
				min_aux = aux[index];
			}
		}
		index = -1;
	}
	return (create_stack_b_filled(size));
}

