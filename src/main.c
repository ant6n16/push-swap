/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:52:47 by antdelga          #+#    #+#             */
/*   Updated: 2023/03/01 02:00:39 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	bits;

	if (argc < 2)
		return (0);
	stack_a = (int *) ft_calloc(sizeof(int), (argc - 1));
	if (!stack_a)
		return (0);
	if (process_input(argc, argv, stack_a) == 0)
		return (ft_printf("Error\n"), free(stack_a), 0);
	if (check_repeated_stack_a(stack_a, (argc - 1)) == 0)
		return (ft_printf("Error\n"), free(stack_a), 0);
	stack_b = value_to_index(stack_a, (argc - 1), 2147483648, -2147483649);
	if (!stack_b)
		return (free(stack_a), 0);
	bits = num_bits(len_stack(stack_a, argc - 1) - 1);
	if (len_stack(stack_a, argc - 1) <= 5)
		ft_game_basic(stack_a, stack_b, argc);
	else
		ft_game(stack_a, stack_b, bits, argc);
	plot_both_stacks(stack_a, stack_b, (argc - 1));
	// print_stacks_by_bits(stack_a, stack_b, (argc - 1), bits);
	return (free(stack_a), free(stack_b), 0);
}

/* 
	TO DO:
	METER STACKS Y TAMAÑOS EN UN STRUCT PARA TENER MENOS PARAMETROS EN FUNCIONES
*/
