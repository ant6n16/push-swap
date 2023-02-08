/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:22:38 by antdelga          #+#    #+#             */
/*   Updated: 2022/11/29 18:12:51 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i1;
	const char	*oc;

	oc = NULL;
	i1 = 0;
	while (s[i1] != '\0')
	{
		if (s[i1] == (const char) c)
		{
			oc = &s[i1];
			return ((char *) oc);
		}
		i1++;
	}
	if (s[i1] == (const char) c)
		oc = &s[i1];
	return ((char *) oc);
}
