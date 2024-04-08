/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:39:13 by sel-moud          #+#    #+#             */
/*   Updated: 2024/04/08 01:41:19 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freeing(game_cars *game)
{
	int	line;

	line = 0;
	while (line < game->map_height)
	{
		if (game->gamemap[line])
			free(game->gamemap[line++]);
	}
	if (game->gamemap)
		free(game->gamemap);
	if (game->mlx)
		mlx_terminate(game->mlx);
}

void	ft_close(game_cars *game)
{
	if (game->wall)
		mlx_delete_texture(game->wall);
	if (game->vid)
		mlx_delete_texture(game->vid);
	if (game->fd)
		mlx_delete_texture(game->fd);
	if (game->et)
		mlx_delete_texture(game->et);
	if (game->pl_up)
		mlx_delete_texture(game->pl_up);
	if (game->food)
		mlx_delete_image(game->mlx, game->food);
	if (game->wl)
		mlx_delete_image(game->mlx, game->wl);
	if (game->player_up)
		mlx_delete_image(game->mlx, game->player_up);
	if (game->vd)
		mlx_delete_image(game->mlx, game->vd);
	if (game->exit)
		mlx_delete_image(game->mlx, game->exit);
	freeing(game);
	exit(0);
}

void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char *p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}