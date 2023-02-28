/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_improved.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:30:45 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/28 15:42:08 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	game_completed(int *stack, int len, int offset)
{
	int	index;

	index = -1;
	while(++index < len)
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
		work_in_a(stack_a, stack_b, i_bit, argc);
		return_to_a(stack_a, stack_b, argc);
	}
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
			pb(stack_a, stack_b, len_a, len_b, 1);
			cont++;
		}
		else
		{
			ra(stack_a, len_a, 1);
			cont++;
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
		pa(stack_a, stack_b, len_a, len_b);
		cont++;
		len_a = len_stack(stack_a, (argc - 1));
		len_b = len_stack(stack_b, (argc - 1));
	}
	return (cont);
}
