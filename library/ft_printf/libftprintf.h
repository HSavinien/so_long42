/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 00:21:49 by tmongell          #+#    #+#             */
/*   Updated: 2022/05/19 00:21:58 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

//main functions
int		ft_handle_format(char form, va_list ap);
int		ft_printf(const char *str, ...);
//format functions
int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printptr(void *ptr);
int		ft_printnbr(long int nb);
int		ft_printbase(long unsigned int nb, char *base);
//subfunction (used by the others)
size_t	ft_strlen(const char *s);
#endif
