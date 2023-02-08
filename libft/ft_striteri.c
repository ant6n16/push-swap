/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:05:02 by antdelga          #+#    #+#             */
/*   Updated: 2022/12/05 16:11:24 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	cont;

	if (!s || !f)
		return ;
	cont = 0;
	while (s[cont] != '\0')
	{
		f(cont, &s[cont]);
		cont++;
	}
	s[cont] = '\0';
}
