/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:52:47 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/24 02:06:56 by antdelga         ###   ########.fr       */
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
	ft_printf("%d\n", len_stack(stack_a, argc - 1));
	bits = num_bits(len_stack(stack_a, argc - 1) - 1);
	ft_printf("Num bits: %d\n", bits);
	/* Ploteamos el stack en numero y en bits */
	plot_both_stacks(stack_a, stack_b, (argc - 1));
	//print_stacks_by_bits(stack_a, stack_b, argc - 1, bits);
	
	// /* Play y representamos el resultado final y el numero de instrucciones */
	// ft_printf("\nNumero de instrucciones %d\n", ft_game(stack_a, stack_b, bits, argc));
	// plot_both_stacks(stack_a, stack_b, (argc - 1));
	return (0);
}

/* Testeamos que las instrucciones funcionen bien
	test_instructions(stack_a, stack_b, argc); */
