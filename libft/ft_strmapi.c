/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:51:39 by antdelga          #+#    #+#             */
/*   Updated: 2022/12/05 16:03:19 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		cont;

	if (!s || !f)
		return (NULL);
	result = (char *) malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (result == NULL)
		return (NULL);
	cont = 0;
	while (s[cont] != '\0')
	{
		result[cont] = f(cont, s[cont]);
		cont++;
	}
	result[cont] = '\0';
	return (result);
}
