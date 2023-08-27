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

int count_lines_in_file(int fd)
{
    char    *line;
    int     count;

    count = 0;
    while (get_next_line(fd, &line) > 0)
    {
        free(line); // free the line after counting
        count++;
    }
    // Reset file descriptor to the start of the file for further reading
    lseek(fd, 0, SEEK_SET);

    return (count);
}

int read_map(const char *filename, t_game *game)
{
    int     fd;
    char    *line;
    char    **map;
    int     map_height;
    int     i;

    // Open the file
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1); // Error: Unable to open the file

    // Calculate the height of the map (number of lines in the file)
    map_height = count_lines_in_file(fd);

    // Allocate memory for the map
    map = (char **)malloc(sizeof(char *) * (map_height + 1));
    if (!map)
        return (-1); // Error: Memory allocation failed

    // Read and store each line into the map
    i = 0;
    while (get_next_line(fd, &line) > 0)
    {
        map[i] = line;
        i++;
    }
    map[i] = NULL; // Null terminate the array for easier handling later

    // Close the file
    close(fd);

    // Validate the map content and structure
    if (!is_rectangular(map) || !validate_map_content(map) || !is_surrounded_by_walls(map))
    {
        free_map(map); // You might want a function to free the 2D array
        return (-1);   // Error: Invalid map structure or content
    }

    // Initialize the game state (e.g., player position)
    init_game_state(game, map);

    // TODO: keep the map in memory for rendering later, or read it again as needed.

    return (0); // Successful loading and validation of map
}