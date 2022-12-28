/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sreerink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/18 02:16:18 by sreerink      #+#    #+#                 */
/*   Updated: 2022/12/22 22:00:40 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	<stdio.h>

char	*read_and_make_line(int fd, char *read_buffer)
{
	ssize_t	n_chars;



char	*get_next_line(int fd)
{
	static char	*read_buffer;
	char		*line_return;

	read_buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
		return (NULL);
	read_buffer[BUFFER_SIZE] = '\0';
	line_return = read_and_make_line(fd, read_buffer);
}

int	main(void)
{
	int	fd;
	
	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
