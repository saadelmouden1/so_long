/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 01:38:48 by sel-moud          #+#    #+#             */
/*   Updated: 2024/04/16 02:00:40 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	horizontal_check(t_game_cars *game)
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

int	vertical_check(t_game_cars *game)
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

int	ft_check_with(t_game_cars *game)
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

int	check_map(t_game_cars *game)
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

void	check_errs(t_game_cars *game)
{
	if (check_map(game) == 0)
	{
		game->err = 1;
		ft_putstr("Error\nerr in borders\n", 2);
		ft_close(game);
	}
	check_items(game);
	if (check_map_solvable(game) == 0)
	{
		game->err = 1;
		ft_putstr("Error\nmap not solvable\n", 2);
		ft_close(game);
	}
}
