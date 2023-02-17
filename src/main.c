/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:52:47 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/17 21:29:59 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;

	stack_a = (int *) ft_calloc(sizeof(int), (argc - 1));
	if (!stack_a)
		return (0);
	if (process_input(argc, argv, stack_a) == 0)
		return (free(stack_a), 0);
	if (check_repeated_stack_a(stack_a, (argc - 1)) == 0)
		return (free(stack_a), 0);
	stack_b = value_to_index(stack_a, (argc - 1), 2147483648, -2147483649);
	if (!stack_b)
		return (free(stack_a), 0);
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	// PROBANDO LAS INSTRUCCIONES!!!!!

	sa(stack_a, len_stack(stack_a));
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	stack_b[0] = 5;
	stack_b[1] = 6;
	stack_b[2] = 7;
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	sa(stack_a, len_stack(stack_b));
	return (0);
}
