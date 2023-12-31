/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:35:29 by jucalder          #+#    #+#             */
/*   Updated: 2023/08/29 18:53:32 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, UP);
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, LEFT);
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, DOWN);
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, RIGHT);
	return (0);
}
