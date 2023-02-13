/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 19:42:03 by antdelga          #+#    #+#             */
/*   Updated: 2023/02/09 20:14:39 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

long int	ft_atoi_long(const char *str)
{
	long int	index;
	long int	result;
	long int	sign;

	index = 0;
	result = 0;
	sign = 1;
	while ((str[index] == ' ' || str[index] == '\n' || str[index] == '\t') || \
	str[index] == '\v' || str[index] == '\f' || str[index] == '\r')
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		sign = sign + (-2) * (str[index] == '-');
		index++;
	}
	while (str[index] != '\0')
	{
		if (str[index] >= '0' && str[index] <= '9')
			result = result * 10 + (str[index] - 48);
		else
			return (result * sign);
		index++;
	}
	return (result * sign);
}
