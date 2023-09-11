/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezongo <mpezongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 21:45:37 by mpezongo          #+#    #+#             */
/*   Updated: 2022/10/27 22:30:27 by mpezongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_and_put_bonus(int fd, char *str)
{
	int		ret;
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	ret = 1;
	while (!ft_strchr(str, '\n') && ret)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (0);
		}
		buf[ret] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
		{
			free(buf);
			return (0);
		}
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[10240];
	char		*new_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str[fd] = ft_read_and_put_bonus(fd, str[fd]);
	if (!str[fd])
		return (0);
	new_line = ft_get_print_line_bonus(str[fd]);
	str[fd] = ft_rest_line_bonus(str[fd]);
	return (new_line);
}
