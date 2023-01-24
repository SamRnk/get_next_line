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

char    *ft_strjoin(char *stash, char const *buffer)
{
        size_t  s_len;
        size_t  b_len;
        char    *new_str;

        s_len = ft_strlen(stash);
        b_len = ft_strlen(buffer);
        new_str = malloc(sizeof(char) * s_len + b_len + 1);
        if (!new_str)
                return (NULL);
        ft_strlcpy(new_str, stash, s_len + 1);
        ft_strlcat(new_str, buffer, s_len + b_len + 1);
	free(stash);
        return (new_str);
}

char	*stash_until_newline(int fd, char *stash, ssize_t read_chars)
{
	char	*buffer;
	
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	while (!has_newline(buffer) && read_chars != 0)
	{
		read_chars = read(fd, buffer, BUFFER_SIZE);
		if (read_chars == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[read_chars] = '\0';
		printf("%s|", buffer);
		stash = ft_strjoin(stash, buffer);
	}
	free(buffer);
	return (stash);
}

char	*make_line(char *line, char *stash)
{
	size_t	i;

	i = pos_newline(stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	ssize_t		read_chars;

	if (fd < 0 || BUFFER_SIZE <= 0  || read(fd, line, 0) < 0)
		return (NULL);
	if (stash == NULL)
	{
		stash = malloc(sizeof(char) * 1);
		stash[0] = '\0';
	}
	read_chars = 1;
	stash = stash_until_newline(fd, stash, read_chars);
	if (stash == NULL)
		return (NULL);
	if (read_chars == 0)
		line = stash;
	else
		line = make_line(line, stash);
	return (stash);
}

int	main(void)
{
	int	fd;
	
	fd = open("test.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close(fd);
	return (0);
}
