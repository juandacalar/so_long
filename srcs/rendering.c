/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:35:29 by jucalder          #+#    #+#             */
/*   Updated: 2023/08/29 19:38:46 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error: Failed to initialize MLX.\n", 2);
		exit(EXIT_FAILURE);
	}
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "So Long");
	if (!game->win)
	{
		ft_putstr_fd("Error: Failed to create a new window.\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	load_textures(t_game *game)
{
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "path_to_wall_texture.xpm", \
			&game->tile_width, &game->tile_height);
	if (!game->wall_img)
	{
		ft_putstr_fd("Error: Failed to load wall texture.\n", 2);
		exit(EXIT_FAILURE);
	}
	game->player_img = mlx_xpm_file_to_image \
			   (game->mlx, "path_to_player_texture.xpm", &game->tile_width, &game->tile_height);
	if (!game->player_img)
	{
		ft_putstr_fd("Error: Failed to load player texture.\n", 2);
		exit(EXIT_FAILURE);
	}
	game->exit_img = mlx_xpm_file_to_image(game->mlx, \
			"path_to_exit_texture.xpm", &game->tile_width, &game->tile_height);
	if (!game->exit_img)
	{
		ft_putstr_fd("Error: Failed to load exit texture.\n", 2);
		exit(EXIT_FAILURE);
	}
	game->collectible_img = mlx_xpm_file_to_image \
				(game->mlx, "path_to_collectible_texture.xpm", &game->tile_width, &game->tile_height);
	if (!game->collectible_img)
	{
		ft_putstr_fd("Error: Failed to load collectible texture.\n", 2);
		exit(EXIT_FAILURE);
	}
}

static void	*get_tile_image(char tile, t_game *game)
{
	if (tile == '1')
		return (game->wall_img);
	if (tile == 'P')
		return (game->player_img);
	if (tile == 'E')
		return (game->exit_img);
	if (tile == 'C')
		return (game->collectible_img);
	return (NULL);
}

void	draw_map(t_game *game)
{
	int		x;
	int		y;
	void	*current_img;

	y = -1;
	while (++y < game->map_height)
	{
		x = -1;
		while (++x < game->map_width)
		{
			current_img = get_tile_image(game->map[y][x], game);
			if (current_img)
				mlx_put_image_to_window(game->mlx, game->win,\
						current_img, x * game->tile_width,\
						y * game->tile_height);
		}
	}
}

void	render_map(t_game *game)
{
	char	*message;

	initialize_window(game);
	load_textures(game);
	draw_map(game);
	message = ft_strjoin("Moves: ", ft_itoa(game->move_count));
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, message);
	free(message);
}
