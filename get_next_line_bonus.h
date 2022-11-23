/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ychahbi <ychahbi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:33:20 by ychahbi           #+#    #+#             */
/*   Updated: 2022/11/23 13:35:43 by ychahbi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlen(const char *s);

void	*ft_calloc(size_t count, size_t size);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strchr(const char *s, int c);

char	*get_next_line(int fd);

#endif