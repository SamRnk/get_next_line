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

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);

size_t	pos_newline(char *str);

size_t	gnl_strlen(char *str);

void	copy_str(char *dst, char *src, size_t size);

char	*gnl_strjoin(char *dst, char *src);

#endif
