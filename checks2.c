/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:03:18 by sel-moud          #+#    #+#             */
/*   Updated: 2024/04/08 02:03:25 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int h;
	int w;

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
		printf("\nError\nSomething is wrong!\n");
		printf("either player, exit or collectable issue\n");
		ft_close(game);
	}
}