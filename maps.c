/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 02:21:05 by sel-moud          #+#    #+#             */
/*   Updated: 2024/04/08 01:57:58 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height_map(int fd)
{
	int		i;
	char	*a;

	i = 0;
	a = get_next_line(fd);
	while (a != NULL)
	{
		free(a);
		a = get_next_line(fd);
		i++;
	}
	return (i);
}

void	get_map(game_cars *game, char **av)
{
	int	fd;
	int	mp_height;
	int	fd1;
	int	i;

	fd = open(av[1], O_RDONLY);
	mp_height = get_height_map(fd);
	close(fd);
	game->gamemap = (char **)malloc((mp_height + 1) * sizeof(char *));
	i = 0;
	fd1 = open(av[1], O_RDONLY);
	while ((game->gamemap[i] = get_next_line(fd1)) != NULL)
		i++;
	close(fd1);
	game->gamemap[i] = NULL;
	game->map_height = mp_height;
}

void	get_with(game_cars *game)
{
	int	i;

	i = 0;
	while (game->gamemap[0][i] != '\0')
	{
		i++;
	}
	game->map_width = i;
}
