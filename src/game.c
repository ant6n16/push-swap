/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:58:41 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/23 22:24:48 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_game(int *stack_a, int *stack_b, int bits, int argc)
{
	int	i_bit;

	i_bit = 0;
	(void) bits;
	work_in_a(stack_a, stack_b, i_bit, argc);

	// i_bit = -1;
	// // Nos situamos en uno de los bits
	// while (++i_bit < bits)
	// {
	// 	// Primero mueve del stackA
	// 	work_in_a(stack_a, stack_b, i_bit, argc);

	// 	// Luego rellena el stackA con lo que movió al B
	// 	//return_to_a(stack_a, stack_b, i_bit, argc);
	// }
}

void	work_in_a(int *stack_a, int *stack_b, int in_bit, int argc)
{
	int	index;
	int	len_a;
	int	len_b;
	int	bits;
	int	size_orig;

	index = -1;
	len_a = len_stack(stack_a, (argc - 1));
	len_b = len_stack(stack_b, (argc - 1));
	size_orig = len_a;
	bits = 3;
	while (++index < size_orig)
	{
		if ((stack_a[0] >> in_bit & 1) == 1)
		{
			ft_printf("Ejecuto pb sobre el numero: %d\n", stack_a[0]);
			pb(stack_a, stack_b, len_a, len_b);
			//print_stacks_by_bits(stack_a, stack_b, len_stack(stack_a, argc - 1), bits);
			print_stacks_by_bits(stack_a, stack_b, (argc - 1), bits);
			plot_both_stacks(stack_a, stack_b, (argc - 1));
		}
			
		else
		{
			ft_printf("Ejecuto ra sobre el numero: %d\n", stack_a[0]);
			ra(stack_a, len_a);
			//print_stacks_by_bits(stack_a, stack_b, len_stack(stack_a, argc - 1), bits);
			print_stacks_by_bits(stack_a, stack_b, (argc - 1), bits);
			plot_both_stacks(stack_a, stack_b, (argc - 1));
		}
		len_a = len_stack(stack_a, (argc - 1));
		len_b = len_stack(stack_b, (argc - 1));
	}
}

// void	return_to_a(int *stack_a, int *stack_b)
// {

	
// }
