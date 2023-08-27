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

int is_rectangular(char **map)
{
    int length;
    int i;

    if(!map || !*map)
        return (0); //invalid map
    length = ft_strlen(map[0]);
    i = 1;
    while (map[i])
    {
        if (ft_strlen(map[i]) != length)
        return (0); // different length found
        i++;
    }
    return (1);
}

static int validate_characters(char **map, int *player_count,
                                int *exit_count, int *collectibles_count)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'P') (*player_count)++;
            else if (map[i][j] == 'E') (*exit_count)++;
            else if (map[i][j] == 'C') (*collectibles_count)++;
            else if (map[i][j] != '0' && map[i][j] != '1')
                return (0); // Invalid character found
            j++;
        }
        i++;
    }
    return (1);
}

int validate_map_content(char **map)
{
    int player_count;
    int exit_count;
    int collectibles_count;

    player_count = 0;
    exit_count = 0;
    collectibles_count = 0;
    if (!validate_characters(map, &player_count, &exit_count, &collectibles_count))
        return (0);
    if (player_count != 1 || exit_count != 1 || collectibles_count < 1)
        return (0); // Invalid counts of P, E, or C
    return (1);
}

int is_surrounded_by_walls(char **map)
{
    int i, j;

    // Check top and bottom borders
    j = 0;
    while (map[0][j] && map[ft_strlen_arr(map) - 1][j])
    {
        if (map[0][j] != '1' || map[ft_strlen_arr(map) - 1][j] != '1')
            return (0);
        j++;
    }

    // Check left and right borders
    i = 0;
    while (map[i])
    {
        if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
            return (0);
        i++;
    }

    return (1);
}
