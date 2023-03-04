/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_improved.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:30:45 by antdelga          #+#    #+#             */
/*   Updated: 2023/03/04 20:43:07 by antdelga         ###   ########.fr       */
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
		//print_stacks_by_bits(stack_a, stack_b, (argc - 1), bits);
		//plot_both_stacks(stack_a, stack_b, (argc - 1));
		work_in_a(stack_a, stack_b, i_bit, argc, bits);
		//print_stacks_by_bits(stack_a, stack_b, (argc - 1), bits);
		//plot_both_stacks(stack_a, stack_b, (argc - 1));
		return_to_a(stack_a, stack_b, i_bit, argc, bits);
	}
}

int	find_way(int *stack, int len, int in_bit)
{
	int	index;
	int	index2;

	index = -1;
	while (++index < len)
	{
		if ((stack[index] >> in_bit & 1) == 0)
			break ;
	}
	index2 = len;
	while(--index2 >= 0)
	{
		if ((stack[index2] >> in_bit & 1) == 0)
			break ;
	}
	ft_printf("index1: %d\n", index);
	ft_printf("index2: %d\n", len - 1 - index2);
	if (index > (len - 1 - index2))
		return (-1);
	else
		return (1);
}

void	work_in_a(int *stack_a, int *stack_b, int in_bit, int argc, int bits)
{
	int	index;
	int	size_orig;
	int	way;

	index = -1;
	(void) bits;
	size_orig = len_stack(stack_a, (argc - 1));
	while (++index < size_orig)
	{
		if (game_completed(stack_a, len_stack(stack_a, (argc - 1)), 0) == 1)
			return ;
		if ((stack_a[0] >> in_bit & 1) == 0)
		{
			pb(stack_a, stack_b, argc, 1);
			//print_stacks_by_bits(stack_a, stack_b, (argc - 1), bits);
			//plot_both_stacks(stack_a, stack_b, (argc - 1));
		}
		else
		{
			way = find_way(stack_a, len_stack(stack_a, (argc - 1)), in_bit);
			if (way == 1)
				ra(stack_a, len_stack(stack_a, (argc - 1)), 1);
			else if (way == -1)
				rra(stack_a, len_stack(stack_a, (argc - 1)), 1);
			ft_printf("%d\n", way);
			// ft_printf("\n");
			// print_stacks_by_bits(stack_a, stack_b, (argc - 1), bits);
			//plot_both_stacks(stack_a, stack_b, (argc - 1));
			// if ((stack_a[size_orig - 1] >> in_bit & 1) == 0)
			// {	
			// 	rra(stack_a, len_stack(stack_a, (argc - 1)), 1);
			// 	ft_printf("\n");
			// 	plot_both_stacks(stack_a, stack_b, (argc - 1));
			// }
			// else
			// {
			// 	ra(stack_a, len_stack(stack_a, (argc - 1)), 1);
			// 	ft_printf("\n");
			// 	plot_both_stacks(stack_a, stack_b, (argc - 1));
			// }
		}
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
		if (game_completed(stack_a, len_stack(stack_a, (argc - 1)), 0) == 1)
			return ;
		if (in_bit < (bits - 1))
		{	
			if (((stack_b[0] >> (in_bit + 1) & 1) == 0))
			{
				rb(stack_b, len_stack(stack_b, (argc - 1)), 1);
				// ft_printf("\n");
				// print_stacks_by_bits(stack_a, stack_b, (argc - 1), bits);
				//plot_both_stacks(stack_a, stack_b, (argc - 1));
			}
			else
			{
				pa(stack_a, stack_b, argc);
				// ft_printf("\n");
				// print_stacks_by_bits(stack_a, stack_b, (argc - 1), bits);
				//plot_both_stacks(stack_a, stack_b, (argc - 1));
			}
		}
		else
		{
			pa(stack_a, stack_b, argc);
			// ft_printf("\n");
			// print_stacks_by_bits(stack_a, stack_b, (argc - 1), bits);
			//plot_both_stacks(stack_a, stack_b, (argc - 1));
		}
	}
}
