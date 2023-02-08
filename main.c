/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 19:52:47 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/08 20:58:38 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	index;
	int	*prueba;

	if (argc < 2)
		return (0);
	prueba = (int *) ft_calloc(sizeof(int), (argc - 1));
	if (!prueba)
		return (0);
	index = 0;
	while (++index < argc)
		prueba[index - 1] = ft_atoi(argv[index]);
	index = 0;
	while (index < (argc - 1))
	{
		printf("%d\n", prueba[index++]);
	}
	return (0);
}
