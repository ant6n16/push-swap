/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:52:47 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/23 22:10:55 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	bits;

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

	/* Hay que sacar el numero de bits necesario */
	bits = num_bits(len_stack(stack_a, argc - 1) - 1);
	ft_printf("Numero mayor a representar: %s\n", print_bits(len_stack(stack_a, argc - 1) - 1, bits));	
	ft_printf("Num bits: %d\n", bits);

	plot_both_stacks(stack_a, stack_b, (argc - 1));
	//print_stacks_by_bits(stack_a, stack_b, len_stack(stack_a, argc - 1), bits);

	ft_game(stack_a, stack_b, bits, argc);
	// print_stacks_by_bits(stack_a, stack_b, len_stack(stack_a, argc - 1), bits);
	// plot_both_stacks(stack_a, stack_b, (argc - 1));
	
	/* Testeamos que las instrucciones funcionen bien  */
	//test_instructions(stack_a, stack_b, argc);

	return (0);
}
