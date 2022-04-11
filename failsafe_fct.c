/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failsafe_fct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 18:34:06 by tmongell          #+#    #+#             */
/*   Updated: 2022/04/08 21:43:52 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* this file exist for one reason : for some reason, my gnl may return weird 
 * value in parsing. if other function need failsafing, I'll add them too */

char	*fs_get_next_line(int fd)
{
	char	*line;
	char	*fs_line;
	int		i;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	i = 0;
	while (line[i] < '\0')
		i ++;
	fs_line = ft_strdup(line + i);
	free (line);
	return (fs_line);
}
