/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:17:35 by antdelga          #+#    #+#             */
/*   Updated: 2022/12/09 17:11:50 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		index;
	int		result;
	int		sign;

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
