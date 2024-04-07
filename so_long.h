#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "MLX42/include/MLX42/MLX42.h"
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

typedef struct game_c
{
    mlx_image_t *player_up;
    mlx_image_t *wl;
    mlx_image_t *vd;
    mlx_image_t *food;
    mlx_image_t *exit;
    mlx_texture_t *pl_up;
    mlx_texture_t *wall;
    mlx_texture_t *vid;
    mlx_texture_t *fd;
    mlx_texture_t *et;
    char **gamemap;
    int map_height;
    int map_width;
    int x_player;
    int y_player;
    int collectible;
    int counter;
    int isfirst;
    int x_e;
    int y_e;
    int p_count;
    int e_count;
    int c_count;

    mlx_t *mlx;


} game_cars;

int get_height_map(int fd);
void get_map(game_cars *game, char **av);
void get_with(game_cars *game);
int	right_move(game_cars *game, int i, int j);
int move_u_d(struct mlx_key_data key_data, game_cars *game);
int move_l_r(struct mlx_key_data key_data, game_cars *game);
int horizontal_check(game_cars *game);
int vertical_check(game_cars *game);
int ft_check_with(game_cars *game);
int check_map(game_cars *game);
void ft_close(game_cars *game);
void set_textures(game_cars *game);
void print_map(game_cars *game);
int controls_car(struct mlx_key_data key_data, void *param);
int	check_map_solvable(game_cars *game);
void check_items(game_cars *game);