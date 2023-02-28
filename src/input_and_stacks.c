/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_and_stacks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:03:53 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/28 16:18:52 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	process_input(int argc, char **argv, int *stack_a)
{
	int			index;
	long int	aux;

	index = 0;
	while (++index < argc)
	{
		if (check_numeric_string(argv[index]) == 0)
			return (0);
		aux = ft_atoi_long(argv[index]);
		if ((aux > 2147483647) || (aux < -2147483648))
			return (0);
		stack_a[index - 1] = ft_atoi(argv[index]);
	}
	return (1);
}

int	check_numeric_string(char *str)
{
	int	index;

	index = 0;
	if (str[index] == '-')
		index++;
	while (str[index] != '\0')
	{
		if (str[index] < '0' || str[index] > '9')
			return (0);
		index++;
	}
	return (1);
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

int	*swap_table(int *stack_a, int *aux, int size)
{
	int	index;

	index = -1;
	while (++index < size)
		stack_a[index] = aux[index];
	free(aux);
	return (stack_a);
}

int	*value_to_index(int *stack_a, int size, long max_aux, long min_aux)
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
			if (stack_a[index] < max_aux && stack_a[index] > min_aux)
			{
				aux[index] = index2;
				max_aux = stack_a[index];
			}
		}
		min_aux = max_aux;
		max_aux = 2147483648;
		index = -1;
	}
	stack_a = swap_table(stack_a, aux, size);
	return (create_stack_b_filled(size));
}
