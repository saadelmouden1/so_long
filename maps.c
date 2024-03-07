#include "so_long.h"

int get_height_map(int fd)
{
    
    int i = 0;
    char *a;
    while((a = get_next_line(fd))!= NULL)
    {
        free(a);
        i++;
    }
    return i;
}

void get_map(game_cars *game, char **av)
{
  
     int fd = open(av[1],O_RDONLY);
    int mp_height = get_height_map(fd);
    printf("%d\n",mp_height);
    close(fd);
   
    game->gamemap = (char **)malloc((mp_height + 1) *sizeof(char *));
    int i =0;
    int fd1  =open(av[1],O_RDONLY);
    while((game->gamemap[i] = get_next_line(fd1))!=NULL)
        i++;
    close(fd1);
    game->gamemap[i] = NULL;

    printf("ln : %s\n",game->gamemap[0]);
         

    game->map_height = mp_height;
   
}
void get_with(game_cars *game)
{
     int i = 0;
     while(game->gamemap[0][i]!='\0')
     {
        i++;
     }
     game->map_width = i;
}