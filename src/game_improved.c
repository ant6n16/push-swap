/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_improved.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:30:45 by antdelga          #+#    #+#             */
/*   Updated: 2023/03/01 02:14:11 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	game_completed(int *stack, int len, int offset)
{
	int	index;

	index = -1;
	while (++index < len)
	{
		if (stack[index] != (index + offset))
			return (0);
	}
	return (1);
}

void	ft_game(int *stack_a, int *stack_b, int bits, int argc)
{
	int	i_bit;

	i_bit = -1;
	while (++i_bit < bits)
	{
		if (game_completed(stack_a, len_stack(stack_a, (argc - 1)), 0) == 1)
			return ;
		print_stacks_by_bits(stack_a, stack_b, (argc - 1), bits);
		plot_both_stacks(stack_a, stack_b, (argc - 1));
		work_in_a(stack_a, stack_b, i_bit, argc);
		print_stacks_by_bits(stack_a, stack_b, (argc - 1), bits);
		plot_both_stacks(stack_a, stack_b, (argc - 1));
		return_to_a(stack_a, stack_b, i_bit, argc, bits);
	}
}

void	work_in_a(int *stack_a, int *stack_b, int in_bit, int argc)
{
	int	index;
	int	size_orig;

	index = -1;
	size_orig = len_stack(stack_a, (argc - 1));
	while (++index < size_orig)
	{
		if ((stack_a[0] >> in_bit & 1) == 0)
			pb(stack_a, stack_b, argc, 1);
		else
			ra(stack_a, len_stack(stack_a, (argc - 1)), 1);
	}
}

void	return_to_a(int *stack_a, int *stack_b, int in_bit, int argc, int bits)
{
	int	index;
	int	size_orig;

	index = -1;
	size_orig = len_stack(stack_b, (argc - 1));
	while (++index < size_orig)
	{
		/* VAMOS A BUSCAR DONDE ESTAN LOS 1 DEL BIT SIGUIENTE EN EL STACK B.
		SI LOS UNOS ESTÁN MAS CERCA HACIENDO RA O RRA. PASAMOS LOS UNOS AL OTRO STACK */
		if (in_bit < (bits - 1))
		{	
			if (((stack_b[0] >> (in_bit + 1) & 1) == 0))
				rb(stack_b, len_stack(stack_b, (argc - 1)), 1);
			else
				pa(stack_a, stack_b, argc);
		}
		else
			pa(stack_a, stack_b, argc);
	}
}
