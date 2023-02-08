/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 14:35:34 by antdelga          #+#    #+#             */
/*   Updated: 2022/12/06 23:17:25 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_digits(long n)
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

static char	*get_number(char *table, long n, int digits)
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

char	*ft_itoa(int n)
{
	int		digits;
	char	*result;
	long	neg;

	if (n < 0)
	{
		neg = ((long) n) * (-1);
		digits = num_digits((neg));
		digits++;
	}
	else
		digits = num_digits((long) n);
	result = (char *) malloc(sizeof(char) * (digits + 1));
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		get_number(result, neg, digits);
	}
	else
		get_number(result, (long) n, digits);
	return (result);
}
