/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:58:41 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/25 01:32:05 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_game_basic(int *stack_a, int argc)
{
	int	len_a;

	len_a = len_stack(stack_a, (argc - 1));
	if (game_completed(stack_a, len_a) == 1)
			return ;
	if (stack_a[0] == 0)
	{
		ra(stack_a, len_a);
		ft_printf("ra\n");
		sa(stack_a, len_a);
		ft_printf("sa\n");
		return ;
	}
	if (stack_a[0] == 1 && stack_a[2] == 0)
	{
		ra(stack_a, len_a);
		ft_printf("ra\n");
		return ;
	}
	if (stack_a[0] == 1 && stack_a[2] == 2)
	{
		sa(stack_a, len_a);
		ft_printf("sa\n");
		return ;
	}
	if (stack_a[0] == 2 && stack_a[2] == 0)
	{
		sa(stack_a, len_a);
		ft_printf("sa\n");
		ra(stack_a, len_a);
		ft_printf("sa\n");
		return ;
	}
	if (stack_a[0] == 2 && stack_a[2] == 1)
	{
		ra(stack_a, len_a);
		ft_printf("ra\n");
		ra(stack_a, len_a);
		ft_printf("sa\n");
		return ;
	}
}

void	ft_game(int *stack_a, int *stack_b, int bits, int argc)
{
	int	i_bit;

	i_bit = -1;
	while (++i_bit < bits)
	{
		if (game_completed(stack_a, len_stack(stack_a, (argc - 1))) == 1)
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
			pb(stack_a, stack_b, len_a, len_b);
			ft_printf("pb\n");
			cont++;
		}
		else
		{
			ra(stack_a, len_a);
			ft_printf("ra\n");
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
		ft_printf("pa\n");
		cont++;
		len_a = len_stack(stack_a, (argc - 1));
		len_b = len_stack(stack_b, (argc - 1));
	}
	return (cont);
}
