/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-moud <sel-moud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 02:53:22 by sel-moud          #+#    #+#             */
/*   Updated: 2024/04/16 04:46:48 by sel-moud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/include/MLX42/MLX42.h"
#include <fcntl.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct game_c
{
	mlx_image_t		*player_up;
	mlx_image_t		*wl;
	mlx_image_t		*vd;
	mlx_image_t		*food;
	mlx_image_t		*exit;
	mlx_texture_t	*pl_up;
	mlx_texture_t	*wall;
	mlx_texture_t	*vid;
	mlx_texture_t	*fd;
	mlx_texture_t	*et;
	char			**gamemap;
	int				map_height;
	int				map_width;
	int				x_player;
	int				y_player;
	int				collectible;
	int				counter;
	int				isfirst;
	int				x_e;
	int				y_e;
	int				p_count;
	int				e_count;
	int				c_count;
	int				err;

	mlx_t			*mlx;
}					t_game_cars;

int					get_height_map(int fd);
void				get_map(t_game_cars *game, char **av);
void				get_with(t_game_cars *game);
int					right_move(t_game_cars *game, int i, int j);
int					move_u_d(struct mlx_key_data key_data, t_game_cars *game);
int					move_l_r(struct mlx_key_data key_data, t_game_cars *game);
int					horizontal_check(t_game_cars *game);
int					vertical_check(t_game_cars *game);
int					ft_check_with(t_game_cars *game);
int					check_map(t_game_cars *game);
void				ft_close(t_game_cars *game);
void				set_textures(t_game_cars *game);
void				print_map(t_game_cars *game);
int					controls_car(struct mlx_key_data key_data, void *param);
int					check_map_solvable(t_game_cars *game);
void				check_items(t_game_cars *game);
void				*ft_memset(void *b, int c, size_t length);
char				*get_next_line(int fd);
char				*get_update(char *retholder, char *holder);
char				*get_line(char *holder);
char				*read_line(char **holder_ptr, int fd);
char				*ft_strjoin(char *s1, char *s2);
int					found_newline(char *holder);
int					ft_strlen(char *str);
void				ft_putstr(char *str, int fd);
void				ft_putnbr_fd(int n, int fd);
void				check_errs(t_game_cars *game);
