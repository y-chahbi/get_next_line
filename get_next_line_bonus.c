/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:33:14 by ychahbi           #+#    #+#             */
/*   Updated: 2022/11/23 13:41:23 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	free_f(char **my_static)
{
	free(*my_static);
	*my_static = NULL;
}

static char	*file_r(int fd, char *my_static)
{
	char	*buf;
	char	*tmp;
	int		c;

	if (!my_static)
		my_static = ft_calloc(1, 1);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return (NULL);
	c = 1;
	while (c && !ft_strchr(my_static, '\n'))
	{
		c = read(fd, buf, BUFFER_SIZE);
		if (c == -1)
		{
			free_f(&buf);
			return (NULL);
		}
		buf[c] = '\0';
		tmp = my_static;
		my_static = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free_f(&buf);
	return (my_static);
}

static char	*line_g(char **my_static)
{
	char	*temp;
	char	*str;
	int		i;
	int		j;

	if (ft_strlen(*my_static) && !ft_strchr (*my_static, '\n'))
	{
		temp = ft_substr(*my_static, 0, ft_strlen(*my_static));
		free_f(my_static);
		return (temp);
	}
	else if (ft_strchr (*my_static, '\n'))
	{
		i = ft_strlen(*my_static);
		j = ft_strlen(ft_strchr(*my_static, '\n'));
		temp = ft_substr(*my_static, 0, i - j + 1);
		str = ft_substr(ft_strchr(*my_static, '\n'), 1, j + 1);
		free_f(my_static);
		*my_static = str;
		return (temp);
	}
	free_f(my_static);
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

// int main()
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	//while(1){
// 		printf("%s",get_next_line(fd));
// 		printf("%s",get_next_line(fd));
// 		printf("%s",get_next_line(fd));
// 		printf("%s",get_next_line(fd));
// 		printf("%s",get_next_line(fd));
// 		printf("%s",get_next_line(fd));
// 		printf("%s",get_next_line(fd));
// }
