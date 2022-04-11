/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:52:03 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/11 22:25:28 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac != 2)
		return (ft_printf("arguments error\nusage : %s <map.ber>\n", av[0]));
	map = parsing(av[1]);
	display_map_color(map);
	manage_window(map);
}
