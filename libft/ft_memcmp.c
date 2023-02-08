/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:44:42 by antdelga          #+#    #+#             */
/*   Updated: 2022/11/29 19:34:56 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*su1;
	unsigned char	*su2;

	su1 = (unsigned char *) s1;
	su2 = (unsigned char *) s2;
	index = 0;
	while (index < n)
	{
		if (*su1 != *su2)
			return (*su1 - *su2);
		su1++;
		su2++;
		index++;
	}
	return (0);
}
