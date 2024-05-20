/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:06:03 by sel-moud          #+#    #+#             */
/*   Updated: 2024/04/16 03:16:00 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_0(t_game_cars *game, int i, int j)
{
	game->gamemap[j][i] = 'P';
	game->x_player = i;
	game->y_player = j;
	game->counter++;
}

int	right_move(t_game_cars *game, int i, int j)
{
	if (game->gamemap[j][i] == 'E')
	{
		if (game->collectible != 0)
		{
			game->gamemap[j][i] = 'P';
			game->x_player = i;
			game->y_player = j;
			game->counter++;
			return (1);
		}
		ft_putstr("\nYou Have Won, Congrats!\n", 1);
		ft_close(game);
	}
	if (game->gamemap[j][i] == '0')
		move_0(game, i, j);
	if (game->gamemap[j][i] == 'C')
	{
		game->gamemap[j][i] = 'P';
		game->x_player = i;
		game->y_player = j;
		game->collectible--;
		game->counter++;
	}
	return (1);
}

int	move_u(t_game_cars *game, int i, int j, int c)
{
	j--;
	if (game->gamemap[j][i] == '1')
		return (0);
	c = right_move(game, i, j);
	if (!c)
		return (0);
	if ((j + 1) == game->y_e && i == game->x_e)
		game->gamemap[j + 1][i] = 'E';
	else
		game->gamemap[j + 1][i] = '0';
	return (1);
}

int	move_d(t_game_cars *game, int i, int j, int c)
{
	j++;
	if (game->gamemap[j][i] == '1')
		return (0);
	c = right_move(game, i, j);
	if (!c)
		return (0);
	if ((j - 1) == game->y_e && i == game->x_e)
		game->gamemap[j - 1][i] = 'E';
	else
		game->gamemap[j - 1][i] = '0';
	return (1);
}

int	move_u_d(struct mlx_key_data key_data, t_game_cars *game)
{
	int	i;
	int	j;
	int	c;

	i = game->x_player;
	j = game->y_player;
	c = 0;
	if (key_data.key == MLX_KEY_UP)
	{
		c = move_u(game, i, j, c);
		if (!c)
			return (0);
	}
	if (key_data.key == MLX_KEY_DOWN)
	{
		c = move_d(game, i, j, c);
		if (!c)
			return (0);
	}
	return (1);
}
