/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pramos <pramos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:52:32 by pramos            #+#    #+#             */
/*   Updated: 2023/02/23 14:18:34 by pramos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_last(char *arch1r)
{
	int		s_to_n;
	char	*aux;

	s_to_n = 0;
	if (!arch1r)
	{
		free(arch1r);
		arch1r = 0;
		return (0);
	}
	while (arch1r[s_to_n] != '\n' && arch1r[s_to_n] != 0)
		s_to_n++;
	aux = ft_substr(arch1r, s_to_n + 1, ft_strlen(arch1r) - s_to_n);
	free(arch1r);
	arch1r = aux;
	return (arch1r);
}

char	*ft_get_line_ready(char *arch1r)
{
	char	*aux;
	int		i;

	i = 0;
	if (!arch1r)
	{
		free(arch1r);
		arch1r = 0;
		return (0);
	}
	while (arch1r[i] != '\n' && arch1r[i] != 0)
		i++;
	aux = ft_substr(arch1r, 0, i + 1);
	if (!aux)
	{
		free(aux);
		return (NULL);
	}
	return (aux);
}

char	*ft_read_line(int fd, char *arch1r)
{
	int		lectura;
	char	archaux[BUFFER_SIZE + 1];

	lectura = 1;
	while (lectura != 0)
	{
		lectura = read(fd, &archaux, BUFFER_SIZE);
		if (lectura < 0)
		{
			free(arch1r);
			arch1r = NULL;
			return (arch1r);
		}
		if (lectura == 0)
			break ;
		archaux[lectura] = 0;
		arch1r = ft_strjoin(arch1r, archaux);
		if (!arch1r)
			return (0);
		if (ft_strchr(arch1r, '\n'))
			break ;
	}
	return (arch1r);
}

char	*get_next_line(int fd)
{
	static char		*arch1r[1024];
	char			*finaline;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(arch1r[fd]);
		arch1r[fd] = 0;
		return (0);
	}
	arch1r[fd] = ft_read_line(fd, arch1r[fd]);
	if (!arch1r[fd])
		return (NULL);
	finaline = ft_get_line_ready(arch1r[fd]);
	arch1r[fd] = ft_get_last(arch1r[fd]);
	return (finaline);
}
