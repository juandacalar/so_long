#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h> // For Minilibs Functions
# include <stdlib.h> // Malloc, free
# include <unistd.h> // read, write
# include <fcntl.h> // Open, close
# include "libft.h" 

//struct to represent the game state
typedef struct s_game
{
    int player_x;
    int player_y;
    int collectibles_count;
}   t_game;

//From read_map.c
int parse_map(const char *filename);

// From validate_map.c

int is_rectangular(char **map);
int validate_map_content(char **map);
int is_surrounded_by_walls(char **map);

//From rendering.c
void    render_map(t_game *game);

//from game_logic.c
void    move_player(t_game *game, int direction);
int has_won(t_game *game);

//Utils 
int ft_strendswith(const char *str, const char *suffix);

#endif