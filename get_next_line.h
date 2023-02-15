/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sreerink <sreerink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/15 03:38:59 by sreerink      #+#    #+#                 */
/*   Updated: 2023/02/15 03:39:04 by sreerink      ########   odam.nl         */
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

size_t	pos_newline(char *str);

size_t	gnl_strlen(char *str);

void	copy_str(char *dst, char *src, size_t size);

char	*gnl_strjoin(char *dst, char *src);

#endif
