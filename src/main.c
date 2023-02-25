/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:52:47 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/25 01:31:36 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	*stack_b;
	int	bits;

	if (argc < 2)
		return (0);
	stack_a = (int *) ft_calloc(sizeof(int), (argc - 1));
	if (!stack_a)
		return (0);
	if (process_input(argc, argv, stack_a) == 0)
		return (ft_printf("Error\n"), free(stack_a), 0);
	if (check_repeated_stack_a(stack_a, (argc - 1)) == 0)
		return (ft_printf("Error\n"), free(stack_a), 0);
	stack_b = value_to_index(stack_a, (argc - 1), 2147483648, -2147483649);
	if (!stack_b)
		return (free(stack_a), 0);
	bits = num_bits(len_stack(stack_a, argc - 1) - 1);
	plot_both_stacks(stack_a, stack_b, (argc - 1));
	if (len_stack(stack_a, argc - 1) <= 5)
		ft_game_basic(stack_a, argc);
		//ft_game(stack_a, stack_b, bits, argc);
	else
		ft_game(stack_a, stack_b, bits, argc);
	plot_both_stacks(stack_a, stack_b, (argc - 1));
	atexit(ft_leaks);
	return (free(stack_a), free(stack_b), 0);
}

/* 
	TO DO:
	0.- REVISAR LA ENTRADA CUANDO ES TIPO "1 3 2 4 5" Y CON EL CHECKER
	1.- METER LOS FTPRINTF DE LAS INSTRUCCIONES EN SUS FUNCIONES
	2.- METER STACKS Y TAMAÑOS EN UN STRUCT PARA TENER MENOS PARAMETROS EN FUNCIONES
	3.- OPTIMIZAR USANDO EL RESTO DE INSTRUCCIONES
	4.- HACER LA FUNCIÓN PARA QUE ORDENE CUANDO SON <= A 5 NUMEROS
*/

/*
	Para representar el stack en decimal y binario:
	//plot_both_stacks(stack_a, stack_b, (argc - 1));
	//print_stacks_by_bits(stack_a, stack_b, argc - 1, bits);
*/

/* Testeamos que las instrucciones funcionen bien
	test_instructions(stack_a, stack_b, argc); 
*/
