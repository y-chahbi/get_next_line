/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:33:14 by ychahbi           #+#    #+#             */
/*   Updated: 2022/11/25 11:37:23 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	free_my_static(char **my_static)
{
	free(*my_static);
	*my_static = NULL;
}

static char	*file_r(int fd, char *my_static)
{
	char	*buf;
	char	*tmp;
	int		read_l;

	if (!my_static)
		my_static = ft_calloc(1, 1);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	read_l = 1;
	while (read_l && !ft_strchr(my_static, '\n'))
	{
		read_l = read(fd, buf, BUFFER_SIZE);
		if (read_l == -1)
			return (free_my_static(&buf), NULL);
		buf[read_l] = '\0';
		tmp = my_static;
		my_static = ft_strjoin(tmp, buf);
		free(tmp);
	}
	return (free_my_static(&buf), my_static);
}

static char	*line_g(char **my_static)
{
	char	*tmp;
	char	*str;
	int		i;
	int		j;

	if (ft_strlen(*my_static) && !ft_strchr (*my_static, '\n'))
	{
		tmp = ft_substr(*my_static, 0, ft_strlen(*my_static));
		return (free_my_static(my_static), tmp);
	}
	else if (ft_strchr (*my_static, '\n'))
	{
		i = ft_strlen(*my_static);
		j = ft_strlen(ft_strchr(*my_static, '\n'));
		tmp = ft_substr(*my_static, 0, i - j + 1);
		str = ft_substr(ft_strchr(*my_static, '\n'), 1, j + 1);
		free_my_static(my_static);
		*my_static = str;
		return (tmp);
	}
	free_my_static(my_static);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*my_static[10240];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	my_static[fd] = file_r(fd, my_static[fd]);
	if (!my_static[fd])
		return (NULL);
	line = line_g(&my_static[fd]);
	return (line);
}