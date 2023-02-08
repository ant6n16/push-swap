/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:13:28 by antdelga          #+#    #+#             */
/*   Updated: 2022/11/29 18:22:05 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (((s1[index] != '\0') || (s2[index] != '\0')) && (index < n))
	{
		if (s1[index] == '\0')
			return ((s2[index]) * (-1));
		if (s2[index] == '\0')
			return ((unsigned char)s1[index]);
		if (s1[index] > s2[index])
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		else if ((s1[index] < s2[index]))
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		index++;
	}
	return (0);
}
