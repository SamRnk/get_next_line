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

char    *ft_strjoin(char *stash, char *buffer)
{
        size_t  s_len;
        size_t  b_len;
        char    *new_str;

        s_len = ft_strlen(stash);
        b_len = ft_strlen(buffer);
        new_str = malloc(sizeof(char) * s_len + b_len + 1);
        if (!new_str)
	{
		free(stash);
		free(buffer);
                return (NULL);
	}
        ft_strlcpy(new_str, stash, s_len + 1);
        ft_strlcat(new_str, buffer, s_len + b_len + 1);
	free(stash);
        return (new_str);
}

char	*stash_until_newline(int fd, char *stash)
{
	char	*buffer;
	ssize_t	read_chars;
	
	read_chars = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(stash), NULL);
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
		if (stash == NULL)
			return (NULL);
	}
	free(buffer);
	return (stash);
}

char	*make_line(char *line, char *stash)
{
	size_t	pos;
	char	*temp;

	pos = pos_newline(stash);
	line = malloc(sizeof(char) * 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	temp = malloc(sizeof(char) * 1);
	if (!temp)
		return (NULL);
	temp[0] = '\0';
	printf("stash = %s|", stash);
	temp = ft_strjoin(temp, stash + pos + 1);//Could go wrong if pos is '\0', keep checking.
	if (temp == NULL)
		return (NULL);
	printf("temp = %s|", temp);
	stash[pos + 1] = '\0';
	line = ft_strjoin(line, stash);
	if (line == NULL)
		return (free(temp), NULL);
	stash = ft_strjoin(stash, temp);
	if (stash == NULL)
		return (NULL);
	printf("stash = %s|", stash);
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0  || read(fd, line, 0) < 0)
		return (NULL);
	if (stash == NULL)
	{
		stash = malloc(sizeof(char) * 1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = stash_until_newline(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = make_line(line, stash);
	if (line == NULL)
	{
		free(stash);
		free(line);
		return (NULL);
	}
	printf("stash = %s|", stash);
	return (line);
}

int	main(void)
{
	int	fd;
	
	fd = open("test1.txt", O_RDONLY);
	printf("line = %s|", get_next_line(fd));
	close(fd);
	return (0);
}
