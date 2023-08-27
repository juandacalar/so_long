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

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long [map.ber]\n", 2);
		return (1);
	}
	if (!ft_strendswith(argv[i], ".ber"))
	{
		ft_putstr_fd("Error, Invalid map file.Must be a .ber extension. \n", 2);
		return (1);
	}
	ft_putstr_fd("Map is valid. Starting the game... \n", 1);
	return (0);
}
