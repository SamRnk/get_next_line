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

char	*get_next_line(int fd)
{
	char			*line_return;
	char			*str_buffer;
	static size_t	i;

	str_buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str_buff)
		return (NULL);
	str_buff[BUFFER_SIZE] = '\0';
	read(fd, str_buff, BUFFER_SIZE);
	i = ft_strchr(str_buff, '\n');
	if (i != 0)
	return (line_return);
}

int	main(void)
{
	int	fd;
	int	i;
	
	i = 0;
	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
