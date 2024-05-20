/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:39:13 by sel-moud          #+#    #+#             */
/*   Updated: 2024/04/16 01:54:46 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freeing(t_game_cars *game)
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

void	ft_close(t_game_cars *game)
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
	if (game->err == 1)
		exit(1);
	else
		exit(0);
}

void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}

void	ft_putstr(char *str, int fd)
{
	int	i;

	if (!fd)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		write(fd, &str[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;
	char	a;

	nb = (long)n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb == 0)
		write(fd, "0", 1);
	if (nb < 10 && nb > 0)
	{
		a = nb + 48;
		write(fd, &a, 1);
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
