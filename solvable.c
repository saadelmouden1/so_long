/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 00:42:51 by sel-moud          #+#    #+#             */
/*   Updated: 2024/04/08 00:49:39 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_move_valid(game_cars *game, int y, int x, int **has_visited)
{
	if (game->gamemap[y][x] == '1' || has_visited[y][x])
		return (0);
	return (1);
}

void	flood_fill(game_cars *game, int y, int x, int **has_visited)
{
	int			i;
	static int	direction_x[] = {-1, 0, 0, 1};
	static int	direction_y[] = {0, -1, 1, 0};
	int			new_x;
	int			new_y;

	i = 0;
	has_visited[y][x] = 1;
	while (i < 4)
	{
		new_x = x + direction_x[i];
		new_y = y + direction_y[i];
		if (is_move_valid(game, new_y, new_x, has_visited) == 1)
			flood_fill(game, new_y, new_x, has_visited);
		i++;
	}
}

int	allocate(game_cars *game, int **has_visited)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (a < game->map_height)
	{
		has_visited[a] = (int *)malloc(game->map_width * sizeof(int));
		if (!has_visited[a])
			return (0);
		b = 0;
		while (b < game->map_width)
		{
			has_visited[a][b] = 0;
			b++;
		}
		a++;
	}
	return (1);
}
void	free_int_tab(game_cars *game, int **has_visited)
{
	int	a;

	a = 0;
	while (a < game->map_height)
	{
		free(has_visited[a]);
		a++;
	}
	free(has_visited);
}
int	check_map_solvable(game_cars *game)
{
	static int	**has_visited;
	int			x;
	int			y;

	has_visited = (int **)malloc(game->map_height * sizeof(int *));
	if (!has_visited)
		return (0);
	if (allocate(game, has_visited) == 0)
		return (0);
	y = 0;
	flood_fill(game, game->y_player, game->x_player, has_visited);
	while (game->gamemap[y] != NULL)
	{
		x = 0;
		while (x < game->map_width)
		{
			if ((game->gamemap[y][x] == 'E' || game->gamemap[y][x] == 'C')
				&& !has_visited[y][x])
				return (0);
			x++;
		}
		y++;
	}
	free_int_tab(game, has_visited);
	return (1);
}
