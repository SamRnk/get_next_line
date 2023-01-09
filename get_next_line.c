/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sreerink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/18 02:16:18 by sreerink      #+#    #+#                 */
/*   Updated: 2023/01/09 21:22:43 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	<stdio.h>

char	*read_and_make_line(int fd, char *buffer)
{
	static char	*read_text;
	char		*line;
	ssize_t		n_chars;
	while (!ft_strchr(read_text, '\n'))
	{


char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line_return;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	line_return = read_and_make_line(fd, buffer);
}

int	main(void)
{
	int	fd;
	
	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
