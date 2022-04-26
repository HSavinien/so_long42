/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:23:39 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/26 17:17:27 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_limit_line(char *line)
//check that the first and last line of the map are just a sery of 1
{
	int	i;

	i = 0;
	line = handle_eol(line);
	while (line[i] == '1')
		i ++;
	if (line[i] != '\n')
	{
		free (line);
		exit_msg("error : map must be closed");
	}
	return (i);
}

char	*checkline(char	*line, t_map *map)
{
	int	i;

	line = handle_eol(line);
	if (ft_strlen(line) - 1 != (size_t) map->nb_tiles_x)
		return ("error : map must be rectangular");
	if (line[0] != '1' || line[map->nb_tiles_x - 1] != '1')
		return ("error : map must be closed");
	i = 0;
	while (line[i ++])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == '\n' || !line[i])
			(void) line;
		else if (line[i] == 'P')
			map->nb_player ++;
		else if (line[i] == 'C')
			map->nb_colectible ++;
		else if (line[i] == 'E')
			map->nb_exit ++;
		else if (line[i] == 'K')
			map->nb_enemy ++;
		else
			return ("error : map contain unknown characters");
	}
	return (NULL);
}

void	fill_map(int map_fd, t_map *map)
{
	int		i;
	char	*line;
	char	*er_msg;

	line = map->grid[0];
	i = 0;
	while (line)
	{
		er_msg = checkline(line, map);
		if (er_msg)
			free_map_exit(map->grid, er_msg);
		map->grid[i] = line;
		line = get_next_line(map_fd);
		i ++;
	}
}

void	check_object(t_map *map)
{
	if (map->nb_tiles_x < 3 || map->nb_tiles_y < 3)
		free_map_exit(map->grid, "error : map is too small");
	if (map->nb_colectible < 1)
		free_map_exit(map->grid, "error : no collectibles found");
	if (map->nb_exit < 1)
		free_map_exit(map->grid, "without an exit, game will be hard to solve");
	if (map->nb_player < 1)
		free_map_exit(map->grid, "this is not an idle game. you need a player");
	if (map->nb_player > 1)
		free_map_exit(map->grid, "warning : multiplayer is not available yet");
}

t_map	*parsing(char *map_name)
{
	t_map	*map;
	int		map_fd;
	char	*line;

	map = map_init();
	line = NULL;
	check_map_name(map_name);
	map->nb_tiles_y = count_line(map_name);
	if (!map->nb_tiles_y)
		exit_msg("error : map is empty");
	map->grid = ft_calloc(sizeof(char *), map->nb_tiles_y + 1000);
	if (!map->grid)
		exit_msg("error : memory allocation failed");
	map_fd = open(map_name, O_RDONLY, O_CLOEXEC);
	if (map_fd < 0 || errno == 21)
		exit_msg("error : could not open file");
	line = get_next_line(map_fd);
	map->nb_tiles_x = check_limit_line(line);
	map->grid[0] = line;
	fill_map(map_fd, map);
	check_object(map);
	check_limit_line(map->grid[map->nb_tiles_y - 1]);
	close(map_fd);
	find_player(map);
	printf("\n\n");//================debug
	return (map);
}
