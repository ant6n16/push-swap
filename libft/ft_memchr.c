/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:24:21 by antdelga          #+#    #+#             */
/*   Updated: 2022/11/29 18:35:56 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i1;
	void	*oc;

	oc = NULL;
	i1 = 0;
	while (i1 < n)
	{
		if (((unsigned char *)s)[i1] == (unsigned char) c)
		{
			oc = (void *) &s[i1];
			return (oc);
		}
		i1++;
	}
	return (oc);
}
