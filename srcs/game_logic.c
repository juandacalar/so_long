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

static int  is_valid_position(t_game *game, int x, int y)
{
    if (x < 0 || x >= game->map_width || y < 0 || y >= game->map_height)
        return (0);
    if (game->map[y][x] == '1')
        return (0);
    return (1);
}

static void handle_collectible(t_game *game, int new_x, int new_y)
{
    game->collectibles_count--;
    game->map[new_y][new_x] = '0';
}

static int  handle_exit(t_game *game)
{
    return (game->collectibles_count == 0);
}

void    move_player(t_game *game, int direction)
{
    int new_x;
    int new_y;

    new_x = game->player_x;
    new_y = game->player_y;
    direction_logic(&new_x, &new_y, direction); // Assuming this is another function
    if (!is_valid_position(game, new_x, new_y))
        return ;
    if (game->map[new_y][new_x] == 'C')
        handle_collectible(game, new_x, new_y);
    if (game->map[new_y][new_x] == 'E' && handle_exit(game))
    {
        mlx_string_put(game->mlx, game->win, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0xFFFFFF, "You Win!");
        return ;
    }
    game->map[game->player_y][game->player_x] = '0';
    game->player_x = new_x;
    game->player_y = new_y;
    game->map[new_y][new_x] = 'P';
    game->move_count++;
    render_map(game);
}

int has_won(t_game *game)
{
    return (game->collectibles_count == 0);
}

