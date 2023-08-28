/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:35:29 by jucalder          #+#    #+#             */
/*   Updated: 2023/08/27 16:41:45 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    // Check for correct number of arguments (if required by your game)
    if (argc != 2)
    {
        ft_putstr_fd("Usage: ./so_long <map_file>\n", 2);
        return (1);
    }

    // Initialize the game state
    ft_bzero(&game, sizeof(t_game));  // Use this if you have the bzero function in your libft

    // Read and validate the map
    if (!read_map(argv[1], &game) || !validate_map_content(game.map) || !is_surrounded_by_walls(game.map))
    {
        ft_putstr_fd("Error: Invalid map.\n", 2);
        return (1);
    }

    // Initialize MLX and create window
    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "So Long");

    // Load textures
    load_textures(&game);

    // Register key press handler
    mlx_key_hook(game.win, handle_keypress, &game);

    // Enter the main loop
    mlx_loop(game.mlx);

    return (0);
}