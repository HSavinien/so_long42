/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:50:50 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/08 18:04:15 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void	show(char	*line)
{
	int	i = 0;

	while (line[i])
		printf("%d | ", (int)(line[i ++]));
	printf("\n");
}

int	main()
{
	char	*line;
	int		fd;

	fd = open("../../map/minimalist.ber", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		show(line);
		free(line);
		line = get_next_line(fd);
	}
	show("�1111111111");
}
