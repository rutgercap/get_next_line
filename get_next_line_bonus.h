/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.h                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 10:39:19 by rcappend      #+#    #+#                 */
/*   Updated: 2020/11/30 12:19:33 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

# define MAX_FD 1024

typedef enum
{
	FALSE,
	TRUE
}	t_bool;

size_t	ft_strclen(const char *str, int c);

char	*ft_strchr(const char *s, int c);

char	*ft_memccpy(char *dst, const char *src, int c);

void	ft_memmove(char *dst, const char *src);

int		get_next_line(int fd, char **line);

#endif
