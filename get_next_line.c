/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:02:55 by sel-moud          #+#    #+#             */
/*   Updated: 2024/04/16 01:07:34 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

char	*read_line(char **holder_ptr, int fd)
{
	char	*hold;
	int		readed;

	readed = 1;
	hold = malloc((size_t)BUFFER_SIZE + 1);
	if (!hold)
		return (free(*holder_ptr), *holder_ptr = NULL, NULL);
	while (found_newline(*holder_ptr) != 0 && readed > 0)
	{
		readed = read(fd, hold, BUFFER_SIZE);
		if (readed <= 0)
			break ;
		hold[readed] = '\0';
		*holder_ptr = ft_strjoin(*holder_ptr, hold);
		if (!*holder_ptr)
			return (free(hold), hold = NULL, *holder_ptr = NULL, NULL);
	}
	if (!holder_ptr[0])
		return (free(hold), hold = NULL, NULL);
	return (free(hold), hold = NULL, *holder_ptr);
}

char	*get_line(char *holder)
{
	char	*ret;
	int		i;
	int		j;

	if (!holder)
		return (NULL);
	i = 0;
	while (holder[i] && holder[i] != '\n')
		i++;
	ret = malloc((i + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	j = i;
	i = 0;
	while (i < j)
	{
		ret[i] = holder[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*get_update(char *retholder, char *holder)
{
	int	i;
	int	j;

	if (!holder)
		return (NULL);
	i = 0;
	while (holder[i] && holder[i] != '\n')
		i++;
	if (holder[i] == '\n')
		i++;
	j = 0;
	while (holder[i])
	{
		retholder[j] = holder[i];
		i++;
		j++;
	}
	if (j == 0)
	{
		free(holder);
		return (0);
	}
	retholder[j] = '\0';
	return (retholder);
}

char	*get_next_line(int fd)
{
	static char	*holder;
	char		*line;

	line = NULL;
	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0 || read(fd, "", 0) < 0
		|| BUFFER_SIZE > INT_MAX)
		return (free(holder), holder = NULL, NULL);
	holder = read_line(&holder, fd);
	if (!holder)
		return (free(line), NULL);
	line = get_line(holder);
	if (!line)
		return (free(holder), holder = NULL, NULL);
	holder = get_update(holder, holder);
	return (line);
}
