/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 01:38:48 by sel-moud          #+#    #+#             */
/*   Updated: 2024/04/07 02:19:45 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	horizontal_check(game_cars *game)
{
	int	i;
	int	j;

	i = game->map_width;
	j = 0;
	while (j < i)
	{
		if (game->gamemap[0][j] != '1' || game->gamemap[game->map_height
			- 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	vertical_check(game_cars *game)
{
	int	height;
	int	width;

	height = 0;
	width = game->map_width;
	while (height < game->map_height)
	{
		if (!(game->gamemap[height][0] == '1' && game->gamemap[height][width
				- 1] == '1'))
			return (0);
		height++;
	}
	return (1);
}

int	ft_check_with(game_cars *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(game->gamemap[0]);
	while (game->gamemap[i] != NULL)
	{
		if (len != ft_strlen(game->gamemap[i]))
			return (0);
		len = ft_strlen(game->gamemap[i]);
		i++;
	}
	return (1);
}

int	check_map(game_cars *game)
{
	if (ft_check_with(game) == 0)
	{
		return (0);
	}
	if (horizontal_check(game) == 0)
	{
		return (0);
	}
	if (vertical_check(game) == 0)
	{
		return (0);
	}
	return (1);
}

void	check_char(game_cars *game, int h, int w)
{
	if (game->gamemap[h][w] != 'P' && game->gamemap[h][w] != 'E'
		&& game->gamemap[h][w] != 'C' && game->gamemap[h][w] != '0'
		&& game->gamemap[h][w] != '1')
	{
		printf("error :%c\n", game->gamemap[h][w]);
		ft_close(game);
	}
	if (game->gamemap[h][w] == 'P')
		game->p_count++;
	if (game->gamemap[h][w] == 'C')
		game->c_count++;
	if (game->gamemap[h][w] == 'E')
		game->e_count++;
}

void	check_items(game_cars *game)
{
	int	h;
	int	w;

	h = 0;
	while (game->gamemap[h] != NULL)
	{
		w = 0;
		while (w < game->map_width)
		{
			check_char(game, h, w);
			w++;
		}
		h++;
	}
	if (!(game->p_count == 1 && game->c_count > 1 && game->e_count == 1))
	{
		printf("\nError\nSomething is wrong!\n");
		printf("either player, exit or collectable issue\n");
		ft_close(game);
	}
}
