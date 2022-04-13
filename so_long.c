/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:52:03 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/12 19:42:39 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_mlx	*mlx;

	if (ac != 2)
		return (ft_printf("arguments error\nusage : %s <map.ber>\n", av[0]));
	map = parsing(av[1]);
	mlx = init_window(map);
	print_map_shell(map);
	print_map(mlx, map);
	mlx_hook(mlx->win, 17, 0, close_window, 0);
	mlx_key_hook(mlx->win, keyboard_event, mlx);
	mlx_loop(mlx->serv);
}
