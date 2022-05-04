/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:02:51 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/04 19:07:45 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_direction(int key, int *dst_x, int *dst_y, t_map *map)
{
	if (key == KEY_W || key == KEY_ARROW_UP)
	{
		*dst_x = (map->p_posx);
		*dst_y = (map->p_posy) - 1;
		return (1);
	}
	if (key == KEY_A || key == KEY_ARROW_LEFT)
	{
		*dst_x = map->p_posx - 1;
		*dst_y = map->p_posy;
		return (2);
	}
	if (key == KEY_S || key == KEY_ARROW_DOWN)
	{
		*dst_x = map->p_posx;
		*dst_y = map->p_posy + 1;
		return (3);
	}
	if (key == KEY_D || key == KEY_ARROW_RIGHT)
	{
		*dst_x = map->p_posx + 1;
		*dst_y = map->p_posy;
		return (4);
	}
	return (0);
}

int	keyboard_event(int key, t_mlx *mlx)
{
	int	dst_x;
	int	dst_y;

	if (key == KEY_ESC)
		return (close_window());
	else if (check_direction(key, &dst_x, &dst_y, mlx->map))
	{
		player_moveto(dst_x, dst_y, mlx, mlx->map);
	}
	else
		return (0);
	return (0);
}

int	end_of_game(int key, t_mlx *mlx)
{
	if (key == KEY_ESC || key == KEY_Q)
		return (close_window());
	(void) mlx;
	return (0);
}
