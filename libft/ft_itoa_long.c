/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:29:44 by antdelga          #+#    #+#             */
/*   Updated: 2022/12/21 22:31:30 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_digits(unsigned int n)
{
	int	cont;

	if (n == 0)
		return (1);
	cont = 0;
	while (n)
	{
		n = n / 10;
		cont++;
	}
	return (cont);
}

static char	*get_number(char *table, unsigned int n, int digits)
{
	table[digits] = '\0';
	if (n == 0)
	{
		table[--digits] = '0';
		return (table);
	}
	while (n)
	{
		digits--;
		table[digits] = (n % 10) + '0';
		n = n / 10;
	}
	return (table);
}

char	*ft_itoa_long(unsigned int n)
{
	int		digits;
	char	*result;

	digits = num_digits(n);
	result = (char *) malloc(sizeof(char) * (digits + 1));
	if (result == NULL)
		return (NULL);
	get_number(result, n, digits);
	return (result);
}
