/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:53:36 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/28 16:28:11 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

/* PROCESS INPUT*/
int		process_input(int argc, char **argv, int *stack_a);
int		check_numeric_string(char *str);
int		*create_stack_b_filled(int size);
int		*swap_table(int *stack_a, int *aux, int size);
int		*value_to_index(int *stack_a, int size, long max_aux, long min_aux);

/* STACKS UTILS*/
int		check_repeated_stack_a(int *stack_a, int size);
void	plot_stack(int *stack, int size);
void	plot_both_stacks(int *stack_a, int *stack_b, int size);
int		len_stack(int *stack, int limit);

/* INSTRUCTIONS*/
void	sa(int *stack_a, int len, int verbose);
void	sb(int *stack_b, int len, int verbose);
void	ss(int *stack_a, int *stack_b, int len_a, int len_b);
void	pa(int *stack_a, int *stack_b, int argc);
void	pb(int *stack_a, int *stack_b, int argc, int verbose);
void	ra(int *stack_a, int len, int verbose);
void	rb(int *stack_b, int len, int verbose);
void	rr(int *stack_a, int *stack_b, int len_a, int len_b);
void	rra(int *stack_a, int len, int verbose);
void	rrb(int *stack_b, int len, int verbose);
void	rrr(int *stack_a, int *stack_b, int len_a, int len_b);

/* BITS */
int		*print_bits(int octet, int num_bits);
int		num_bits(int limit);
void	print_stacks_by_bits(int *stack_a, int *stack_b, int size, int n_bits);
void	print_single_last(int *array, int len);
void	print_single_one(int *array, int len);
void	print_both(int *array1, int *array2, int len);
void	print_bits_single(int octet, int num_bits);

/* GAME */
void	ft_game_basic(int *stack_a, int *stack_b, int argc);
int		get_min(int *stack_a, int argc, int aux);
void	ft_sort_3(int *stack_a, int len_a, int aux_min);
void	ft_sort_4(int *stack_a, int *stack_b, int argc, int aux_min);
void	ft_sort_5(int *stack_a, int *stack_b, int argc, int aux_min);

/* GAME IMPROVEMENTS */
int		game_completed(int *stack, int len, int offset);
void	ft_game(int *stack_a, int *stack_b, int bits, int argc);
void	work_in_a(int *stack_a, int *stack_b, int in_bit, int argc);
void	return_to_a(int *stack_a, int *stack_b, int argc);

#endif
