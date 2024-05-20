/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movments2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:45:21 by sel-moud          #+#    #+#             */
/*   Updated: 2024/04/16 03:07:51 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_l(t_game_cars *game, int i, int j, int c)
{
	i--;
	if (game->gamemap[j][i] == '1')
		return (0);
	c = right_move(game, i, j);
	if (!c)
		return (0);
	if (j == game->y_e && (i + 1) == game->x_e)
	{
		game->gamemap[j][i + 1] = 'E';
	}
	else
		game->gamemap[j][i + 1] = '0';
	return (1);
}

int	move_r(t_game_cars *game, int i, int j, int c)
{
	i++;
	if (game->gamemap[j][i] == '1')
		return (0);
	c = right_move(game, i, j);
	if (!c)
		return (0);
	if (j == game->y_e && (i - 1) == game->x_e)
	{
		game->gamemap[j][i - 1] = 'E';
	}
	else
		game->gamemap[j][i - 1] = '0';
	return (1);
}

int	move_l_r(struct mlx_key_data key_data, t_game_cars *game)
{
	int	i;
	int	j;
	int	c;

	i = game->x_player;
	j = game->y_player;
	c = 0;
	if (key_data.key == MLX_KEY_LEFT)
	{
		c = move_l(game, i, j, c);
		if (!c)
			return (0);
	}
	if (key_data.key == MLX_KEY_RIGHT)
	{
		c = move_r(game, i, j, c);
		if (!c)
			return (0);
	}
	return (1);
}
