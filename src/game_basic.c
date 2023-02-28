/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:58:41 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/28 01:27:08 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_game_basic(int *stack_a, int *stack_b, int argc)
{
	int	len_a;

	len_a = len_stack(stack_a, (argc - 1));
	if (game_completed(stack_a, len_a) == 1)
			return ;
	if (len_a == 2)
		sa(stack_a, len_a, 1);
	else if (len_a == 3)
		ft_sort_3(stack_a, argc);
	else if (len_a == 4)
		ft_sort_4(stack_a, stack_b, argc);
	else if (len_a == 5)
		ft_sort_5(stack_a, stack_b, argc);
}

void	ft_sort_3(int *stack_a, int argc)
{
	int	len_a;

	len_a = len_stack(stack_a, (argc - 1));
	if (game_completed(stack_a, len_a) == 1)
			return ;
	if (stack_a[0] == 0)
	{
		rra(stack_a, len_a, 1);
		sa(stack_a, len_a, 1);
	}
	else if (stack_a[0] == 1 && stack_a[2] == 0)
		rra(stack_a, len_a, 1);
	else if (stack_a[0] == 1 && stack_a[2] == 2)
		sa(stack_a, len_a, 1);
	else if (stack_a[0] == 2 && stack_a[2] == 0)
	{
		ra(stack_a, len_a, 1);
		sa(stack_a, len_a, 1);
	}
	else
		ra(stack_a, len_a, 1);
}

void	ft_sort_4(int *stack_a, int *stack_b, int argc)
{
	int	index;
	int	aux_min;

	index = -1;
	while (++index < 4)
	{
		if (stack_a[index] == 0)
			aux_min = index;
	}
	ft_printf("%d\n", aux_min);
	if (aux_min == 1)
		ra(stack_a, 4, 1);
	else if (aux_min == 2)
	{
		ra(stack_a, 4, 1);
		ra(stack_a, 4, 1);
	}
	else if (aux_min == 3)
		rra(stack_a, 4, 1);
	if (game_completed(stack_a, 4) == 1)
			return ;
	pb(stack_a, stack_b, 4, len_stack(stack_b, (argc - 1)), 1);
	ft_sort_3(stack_a, argc);
	pa(stack_a, stack_b, 4, len_stack(stack_b, (argc - 1)));
}

void	ft_sort_5(int *stack_a, int *stack_b, int argc)
{
	int	index;
	int	aux_min;

	index = -1;
	while (++index < 5)
	{
		if (stack_a[index] == 0)
			aux_min = index;
	}
	if (aux_min == 1)
		ra(stack_a, 5, 1);
	else if (aux_min == 2)
	{
		ra(stack_a, 5, 1);
		ra(stack_a, 5, 1);
	}
	else if (aux_min == 3)
	{
		rra(stack_a, 5, 1);
		rra(stack_a, 5, 1);
	}
	else if (aux_min == 4)
		rra(stack_a, 5, 1);
	if (game_completed(stack_a, 5) == 1)
			return ;
	pb(stack_a, stack_b, 5, 0, 1);
	ft_sort_4(stack_a, stack_b, argc);
	pa(stack_a, stack_b, 5, 1);
}
