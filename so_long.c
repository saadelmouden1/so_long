/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 01:12:45 by sel-moud          #+#    #+#             */
/*   Updated: 2024/04/16 06:48:24 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_textures1(t_game_cars *game)
{
	game->wall = mlx_load_png("./textures/wall.png");
	if (!game->wall)
		ft_close(game);
	game->wl = mlx_texture_to_image(game->mlx, game->wall);
	if (!game->wl)
		ft_close(game);
	game->vid = mlx_load_png("./textures/walking_path.png");
	if (!game->wall)
		ft_close(game);
	game->vd = mlx_texture_to_image(game->mlx, game->vid);
	if (!game->wl)
		ft_close(game);
	game->pl_up = mlx_load_png("./textures/player_d.png");
	if (!game->wall)
		ft_close(game);
}

void	set_textures(t_game_cars *game)
{
	set_textures1(game);
	game->player_up = mlx_texture_to_image(game->mlx, game->pl_up);
	if (!game->wl)
		ft_close(game);
	game->fd = mlx_load_png("./textures/coffee.png");
	if (!game->wall)
		ft_close(game);
	game->food = mlx_texture_to_image(game->mlx, game->fd);
	if (!game->wl)
		ft_close(game);
	game->et = mlx_load_png("./textures/exit.png");
	if (!game->et)
		ft_close(game);
	game->exit = mlx_texture_to_image(game->mlx, game->et);
	if (!game->exit)
		ft_close(game);
}

int	controls_car(struct mlx_key_data key_data, void *param)
{
	t_game_cars	*game;
	int			works;

	game = (t_game_cars *)param;
	works = 0;
	if (key_data.key == MLX_KEY_UP && key_data.action == MLX_PRESS)
		works = move_u_d(key_data, game);
	if (key_data.key == MLX_KEY_DOWN && key_data.action == MLX_PRESS)
		works = move_u_d(key_data, game);
	if (key_data.key == MLX_KEY_RIGHT && key_data.action == MLX_PRESS)
		works = move_l_r(key_data, game);
	if (key_data.key == MLX_KEY_LEFT && key_data.action == MLX_PRESS)
		works = move_l_r(key_data, game);
	if (key_data.key == MLX_KEY_ESCAPE)
	{
		ft_close(game);
		exit(0);
	}
	if (works == 1)
	{
		print_map(game);
		ft_putnbr_fd(game->counter, 1);
		ft_putstr("\n", 1);
	}
	return (1);
}

void	get_pos_player(t_game_cars *game)
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
			if (game->gamemap[i][j] == 'P')
			{
				game->x_player = j;
				game->y_player = i;
			}
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	t_game_cars	game;

	if (ac != 1)
	{
		ft_memset(&game, 0, sizeof(t_game_cars));
		get_map(&game, av);
		get_with(&game);
		get_pos_player(&game);
		check_errs(&game);
		game.mlx = mlx_init((game.map_width * 32), game.map_height * 32,
				"so_long", true);
		if (!game.mlx)
		{
			game.err = 1;
			ft_close(&game);
		}
		set_textures(&game);
		print_map(&game);
		mlx_key_hook(game.mlx, (mlx_keyfunc)controls_car, &game);
		mlx_loop(game.mlx);
		ft_close(&game);
	}
	else
		ft_putstr("Error\nput the map", 2);
	return (0);
}
