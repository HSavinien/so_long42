/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formating.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmongell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:58:38 by tmongell          #+#    #+#             */
/*   Updated: 2022/03/19 19:33:40 by tmongell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//this library only contain macro, useful to display formated text on console

#ifndef FORMATING_H

//utilities

# define STRINGIZE(x) STRINGIZE_BIS(x)
# define STRINGIZE_BIS(x) #x
//basics

# define ESC_CHAR ""
# define CLEAR "[0m"
// format

# define BOLD "[1m"
# define ITALIC "[3m"
# define UNDERLINE "[4m"
# define REDACTED "[9m"
//colors

# define RED "[31m"
# define GREEN "[32m"
# define BLUE "[34m"
# define YELLOW "[33m"
# define MAGENTA "[35m"
# define CYAN "[36m"
# define BLACK "[30m"
# define WHITE "[37m"
//useful strings

# define LINE_NB STRINGIZE(__LINE__)
# define DEBUG "debug("__FILE__":"LINE_NB"l) : "

#endif
