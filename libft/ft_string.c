/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:06:22 by antdelga          #+#    #+#             */
/*   Updated: 2022/12/21 22:32:22 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_string(char *str, int *cont)
{
	int		index;

	if (!str)
		str = "(null)";
	index = 0;
	while (str[index] != '\0' && (*cont) != -1)
	{
		ft_putchar_fd_cont(str[index], 1, cont);
		index++;
	}
}
