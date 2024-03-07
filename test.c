// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

// Written by Bruh

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "MLX42/include/MLX42/MLX42.h"
#define WIDTH 448
#define HEIGHT 288
#include <string.h>


static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

	mlx_image_t* player;
	mlx_image_t* food;
	mlx_texture_t* texture1;
	mlx_texture_t* texture2;
	mlx_t* mlx;
	int r = 0;
	int d = 0;
	int l = 0;
void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		if(player->instances[0].y > 32)
		{
			int a =player->instances[0].x;
			int b = player->instances[0].y;
			if(d == 0)
			{
				mlx_delete_texture(texture1);
				mlx_delete_image(mlx, player);
				texture1 = mlx_load_png("./temp/player_d.png");
				player = mlx_texture_to_image(mlx, texture1);
				
				if (mlx_image_to_window(mlx, player, a,b) < 0)
       			 error();
				r  = 0;
				l =0;
				d = 1;
			}
			//printf("player y :%d\n",player->instances[0].y);
		player->instances[0].y -= 1;
		}
			
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		if(player->instances[0].y < (((HEIGHT/32)-2) * 32 )+ 2)
		{
			int a =player->instances[0].x;
			int b = player->instances[0].y;
			if(d == 0)
			{
				mlx_delete_texture(texture1);
				mlx_delete_image(mlx, player);
				texture1 = mlx_load_png("./temp/player_d.png");
				player = mlx_texture_to_image(mlx, texture1);
				
				if (mlx_image_to_window(mlx, player, a,b) < 0)
       			 error();
				r  = 0;
				l =0;
				d = 1;
			}
			//printf("player y :%d\n",player->instances[0].y);
		player->instances[0].y += 1;
		}
			
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		if(player->instances[0].x > -9 +32 )
		{
			int a =player->instances[0].x;
			int b = player->instances[0].y;
			if(r == 0)
			{
				mlx_delete_texture(texture1);
				mlx_delete_image(mlx, player);
				texture1 = mlx_load_png("./temp/player_l.png");
				player = mlx_texture_to_image(mlx, texture1);
				
				if (mlx_image_to_window(mlx, player, a,b) < 0)
       			 error();
				r  = 1;
				l =0;
				d = 0;
			}
			//printf("player :%d\n",player->instances[0].x);
			player->instances[0].x -= 1;

		}
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		if(player->instances[0].x < (WIDTH - 24) +32 )
		{
			int a =player->instances[0].x;
			int b = player->instances[0].y;
			if(l == 0)
			{
				mlx_delete_texture(texture1);
				mlx_delete_image(mlx, player);
				texture1 = mlx_load_png("./temp/player_r.png");
				player = mlx_texture_to_image(mlx, texture1);
				
				if (mlx_image_to_window(mlx, player, a,b) < 0)
       			 error();
				l  = 1;
				r = 0;
				d = 0;
			}
			//printf("player :%d\n",player->instances[0].x);
			
			player->instances[0].x += 1;
		}
	}
}

bool instances_touch(mlx_instance_t instance1, mlx_instance_t instance2, int32_t range) {
    // Check if the distance between the centers of the instances is less than or equal to the specified range
    int32_t dx = instance1.x - instance2.x;
    int32_t dy = instance1.y - instance2.y;
    int32_t distance_squared = dx * dx + dy * dy;
    int32_t range_squared = range * range;
    return distance_squared <= range_squared;
}

// Hook function to handle collision and deletion
void ft_eate(void *param) {
    mlx_t* mlx = (mlx_t*)param;
    if (mlx == NULL) {
        printf("Invalid parameter: mlx\n");
        return;
    }
    
    // Check if player and food instances are valid
    if (player != NULL && food != NULL) {
        for (int i = 0; i < player->count; i++) {
            for (int j = 0; j < food->count; j++) {
                if (instances_touch(player->instances[i], food->instances[j], 10)) {
                    // Adjust the range (10 in this case) as needed
                    // Delete the second image
					//printf("%p\n",food);
					if (texture2) {
						mlx_delete_texture(texture2);
						texture2 = NULL; // Reset pointer to NULL after freeing
					}
					if (food) {
						mlx_delete_image(mlx, food);
						food = NULL; // Reset pointer to NULL after freeing
					}
                    return; // No need to continue checking once overlap is found
                }
            }
        }
    }
}



// void ft_eate(void *param)
// {
// 	mlx_t* mlx = param;
// 	if(player == NULL || food == NULL)
// 	{
// 		printf("hhh");
// 	}
// 	if(player != NULL && food != NULL && player->instances[0].x == food->instances[0].x && player->instances[0].y == food->instances[0].y)
// 	{
// 		mlx_delete_texture(texture2);
// 				mlx_delete_image(mlx, food);
// 	}
// }

int32_t	main(void)
{
	// Start mlx
	mlx = mlx_init(WIDTH, HEIGHT, "Test", false);
	if (!mlx)
        error();



printf("%d\n", ((HEIGHT/32)-1) * 32);
	// Try to load the file
	mlx_texture_t* texture = mlx_load_png("./temp/wall.png");
	mlx_texture_t* walking = mlx_load_png("./temp/walking_path.png");
	texture2 = mlx_load_png("./temp/coffee.png");
	texture1 = mlx_load_png("./temp/player_d.png");

	if (!texture)
        error();
	if(!texture2)
		error();
	
	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	mlx_image_t* walking1 = mlx_texture_to_image(mlx, walking);
	player = mlx_texture_to_image(mlx, texture1);
	food = mlx_texture_to_image(mlx, texture2);
	if (!img)
        error();
	if(!food)
		error();

	
	int  i =0;
	int j = 0;
	while(j < HEIGHT)
	{
		i = 0;
		while(i < WIDTH)
		{
			if(i % 32 == 0 && j==0)
			{
			
				if (mlx_image_to_window(mlx, img, i, j) < 0)
			    	error();
			}
			else if(i % 32 == 0 && j== ((HEIGHT/32)-1) * 32)
			{
				if (mlx_image_to_window(mlx, img, i,j) < 0)
			    	error();
			}
			else if(i == 0 && j >= 32 && j % 32 == 0 &&  j <(((HEIGHT/32)-2) * 32 )+ 2)
			{
				if (mlx_image_to_window(mlx, img, i,j) < 0)
			    	error();
			}
			else if(j == 32 * 4 && (i == 32 *3 || i == 32 * 4))
			{
				if (mlx_image_to_window(mlx, img, i,j) < 0)
			    	error();
			}
			// else
			// {
			// 	if (mlx_image_to_window(mlx, walking1, i,j) < 0)
			//     	error();
			// }

			i++;
		}
		j++;
	}
	// i = 0;
	// while(i < 416)
	// {
	// 	if(i % 32 == 0)
	// 	{
	// 		if (mlx_image_to_window(mlx, img, i,((HEIGHT/32)-1) * 32) < 0)
	// 		    error();
	// 	}
	// 	i++;
	// }



	if (mlx_image_to_window(mlx, player, 100,100) < 0)
        error();
	if (mlx_image_to_window(mlx, food, 120,200) < 0)
        error();
printf("player :%d\n",food->instances[0].x);

mlx_loop_hook(mlx, ft_hook, mlx);

mlx_loop_hook(mlx, ft_eate, mlx);

	mlx_loop(mlx);


	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_delete_texture(texture1);
	// mlx_delete_texture(texture2);
	// 			mlx_delete_image(mlx, food);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}