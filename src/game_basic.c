/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_basic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:58:41 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/28 16:29:30 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_min(int *stack_a, int argc, int aux)
{
	int	len;
	int	index;
	int	min;

	index = -1;
	len = len_stack(stack_a, (argc - 1));
	while (++index < len)
	{
		if (stack_a[index] == aux)
			min = index;
	}
	return (min);
}

void	ft_game_basic(int *stack_a, int *stack_b, int argc)
{
	int	len_a;
	int	aux_min;

	len_a = len_stack(stack_a, (argc - 1));
	aux_min = get_min(stack_a, argc, 0);
	if (game_completed(stack_a, len_a, 0) == 1)
		return ;
	if (len_a == 2)
		sa(stack_a, len_a, 1);
	else if (len_a == 3)
		ft_sort_3(stack_a, len_a, 0);
	else if (len_a == 4)
		ft_sort_4(stack_a, stack_b, argc, aux_min);
	else if (len_a == 5)
		ft_sort_5(stack_a, stack_b, argc, aux_min);
}

void	ft_sort_3(int *stack_a, int len_a, int aux_min)
{
	if (stack_a[0] == (0 + aux_min))
	{
		rra(stack_a, len_a, 1);
		sa(stack_a, len_a, 1);
	}
	else if (stack_a[0] == (1 + aux_min) && stack_a[2] == (0 + aux_min))
		rra(stack_a, len_a, 1);
	else if (stack_a[0] == (1 + aux_min) && stack_a[2] == (2 + aux_min))
		sa(stack_a, len_a, 1);
	else if (stack_a[0] == (2 + aux_min) && stack_a[2] == (0 + aux_min))
	{
		ra(stack_a, len_a, 1);
		sa(stack_a, len_a, 1);
	}
	else
		ra(stack_a, len_a, 1);
}

void	ft_sort_4(int *stack_a, int *stack_b, int argc, int aux_min)
{
	int	aux_ord;

	aux_ord = 0;
	if (len_stack(stack_b, (argc - 1)) == 1)
		aux_ord = 1;
	if (aux_min == 1)
		ra(stack_a, 4, 1);
	else if (aux_min == 2)
	{
		ra(stack_a, 4, 1);
		ra(stack_a, 4, 1);
	}
	else if (aux_min == 3)
		rra(stack_a, 4, 1);
	if (game_completed(stack_a, 4, aux_ord) == 1)
		return ;
	pb(stack_a, stack_b, argc, 1);
	ft_sort_3(stack_a, 3, 1 + aux_ord);
	pa(stack_a, stack_b, argc);
}

void	ft_sort_5(int *stack_a, int *stack_b, int argc, int aux_min)
{
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
	if (game_completed(stack_a, 5, 0) == 1)
		return ;
	pb(stack_a, stack_b, argc, 1);
	ft_sort_4(stack_a, stack_b, argc, get_min(stack_a, argc, 1));
	pa(stack_a, stack_b, argc);
}
