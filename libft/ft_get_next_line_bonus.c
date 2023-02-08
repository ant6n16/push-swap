/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antdelga <antdelga@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 20:59:39 by antdelga          #+#    #+#             */
/*   Updated: 2023/01/26 20:21:37 by antdelga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*final;
	size_t	l;
	size_t	l1;
	size_t	i;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l = l1 + ft_strlen(s2);
	final = (char *) ft_calloc(sizeof(char), (l + 1));
	if (!final)
		return (free(s1), NULL);
	i = -1;
	while (++i < l1)
		final[i] = s1[i];
	while (i < l)
	{
		final[i] = s2[i - l1];
		i++;
	}
	return (free(s1), final);
}

static char	*ft_read(int fd, char *letters)
{
	char	*buf;
	int		cont;

	cont = 1;
	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (free(letters), letters = NULL, letters);
	while (ft_strchr(letters, '\n') == 0)
	{
		cont = read(fd, buf, BUFFER_SIZE);
		if (cont == 0)
			break ;
		buf[cont] = '\0';
		letters = ft_strjoin_gnl(letters, buf);
	}
	free(buf);
	return (letters);
}

char	*ft_cut_line(char *letters)
{
	int		i;
	char	*line;

	i = 0;
	if (letters[i] == '\0')
		return (NULL);
	while (letters[i] != '\0' && letters[i] != '\n')
		i++;
	if (letters[i] == '\0')
		i--;
	line = (char *) ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (letters[i] != '\0' && letters[i] != '\n')
	{
		line[i] = letters[i];
		i++;
	}
	if (letters[i] == '\n')
	{
		line[i] = letters[i];
		i++;
	}
	return (line);
}

char	*free_buffer(char *letters)
{
	int		i1;
	int		i2;
	char	*aux;

	i1 = 0;
	while (letters[i1] != '\0' && letters[i1] != '\n')
		i1++;
	if (letters[i1] == '\0')
	{
		free(letters);
		return (NULL);
	}
	aux = (char *) ft_calloc(sizeof(char), (ft_strlen(letters) - i1 + 1));
	if (!aux)
		return (free(letters), letters = NULL, letters);
	i1++;
	i2 = 0;
	while (letters[i1] != '\0')
		aux[i2++] = letters[i1++];
	free(letters);
	return (aux);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*letters[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, 0, 0) == -1)
		return (free(letters[fd]), letters[fd] = NULL, letters[fd]);
	letters[fd] = ft_read(fd, letters[fd]);
	if (!letters[fd])
		return (free(letters[fd]), letters[fd] = NULL, letters[fd]);
	line = ft_cut_line(letters[fd]);
	if (!line)
		return (free(letters[fd]), letters[fd] = NULL, letters[fd]);
	letters[fd] = free_buffer(letters[fd]);
	return (line);
}
