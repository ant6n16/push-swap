/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:01:20 by antdelga          #+#    #+#             */
/*   Updated: 2022/12/08 15:33:14 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	free_memory(char **tabla, size_t i)
{
	while (i-- > 0)
		free(tabla[i]);
	free(tabla);
}

static char	**fill_table(char **tabla, size_t words, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	len;

	i = 0;
	start = 0;
	len = 0;
	while (i < words)
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		while (s[start] != '\0' && s[start] != c)
		{
			start++;
			len++;
		}
		tabla[i] = ft_substr(s, start - len, len);
		if (tabla[i++] == NULL)
		{
			free_memory(tabla, i);
			return (NULL);
		}
		len = 0;
	}
	return (tabla);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**tabla;

	words = count_words(s, c);
	tabla = (char **) ft_calloc(sizeof(char *), (words + 1));
	if (tabla == NULL)
		return (NULL);
	tabla = fill_table(tabla, words, s, c);
	return (tabla);
}
