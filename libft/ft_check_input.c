/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 21:07:12 by antdelga          #+#    #+#             */
/*   Updated: 2022/12/21 22:31:57 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_input(char *str, va_list *args)
{
	int	i;
	int	cont;

	cont = 0;
	i = 0;
	while (str[i] != '\0' && cont != -1)
	{
		if (str[i] != '%')
			ft_putchar_fd_cont(str[i], 1, &cont);
		else
		{
			if (str[i + 1] == '%' && str[i + 1] != '\0')
				ft_putchar_fd_cont(str[i + 1], 1, &cont);
			else if (ft_type(str[i + 1]))
				ft_replace_arg(str[i + 1], args, &cont);
			else
				ft_putchar_fd_cont(str[i + 1], 1, &cont);
			i++;
		}
		i++;
	}
	return (cont);
}
