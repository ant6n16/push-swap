/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:33:52 by antdelga          #+#    #+#             */
/*   Updated: 2022/12/02 20:49:44 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	size_t	l;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	l = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	final = (char *) malloc(sizeof(char) * (l + 1));
	if (final == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		final[i] = s1[i];
		i++;
	}
	while (i < l)
	{
		final[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	final[i] = '\0';
	return (final);
}
