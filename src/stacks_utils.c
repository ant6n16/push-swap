/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:27:22 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/23 21:40:06 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_repeated_stack_a(int *stack_a, int size)
{
	int	temp;
	int	index;
	int	index2;

	index = -1;
	while (++index < (size - 1))
	{
		temp = stack_a[index];
		index2 = index;
		while (++index2 < size)
		{
			if (temp == stack_a[index2])
				return (0);
		}
	}
	return (1);
}

void	plot_stack(int *stack, int size)
{
	int	index;

	index = 0;
	while (index < size)
		ft_printf("%d\n", stack[index++]);
}

void	plot_both_stacks(int *stack_a, int *stack_b, int size)
{
	int	index;
	int	aux_a;
	int	aux_b;

	index = -1;
	ft_printf("\nStack_A     Stack_B\n");
	ft_printf(" ----------------- \n");
	while (++index < size)
	{
		aux_a = stack_a[index];
		aux_b = stack_b[index];
		if (aux_a == -1 && aux_b != -1)
			ft_printf("              %d\n", stack_b[index]);
		else if (aux_a != -1 && aux_b == -1)
			ft_printf("   %d           \n", stack_a[index]);
		else if (aux_a != -1 && aux_b != -1)
			ft_printf("   %d          %d\n", stack_a[index], stack_b[index]);
	}	
	ft_printf(" ----------------- \n\n");
}

int	len_stack(int *stack, int limit)
{
	int	index;

	index = 0;
	while (stack[index] != -1 && index < limit)
		index++;
	return (index);
}

void	test_instructions(int *stack_a, int *stack_b, int argc)
{
	/* Stack A con los datos de entrada, Stack B vacío (con -1) */
	ft_printf("Originales:\n");
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos SA e imprimimos ambas stacks */
	ft_printf("Probamos Swap los dos primeros de A:\n");
	sa(stack_a, len_stack(stack_a, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));
	
	/* Probamos a pasar el primero de A a B dos veces */
	ft_printf("Probamos pasar el primero de A a B dos veces:\n");
	pb(stack_a, stack_b, len_stack(stack_a, (argc - 1)), len_stack(stack_b, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));
	pb(stack_a, stack_b, len_stack(stack_a, (argc - 1)), len_stack(stack_b, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos SB e imprimimos ambas stacks*/
	ft_printf("Probamos Swap los dos primeros de B:\n");
	sb(stack_b, len_stack(stack_b, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos swap de ambos stacks e imprimimos ambas stacks*/
	ft_printf("Probamos Swap los dos primeros de ambos stacks:\n");
	ss(stack_a, stack_b, len_stack(stack_a, (argc - 1)), len_stack(stack_b, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos a rotar en A */
	ft_printf("Probamos rotar en A:\n");
	ra(stack_a, len_stack(stack_a, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos a rotar en B */
	ft_printf("Probamos rotar en B:\n");
	rb(stack_b, len_stack(stack_b, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos a rotar en A y B */
	ft_printf("Probamos rotar en A y B:\n");
	rr(stack_a, stack_b, len_stack(stack_a, (argc - 1)), len_stack(stack_b, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos a pasar el primero de B a A dos veces */
	ft_printf("Probamos pasar el primero de B a A dos veces:\n");
	pa(stack_a, stack_b, len_stack(stack_a, (argc - 1)), len_stack(stack_a, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));
	pa(stack_a, stack_b, len_stack(stack_a, (argc - 1)), len_stack(stack_a, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));

	/* Probamos a rotar reverso en A*/
	ft_printf("Probamos rotar reverso en A:\n");
	rra(stack_a, len_stack(stack_a, (argc - 1)));
	plot_both_stacks(stack_a, stack_b, (argc - 1));
}
