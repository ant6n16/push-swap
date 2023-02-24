/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:58:41 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/24 01:57:18 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_game(int *stack_a, int *stack_b, int bits, int argc)
{
	int	i_bit;
	int	inst;

	inst = 0;
	i_bit = -1;
	while (++i_bit < bits)
	{
		inst += work_in_a(stack_a, stack_b, i_bit, argc);
		inst += return_to_a(stack_a, stack_b, argc);
	}
	return (inst);
}

int	work_in_a(int *stack_a, int *stack_b, int in_bit, int argc)
{
	int	index;
	int	len_a;
	int	len_b;
	int	size_orig;
	int cont;

	index = -1;
	len_a = len_stack(stack_a, (argc - 1));
	len_b = len_stack(stack_b, (argc - 1));
	size_orig = len_a;
	cont = 0;
	while (++index < size_orig)
	{
		if ((stack_a[0] >> in_bit & 1) == 0)
		{
			//ft_printf("Ejecuto pb sobre el numero: %d\n", stack_a[0]);
			pb(stack_a, stack_b, len_a, len_b);
			ft_printf("pb\n");
			cont++;
			//print_stacks_by_bits(stack_a, stack_b, (argc - 1), bits);
			//plot_both_stacks(stack_a, stack_b, (argc - 1));
		}
		else
		{
			//ft_printf("Ejecuto ra sobre el numero: %d\n", stack_a[0]);
			ra(stack_a, len_a);
			ft_printf("ra\n");
			cont++;
			//print_stacks_by_bits(stack_a, stack_b, (argc - 1), bits);
			//plot_both_stacks(stack_a, stack_b, (argc - 1));
		}
		len_a = len_stack(stack_a, (argc - 1));
		len_b = len_stack(stack_b, (argc - 1));
	}
	return (cont);
}

int	return_to_a(int *stack_a, int *stack_b, int argc)
{
	int	index;
	int	len_a;
	int	len_b;
	int	size_orig;
	int	cont;

	index = -1;
	len_a = len_stack(stack_a, (argc - 1));
	len_b = len_stack(stack_b, (argc - 1));
	size_orig = len_b;
	cont = 0;
	while (++index < size_orig)
	{
		//ft_printf("Ejecuto pa sobre el numero: %d\n", stack_b[0]);
		pa(stack_a, stack_b, len_a, len_b);
		ft_printf("pa\n");
		cont++;
		//print_stacks_by_bits(stack_a, stack_b, (argc - 1), bits);			
		len_a = len_stack(stack_a, (argc - 1));
		len_b = len_stack(stack_b, (argc - 1));
	}
	return (cont);
}
