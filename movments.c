#include "so_long.h"

int	right_move(game_cars *game, int i, int j)
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
		printf("\nYou Have Won, Congrats!\n");
		ft_close(game);
	}
	if (game->gamemap[j][i] == '0')
	{
		game->gamemap[j][i] = 'P';
		game->x_player = i;
		game->y_player = j;
		game->counter++;
	}
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

int	move_u_d(struct mlx_key_data key_data, game_cars *game)
{
	int	i;
	int	j;
	int	c;

	i = game->x_player;
	j = game->y_player;
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP))
	{
		j--;
		if (game->gamemap[j][i] == '1')
			return (0);
		c = right_move(game, i, j);
		if (!c)
			return (0);
		if ((j + 1) == game->y_e && i == game->x_e)
		{
			game->gamemap[j + 1][i] = 'E';
		}
		else
			game->gamemap[j + 1][i] = '0';
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
	{
		j++;
		if (game->gamemap[j][i] == '1')
			return (0);
		c = right_move(game, i, j);
		if (!c)
			return (0);
		if ((j-1) == game->y_e && i == game->x_e)
		{
			game->gamemap[j - 1][i] = 'E';
        }
		else
			game->gamemap[j - 1][i] = '0';
	}
	return (1);
}

int	move_l_r(struct mlx_key_data key_data, game_cars *game)
{
	int	i;
	int	j;
    int	c;
	
	i = game->x_player;
	j = game->y_player;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
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
			 //printf("i :%d, j: %d",i,j);
		}
		else
			game->gamemap[j][i+1] = '0';
    }
	if (mlx_is_key_down(game->mlx,MLX_KEY_RIGHT))
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
             //printf("i :%d, j: %d",i,j);
		}
		else
			game->gamemap[j][i - 1] = '0';
	}
	return (1);
}
