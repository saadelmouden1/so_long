#include "so_long.h"

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void ft_close(game_cars *game)
{
     printf("%p\n",game);
    if(game->wall)
       mlx_delete_texture(game->wall);
    if(game->vid)
        mlx_delete_texture(game->vid);
    if(game->fd)
        mlx_delete_texture(game->fd);
    if(game->et)
        mlx_delete_texture(game->et);
    if(game->pl_up)
        mlx_delete_texture(game->pl_up);
    if(game->food)
        mlx_delete_image(game->mlx,game->food);
    if(game->wl)
        mlx_delete_image(game->mlx,game->wl);
    if(game->player_up)
        mlx_delete_image(game->mlx,game->player_up);
    if(game->vd)
        mlx_delete_image(game->mlx,game->vd);
    if(game->exit)
        mlx_delete_image(game->mlx,game->exit);
    int	line;

	line = 0;
   // free(game->mlx);
   
	while (line < game->map_height)
    {
        if(game->gamemap[line])
            free(game->gamemap[line++]);
    }
    
	if(game->gamemap)
        free(game->gamemap);
    
    if(game->mlx)
         mlx_terminate(game->mlx);
    exit(0);
}

static void	*ft_memset(void *b, int c, size_t length)
{
	unsigned char	*p;

	p = (unsigned char *)b;
	while (length--)
		*p++ = (unsigned char)c;
	return (b);
}


void set_textures1(game_cars *game)
{
    game->wall= mlx_load_png("./temp/wall.png");
    if(!game->wall)
            ft_close(game);
    game->wl = mlx_texture_to_image(game->mlx, game->wall);
    if(!game->wl)
            ft_close(game);
    game->vid= mlx_load_png("./temp/walking_path.png");
    if(!game->wall)
            ft_close(game);
    game->vd = mlx_texture_to_image(game->mlx, game->vid);
    if(!game->wl)
            ft_close(game);
    game->pl_up= mlx_load_png("./temp/player_d.png");
    if(!game->wall)
            ft_close(game);
}

void set_textures(game_cars *game)
{
   set_textures1(game);
    game->player_up = mlx_texture_to_image(game->mlx, game->pl_up);
    if(!game->wl)
            ft_close(game);
    game->fd= mlx_load_png("./temp/coffee.png");
    if(!game->wall)
            ft_close(game);
   game->food = mlx_texture_to_image(game->mlx, game->fd);
    if(!game->wl)
            ft_close(game);
    game->et= mlx_load_png("./temp/exit.png");
    if(!game->et)
            ft_close(game);
    game->exit = mlx_texture_to_image(game->mlx, game->et);
    if(!game->exit)
            ft_close(game);
}
void print_map(game_cars *game)
{
  

    int i = 0;
    int j =0;
    
    while(game->gamemap[i]!= NULL)
    {
        j = 0;
        while(game->gamemap[i][j] !='\0')
        {
            if(game->gamemap[i][j] == '1')
            {
                if (mlx_image_to_window(game->mlx, game->wl, j*32,i*32) < 0)
   	    	        ft_close(game);
            }
            if(game->gamemap[i][j] == '0')
            {
                if (mlx_image_to_window(game->mlx, game->vd, j*32,i*32) < 0)
   	    	        ft_close(game);    
            }
            if(game->gamemap[i][j] == 'P')
            {
                if (mlx_image_to_window(game->mlx, game->vd, j*32,i*32) < 0)
   	    	        ft_close(game); 
                if(game->x_e == j && game->y_e == i)
                    if (mlx_image_to_window(game->mlx, game->exit, j*32,i*32) < 0)
   	    	        ft_close(game); 
                if (mlx_image_to_window(game->mlx, game->player_up, j*32,i*32) < 0)
   	    	        ft_close(game);   
                game->x_player = j; 
                game->y_player = i;
                // printf("g\n");
            }
            if(game->gamemap[i][j] == 'C')
            {

                if (mlx_image_to_window(game->mlx, game->vd, j*32,i*32) < 0)
   	    	        ft_close(game); 
                if (mlx_image_to_window(game->mlx, game->food, j*32,i*32) < 0)
   	    	        ft_close(game); 
                if(game->isfirst == 0)   
                    game->collectible++;
            }
            if(game->gamemap[i][j] == 'E')
            {

                if (mlx_image_to_window(game->mlx, game->vd, j*32,i*32) < 0)
   	    	        ft_close(game); 
                if (mlx_image_to_window(game->mlx, game->exit, j*32,i*32) < 0)
   	    	        ft_close(game);   
                if(game->isfirst == 0)   
                {
                    game->x_e = j;
                    game->y_e = i;
                } 
            }
            j++;
        }
        
        i++;
    }
    game->isfirst = 1;
    
}



int controls_car(struct mlx_key_data key_data, void *param)
{
     game_cars *game = (game_cars *)param;
    int works;
    works  = 0;
    if(mlx_is_key_down(game->mlx, MLX_KEY_UP))
      works = move_u_d(key_data,game);
    if(mlx_is_key_down(game->mlx, MLX_KEY_DOWN))
      works = move_u_d(key_data,game);
    if(mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
      works = move_l_r(key_data,game);
    if(mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
      works = move_l_r(key_data,game);
    if(mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
     {
        ft_close(game);
        exit(0);
     }
    if(works == 1)
    {
        print_map(game);
        printf("%d\n",game->counter);
    }
   return (1);
}

void get_pos_player(game_cars *game)
{
     int i = 0;
    int j = 0;
    while(game->gamemap[i]!= NULL)
    {
        j = 0;
        while(game->gamemap[i][j] !='\0')
        {
            if(game->gamemap[i][j] == 'P')
            {
                game->x_player = j;
                game->y_player = i;
            }
            j++;
        }
        i++;
    }
}

 void fc(void){
    system("leaks a.out");
}

int main(int ac, char **av)
{
   atexit(fc);

    game_cars game;
  ft_memset(&game,0,sizeof(game_cars));
   get_map(&game,av);
     get_with(&game);
       get_pos_player(&game);
   if(check_map(&game) == 0)
        exit(0);
    check_items(&game);
    if(check_map_solvable(&game) == 0)
    {
        printf("bba\n");
        exit(0);
        //ft_close(&game);
    }
      game.mlx = mlx_init((game.map_width * 32),game.map_height*32, "so_long", true);
    if(!game.mlx)
        ft_close(&game);
     set_textures(&game);
      print_map(&game);
   mlx_key_hook(game.mlx, (mlx_keyfunc)controls_car, &game);
    mlx_loop(game.mlx);
    ft_close(&game);
    
    return(0);
      
    
}