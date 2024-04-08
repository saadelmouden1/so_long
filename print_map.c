/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:36:00 by sel-moud          #+#    #+#             */
/*   Updated: 2024/04/08 02:52:12 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_player(game_cars *game, int i, int j)
{
	if (mlx_image_to_window(game->mlx, game->vd, j * 32, i * 32) < 0)
		ft_close(game);
	if (game->x_e == j && game->y_e == i)
		if (mlx_image_to_window(game->mlx, game->exit, j * 32, i * 32) < 0)
			ft_close(game);
	if (mlx_image_to_window(game->mlx, game->player_up, j * 32, i * 32) < 0)
		ft_close(game);
	game->x_player = j;
	game->y_player = i;
}

void	print_collect(game_cars *game, int i, int j)
{
	if (mlx_image_to_window(game->mlx, game->vd, j * 32, i * 32) < 0)
		ft_close(game);
	if (mlx_image_to_window(game->mlx, game->food, j * 32, i * 32) < 0)
		ft_close(game);
	if (game->isfirst == 0)
		game->collectible++;
}

void	print_exit(game_cars *game, int i, int j)
{
	if (mlx_image_to_window(game->mlx, game->vd, j * 32, i * 32) < 0)
		ft_close(game);
	if (mlx_image_to_window(game->mlx, game->exit, j * 32, i * 32) < 0)
		ft_close(game);
	if (game->isfirst == 0)
	{
		game->x_e = j;
		game->y_e = i;
	}
}

void	print_borders(game_cars *game, int i, int j)
{
	if (game->gamemap[i][j] == '1')
	{
		if (mlx_image_to_window(game->mlx, game->wl, j * 32, i * 32) < 0)
			ft_close(game);
	}
	if (game->gamemap[i][j] == '0')
	{
		if (mlx_image_to_window(game->mlx, game->vd, j * 32, i * 32) < 0)
			ft_close(game);
	}
}

void	print_map(game_cars *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (game->gamemap[i] != NULL)
	{
		j = 0;
		while (game->gamemap[i][j] != '\0')
		{
			print_borders(game, i, j);
			if (game->gamemap[i][j] == 'P')
				print_player(game, i, j);
			if (game->gamemap[i][j] == 'C')
				print_collect(game, i, j);
			if (game->gamemap[i][j] == 'E')
				print_exit(game, i, j);
			j++;
		}
		i++;
	}
	game->isfirst = 1;
}
