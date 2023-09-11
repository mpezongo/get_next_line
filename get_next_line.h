/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpezongo <mpezongo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:51:11 by mpezongo          #+#    #+#             */
/*   Updated: 2022/11/05 18:36:04 by mpezongo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
// # include <sys/uio.h>
# include <unistd.h>

int		ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_get_print_line(char *str);
char	*ft_rest_line(char *str);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*ft_read_and_put(int fd, char *str);

#endif
