/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rot_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:39:44 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/28 16:19:13 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rb(int *stack_b, int len, int verbose)
{
	ra(stack_b, len, 0);
	if (verbose == 1)
		ft_printf("rb\n");
}

void	rrb(int *stack_b, int len, int verbose)
{
	rra(stack_b, len, 0);
	if (verbose == 1)
		ft_printf("rrb\n");
}

void	rrr(int *stack_a, int *stack_b, int len_a, int len_b)
{
	if (len_a < 2 || len_b < 2)
		return ;
	rra(stack_a, len_a, 0);
	rrb(stack_b, len_b, 0);
	ft_printf("rrr\n");
}
