/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezongo <mpezongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:12:54 by mpezongo          #+#    #+#             */
/*   Updated: 2022/11/05 18:23:46 by mpezongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	i;
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s2 && s1)
		return (free(s1), NULL);
	if (!s1)
		return (NULL);
	len1 = ft_strlen(s1);
	str = (char *)malloc((len1 + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (free(s1), NULL);
	i = -1;
	while (s1[++i] != '\0')
		str[i] = s1[i];
	i = -1;
	while (s2[++i] != '\0')
		str[len1 + i] = s2[i];
	str[len1 + i] = '\0';
	return (free(s1), str);
}

char	*ft_get_print_line(char *str)
{
	int		i;
	char	*new_line;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	new_line = malloc(sizeof(char) * (i + 1));
	if (!new_line)
		return (0);
	i = -1;
	while (str[++i] && str[i] != '\n')
		new_line[i] = str[i];
	if (str[i] == '\n')
	{
		new_line[i] = '\n';
		i++;
	}
	new_line[i] = '\0';
	return (new_line);
}

char	*ft_rest_line(char *str)
{
	int		i;
	char	*rest_line;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (0);
	}
	rest_line = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!rest_line)
		return (free(str), NULL);
	while (str[++i])
	{
		rest_line[j] = str[i];
		j++;
	}
	rest_line[j] = '\0';
	free(str);
	return (rest_line);
}
