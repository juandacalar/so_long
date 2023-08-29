/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jucalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 16:35:29 by jucalder          #+#    #+#             */
/*   Updated: 2023/08/29 19:26:01 by jucalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines_in_file(int fd)
{
	char	*line;
	int		count;

	count = 0;
	while (get_next_line(fd, &line) > 0)
	{
		free(line);
		count++;
	}
	lseek(fd, 0, SEEK_SET);
	return (count);
}

int	read_map(const char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	**map;
	int		map_height;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	map_height = count_lines_in_file(fd);
	map = (char **)malloc(sizeof(char *) * (map_height + 1));
	if (!map)
		return (-1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	close(fd);
	if (!is_rectangular(map) || !validate_map_content(map) \
			|| !is_surrounded_by_walls(map))
	{
		free_map(map);
		return (-1);
	}
	init_game_state(game, map);
	return (0);
}
//In the first while loops i Free the line after counting
//With lseek  Reset file descriptor to the start of the file for further reading
// On read_map I open the file and if there are none
// shows and error, that is unable to open the file
// i calculate the hegiht of the map based on number of lines in the file
// Then allocate memory for the map and did error handling
// Then i read and store each line into the map and 
// null terminate the array for easier handling later
// then i close the file 
// then a conditional to validate the map content and structure
// i did a free_map function to free the 2d array with free_map
// to check error invalidad map structuture
// then i initialize the game state 
// todo: keep the map in memory for rendering alter o read it again as needed 
// then return sucessful loading and validation for the map
