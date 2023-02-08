/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:52:31 by antdelga          #+#    #+#             */
/*   Updated: 2022/12/21 22:31:04 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_replace_arg(char c, va_list *args, int *cont)
{
	if (c == 'c')
		ft_char(va_arg(*args, int), cont);
	if (c == 's')
		ft_string(va_arg(*args, char *), cont);
	if (c == 'd' || c == 'i')
		ft_integer(va_arg(*args, int), cont);
	if (c == 'u')
		ft_uint(va_arg(*args, unsigned int), cont);
	if (c == 'p')
		ft_pointer(va_arg(*args, void *), cont);
	if (c == 'x')
		ft_hex(va_arg(*args, unsigned int), cont);
	if (c == 'X')
		ft_hex_mayus(va_arg(*args, unsigned int), cont);
}
