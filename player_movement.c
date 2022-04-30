/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:33:27 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/30 19:51:51 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	find_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			if (map->grid[i][j] == 'P')
			{
				map->p_posx = j;
				map->p_posy = i;
				return (1);
			}
			j ++;
		}
		i ++;
	}
	return (0);
}

static void	update_map(t_map *map, t_mlx *mlx, int dst_x, int dst_y)
{
	map->grid[dst_y][dst_x] = 'P';
	map->grid[map->p_posy][map->p_posx] = '0';
	map->p_posx = dst_x;
	map->p_posy = dst_y;
	mlx->nb_moves ++;
}

void	show_nb_moves(int nb_moves, t_mlx *mlx)
{
	char	*nb_moves_str;

	nb_moves_str = ft_itoa(nb_moves);
	mlx_string_put(mlx->serv, mlx->win, 40, 30, 12779520, nb_moves_str);
	free(nb_moves_str);
}

int	player_moveto(int dst_x, int dst_y, t_mlx *mlx, t_map *map)
{
	if (map->grid[dst_y][dst_x] == 'K')
		return (game_over(mlx));
	else if (map->grid[dst_y][dst_x] == '1')
		return (0);
	else if (map->grid[dst_y][dst_x] == 'E')
	{
		if (map->nb_colectible > 0)
			return (1);
		else
			return (winning(mlx));
	}
	else if (map->grid[dst_y][dst_x] == 'C')
		map->nb_colectible --;
	update_map(map, mlx, dst_x, dst_y);
	move_enemy(map);
	print_map_shell(map);
	ft_printf("you did %d moves\n", mlx->nb_moves);
	return (mlx->nb_moves);
}
