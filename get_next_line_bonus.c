/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcappend <rcappend@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/30 10:26:46 by rcappend      #+#    #+#                 */
/*   Updated: 2020/11/30 13:03:12 by rcappend      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ret_check(int ret, char **line)
{
	if (ret == -1)
	{
		free(*line);
		return (ret);
	}
	return (ret);
}

int	ft_strjoin(char **line, char *buff)
{
	char	*new;
	char	*index;
	int		newl;

	if (ft_strclen(buff, 0) == 0)
		return (0);
	new = (char *)malloc(ft_strclen(buff, '\n') + ft_strclen(*line, 0) + 1);
	if (!new)
		return (-1);
	index = ft_memccpy(new, *line, 0);
	index = ft_memccpy(index, buff, '\n');
	free(*line);
	*line = new;
	newl = ft_strchr(buff, '\n') == NULL ? 0 : 1;
	ft_memmove(buff, index);
	return (newl);
}

int	get_next_line(int fd, char **line)
{
	static char		buff[MAX_FD][BUFFER_SIZE + 1];
	int				bytes;
	int				ret;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0 || !line)
		return (-1);
	*line = (char *)malloc(1);
	if (!*line)
		return (-1);
	*line[0] = '\0';
	ret = ft_strjoin(line, buff[fd]);
	if (ret)
		return (ret_check(ret, line));
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buff[fd], BUFFER_SIZE);
		if (bytes == -1)
			return (-1);
		ret = ft_strjoin(line, buff[fd]);
		if (ret)
			return (ret_check(ret, line));
	}
	return (0);
}
