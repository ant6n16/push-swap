/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 19:56:11 by antdelga          #+#    #+#             */
/*   Updated: 2022/11/29 20:16:55 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i1;
	size_t	i2;
	size_t	l_dest;
	size_t	l_org;

	l_org = ft_strlen(src);
	l_dest = ft_strlen(dst);
	if (dstsize == 0 || dstsize <= l_dest)
		return (l_org + dstsize);
	i1 = l_dest;
	i2 = 0;
	while (src[i2] != '\0' && i2 < (dstsize - l_dest - 1))
	{
		dst[i1] = src[i2];
		i1++;
		i2++;
	}
	dst[i1] = '\0';
	return (l_dest + l_org);
}
