/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 07:24:47 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/11 22:38:44 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_msg(char	*msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	free_map_exit(char **map, char *msg)
{
	int	i;

	i = 0;
	while (map[i ++])
		free(map[i]);
	free(map);
	exit_msg(msg);
}

int	close_window(void)
{
	exit(0);
	return (0);
}
