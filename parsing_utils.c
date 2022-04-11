/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:02:56 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/11 22:15:59 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char	*file)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_msg("error : could not open file");
	line = get_next_line(fd);
	i = 0;
	while (line && *line != '\n')
	{
		i ++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (i);
}

void	check_map_name(char	*name)
//check that the map name is a non-empty string folowed by .ber
{
	char	*cut_name;

	cut_name = ft_strrchr(name, '/') + 1;
	if (cut_name - 1)
		name = cut_name;
	if (ft_strlen(name) <= 4)
		exit_msg("error : empty map name");
	if (ft_strncmp(".ber", name + ft_strlen(name) - 4, 5))
		exit_msg("error : invalid map filename : .ber extention only");
}

t_map	*map_init(void)
{
	t_map	*map;

	map = malloc(sizeof (t_map));
	map->nb_tiles_x = 1;
	map->nb_tiles_y = 1;
	map->nb_colectible = 0;
	map->nb_exit = 0;
	map->nb_enemy = 0;
	map->nb_player = 0;
	return (map);
}
