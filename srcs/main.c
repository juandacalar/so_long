/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:35:29 by jucalder          #+#    #+#             */
/*   Updated: 2023/08/29 18:59:22 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long <map_file>\n", 2);
		return (1);
	}
	ft_bzero(&game, sizeof(t_game));
	if (!read_map(argv[1], &game) || !validate_map_content(game.map) \
			|| !is_surrounded_by_walls(game.map))
	{
		ft_putstr_fd("Error: Invalid map.\n", 2);
		return (1);
	}
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "So Long");
	load_textures(&game);
	mlx_key_hook(game.win, handle_keypress, &game);
	mlx_loop(game.mlx);
	return (0);
}
// Check for correct number of arguments with ft_putstr
// Initialize the game state with ft_bzero 
// Initialize MLX and create window
// Load_textures
// register key press handler
// Enter main loop
