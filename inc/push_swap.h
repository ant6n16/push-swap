/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:53:36 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/20 21:32:46 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

/* PROCESS INPUT*/
int		process_input(int argc, char **argv, int *stack_a);
int		check_repeated_stack_a(int *stack_a, int size);

/* STACKS UTILS*/
void	plot_stack(int *stack, int size);
int		*create_stack_b_filled(int size);
int		*value_to_index(int *stack_a, int size, long max_aux, long min_aux);
int		*swap_table(int *stack_a, int *aux, int size);
void	plot_both_stacks(int *stack_a, int *stack_b, int size);
int		len_stack(int *stack, int limit);

/* INSTRUCTIONS*/
void	sa(int *stack_a, int len);
void	sb(int *stack_b, int len);
void	ss(int *stack_a, int *stack_b, int lenA, int lenB);
void	pa(int *stack_a, int *stack_b, int lenA, int lenB);
void	pb(int *stack_a, int *stack_b, int lenA, int lenB);
void	ra(int *stack_a, int len);
void	rb(int *stack_b, int len);
void	rr(int *stack_a, int *stack_b, int lenA, int lenB);
void	rra(int *stack_a, int len);
void	rrb(int *stack_b, int len);
void	rrr(int *stack_a, int *stack_b, int lenA, int lenB);

#endif
