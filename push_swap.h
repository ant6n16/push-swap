/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:53:36 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/14 01:31:50 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

int		process_input(int argc, char **argv, int *stack_a);
int		check_repeated_stack_a(int *stack_a, int size);
void	plot_stack(int *stack, int size);
int		*create_stack_b_filled(int size);
int		*value_to_index(int *stack_a, int size, long max_aux, long min_aux);
int		*swap_table(int *stack_a, int *aux, int size);
void	plot_both_stacks(int *stack_a, int *stack_b, int size);


#endif
