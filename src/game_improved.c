/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_improved.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:30:45 by antdelga          #+#    #+#             */
/*   Updated: 2023/03/08 20:35:58 by antdelga         ###   ########.fr       */
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

int	stack_sorted(int *stack, int len)
{
	int	index;
	int	sorted;

	sorted = 1;
	index = -1;
	while (++index < (len - 1))
	{
		if (stack[index + 1] - stack[index] != 1)
		{
			sorted = 0;
			break ;
		}
	}
	return (sorted);
}

void	ft_game(int *stack_a, int *stack_b, int bits, int argc)
{
	int	i_bit;
	int	*bits_info;

	bits_info = (int *) ft_calloc(sizeof(int), 2);
	if (!bits_info)
		return ;
	i_bit = -1;
	bits_info[1] = bits;
	while (++i_bit < bits)
	{
		if (game_completed(stack_a, len_stack(stack_a, (argc - 1)), 0) == 1)
			return ;
		if (stack_sorted(stack_a, len_stack(stack_a, (argc - 1))) == 0)
			work_in_a(stack_a, stack_b, i_bit, argc);
		bits_info[0] = i_bit;
		return_to_a(stack_a, stack_b, argc, bits_info);
	}
	free(bits_info);
}

void	work_in_a(int *stack_a, int *stack_b, int in_bit, int argc)
{
	int	index;
	int	size_orig;

	index = -1;
	size_orig = len_stack(stack_a, (argc - 1));
	while (++index < size_orig)
	{
		if (game_completed(stack_a, len_stack(stack_a, (argc - 1)), 0) == 1)
			return ;
		if (stack_sorted(stack_a, len_stack(stack_a, (argc - 1))) == 1)
			return ;
		if ((stack_a[0] >> in_bit & 1) == 0)
			pb(stack_a, stack_b, argc, 1);
		else
			ra(stack_a, len_stack(stack_a, (argc - 1)), 1);
	}
}

void	return_to_a(int *stack_a, int *stack_b, int argc, int *bits_info)
{
	int	index;
	int	size_orig;
	int	bits;
	int	in_bit;

	index = -1;
	size_orig = len_stack(stack_b, (argc - 1));
	bits = bits_info[1];
	in_bit = bits_info[0];
	while (++index < size_orig)
	{
		if (game_completed(stack_a, len_stack(stack_a, (argc - 1)), 0) == 1)
			return ;
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
