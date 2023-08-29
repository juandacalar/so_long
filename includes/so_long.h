#ifndef SO_LONG_H
# define SO_LONG_H

// Constants for window dimensions
#ifndef WINDOW_WIDTH
# define WINDOW_WIDTH 800
#endif

#ifndef WINDOW_HEIGHT
# define WINDOW_HEIGHT 600
#endif

# include <mlx.h> // For Minilibs Functions
# include <stdlib.h> // Malloc, free
# include <unistd.h> // read, write
# include <fcntl.h> // Open, close
# include "libft.h"

// Key Codes for movement
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_UP 65362
# define KEY_DOWN 65364

// Movement Directions
# define LEFT 1
# define RIGHT 2
# define UP 3
# define DOWN 4

//struct to represent the game state
typedef struct s_game
{
    int player_x;
    int player_y;
    int collectibles_count;
     int map_height;
    int map_width;
    char **map;
    // Rendering-specific data
    void *mlx;          // MLX reference
    void *win;          // Window reference
    void *wall_img;     // Texture for walls
    void *player_img;
    void *exit_img;
    void *collectible_img;
    // ... (Add other textures as needed)
    int tile_width;     // Width of a tile (based on texture)
    int tile_height;    // Height of a tile (based on texture)
    // Count player moves
	int move_count;
}   t_game;

//From read_map.c
int read_map(const char *filename, t_game *game);
int	count_lines_in_file(int fd);

// From validate_map.c

int is_rectangular(char **map);
int validate_map_content(char **map);
int is_surrounded_by_walls(char **map);

//From rendering.c
void    render_map(t_game *game);
void	load_textures(t_game *game);
void	draw_map(t_game *game);

//from game_logic.c
void    move_player(t_game *game, int direction);
int has_won(t_game *game);


//Utils 
int ft_strendswith(const char *str, const char *suffix);

//From input.c or events.c
int handle_keypress(int keycode, t_game *game);

//not yet sure about this last one
void direction_logic(int *new_x, int *new_y, char direction);


#endif
