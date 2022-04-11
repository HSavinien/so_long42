/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:30:59 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/08 22:10:13 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void	display_map(t_map	*map)
{
	int	i;

	i = 0;
	while (map->grid[i])
	{
		printf("%d	> %s", i + 1, map->grid[i]);
		i ++;
	}
	printf("exiting loop\n");//=================================================debug
	printf("map dimensions are %d * %d\n", map->nb_tiles_x, map->nb_tiles_y);
	printf("found :\n \t- %d collectibles;\n\t- %d exit;\n\t- %d players;\n\t- "
		"%d enemy\n", map->nb_colectible, map->nb_exit, map->nb_player,
		map->nb_enemy);
}
