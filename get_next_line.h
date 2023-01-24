/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sreerink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/20 17:26:07 by sreerink      #+#    #+#                 */
/*   Updated: 2023/01/09 18:32:17 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);

int	has_newline(char *str);

size_t	pos_newline(char *str);

size_t	ft_strlen(const char *s);

void	ft_strlcpy(char *dst, const char *src, size_t size);

void	ft_strlcat(char *dst, const char *src, size_t size);

#endif
