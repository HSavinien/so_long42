/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 19:14:41 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/18 22:26:46 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_handlesign(long int *nb)
{
	if (*nb < 0)
	{
		write(1, "-", 1);
		*nb *= -1;
		return (1);
	}
	return (0);
}

int	ft_printnbr(long int nb)
{
	int	retval;

	retval = 0;
	retval += ft_handlesign(&nb);
	retval += ft_printbase(nb, "0123456789");
	return (retval);
}
