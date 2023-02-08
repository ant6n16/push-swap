/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:08:50 by antdelga          #+#    #+#             */
/*   Updated: 2022/12/04 21:39:04 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i1;
	const char	*oc;

	oc = NULL;
	i1 = 0;
	while (s[i1] != '\0')
	{
		if (s[i1] == (const char) c)
			oc = &s[i1];
		i1++;
	}
	if (s[i1] == (const char) c)
		oc = &s[i1];
	return ((char *) oc);
}
