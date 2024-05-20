/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:03:18 by sel-moud          #+#    #+#             */
/*   Updated: 2024/04/16 01:54:19 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_char(t_game_cars *game, int h, int w)
{
	if (game->gamemap[h][w] != 'P' && game->gamemap[h][w] != 'E'
		&& game->gamemap[h][w] != 'C' && game->gamemap[h][w] != '0'
		&& game->gamemap[h][w] != '1')
	{
		ft_putstr("Error\n", 2);
		ft_putnbr_fd(game->gamemap[h][w], 2);
		ft_putstr("\n", 2);
		ft_close(game);
	}
	if (game->gamemap[h][w] == 'P')
		game->p_count++;
	if (game->gamemap[h][w] == 'C')
		game->c_count++;
	if (game->gamemap[h][w] == 'E')
		game->e_count++;
}

void	check_items(t_game_cars *game)
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
	if (!(game->p_count == 1 && game->c_count >= 1 && game->e_count == 1))
	{
		game->err = 1;
		ft_putstr("Error\nSomething is wrong!\n", 2);
		ft_close(game);
	}
}
