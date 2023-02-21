/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_rot_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:39:44 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/21 20:40:47 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rb(int *stack_b, int len)
{
	ra(stack_b, len);
}

void	rrb(int *stack_b, int len)
{
	rra(stack_b, len);
}

void	rrr(int *stack_a, int *stack_b, int len_a, int len_b)
{
	if (len_a < 2 || len_b < 2)
		return ;
	rra(stack_a, len_a);
	rrb(stack_b, len_b);
}
