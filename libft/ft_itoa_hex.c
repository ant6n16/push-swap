/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:40:22 by antdelga          #+#    #+#             */
/*   Updated: 2022/12/21 22:31:35 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_digits_hex(unsigned long n)
{
	int	cont;

	if (n == 0)
		return (1);
	cont = 0;
	while (n)
	{
		n = n / 16;
		cont++;
	}
	return (cont);
}

static char	*get_number_hex(char *table, unsigned long n, int digits, int mayus)
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
		if ((n % 16) < 10)
			table[digits] = (n % 16) + '0';
		else
		{
			if (mayus)
				table[digits] = (n % 16) + 'A' - 10;
			else
				table[digits] = (n % 16) + 'a' - 10;
		}
		n = n / 16;
	}
	return (table);
}

char	*ft_itoa_hex(unsigned long n, int mayus)
{
	int		digits;
	char	*result;

	digits = num_digits_hex(n);
	result = (char *) malloc(sizeof(char) * (digits + 1));
	if (result == NULL)
		return (NULL);
	get_number_hex(result, n, digits, mayus);
	return (result);
}
