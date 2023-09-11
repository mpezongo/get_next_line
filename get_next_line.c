/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezongo <mpezongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 20:16:52 by mpezongo          #+#    #+#             */
/*   Updated: 2022/11/05 12:35:10 by mpezongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_and_put(int fd, char *str)
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
	static char	*str;
	char		*new_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	str = ft_read_and_put(fd, str);
	if (!str)
		return (0);
	new_line = ft_get_print_line(str);
	str = ft_rest_line(str);
	return (new_line);
}
