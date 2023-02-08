/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 19:30:29 by antdelga          #+#    #+#             */
/*   Updated: 2022/11/30 19:38:07 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*rep;
	size_t	tam;
	size_t	cont;

	tam = ft_strlen(s1);
	cont = 0;
	rep = malloc(tam * sizeof(char) + 1);
	if (rep == NULL)
		return (NULL);
	while (cont < tam)
	{
		rep[cont] = s1[cont];
		cont++;
	}
	rep[cont] = '\0';
	return (rep);
}
