/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:52:47 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/20 21:34:05 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;

	stack_a = (int *) ft_calloc(sizeof(int), (argc - 1));
	if (!stack_a)
		return (0);
	if (process_input(argc, argv, stack_a) == 0)
		return (free(stack_a), 0);
	if (check_repeated_stack_a(stack_a, (argc - 1)) == 0)
		return (free(stack_a), 0);
	stack_b = value_to_index(stack_a, (argc - 1), 2147483648, -2147483649);
	if (!stack_b)
		return (free(stack_a), 0);

	/* Stack A con los datos de entrada, Stack B vacío (con -1) */
	ft_printf("Originales:\n");
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos SA e imprimimos ambas stacks */
	ft_printf("Probamos Swap los dos primeros de A:\n");
	sa(stack_a, len_stack(stack_a, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));
	
	/* Probamos a pasar el primero de A a B dos veces */
	ft_printf("Probamos pasar el primero de A a B dos veces:\n");
	pb(stack_a, stack_b, len_stack(stack_a, (argc - 1)), len_stack(stack_a, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));
	pb(stack_a, stack_b, len_stack(stack_a, (argc - 1)), len_stack(stack_a, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos SB e imprimimos ambas stacks*/
	ft_printf("Probamos Swap los dos primeros de B:\n");
	sb(stack_b, len_stack(stack_b, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos swap de ambos stacks e imprimimos ambas stacks*/
	ft_printf("Probamos Swap los dos primeros de ambos stacks:\n");
	ss(stack_a, stack_b, len_stack(stack_a, (argc - 1)), len_stack(stack_b, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos a rotar reverso en A */
	ft_printf("Probamos rotar reverso en A:\n");
	ra(stack_a, len_stack(stack_a, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos a rotar reverso en B */
	ft_printf("Probamos rotar reverso en B:\n");
	rb(stack_b, len_stack(stack_b, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos a rotar reverso en A y B */
	ft_printf("Probamos rotar reverso en A y B:\n");
	rr(stack_a, stack_b, len_stack(stack_a, (argc - 1)), len_stack(stack_b, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos a rotar en A*/
	ft_printf("Probamos rotar en A:\n");
	rra(stack_a, len_stack(stack_a, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos a pasar el primero de B a A dos veces */
	ft_printf("Probamos pasar el primero de B a A dos veces:\n");
	pa(stack_a, stack_b, len_stack(stack_a, (argc - 1)), len_stack(stack_a, (argc - 1)));

	plot_both_stacks(stack_a, stack_b, (argc - 1));
	pa(stack_a, stack_b, len_stack(stack_a, (argc - 1)), len_stack(stack_a, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));



	return (0);
}
