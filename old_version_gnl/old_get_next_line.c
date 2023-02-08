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
//#include	<stdio.h>

char	*ft_strjoin(char *dst, char *src)
{
	size_t	dst_len;
	size_t	src_len;
	char	*new_str;

	if (dst == NULL)
	{
		dst = malloc(sizeof(char) * 1);
		dst[0] = '\0';
	}
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	new_str = malloc(sizeof(char) * (dst_len + src_len + 1));
	if (!new_str)
	{
		free_mallocs(dst, src);
		return (NULL);
	}
	ft_strlcpy(new_str, dst, dst_len + 1);
	ft_strlcpy(new_str + dst_len, src, src_len + 1);
	free(dst);
	return (new_str);
}

char	*stash_until_newline(int fd, char *stash, ssize_t *read_chars)
{
	char	*buffer;

	*read_chars = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(stash), NULL);
	buffer[0] = '\0';
	while (!has_newline(buffer) && *read_chars != 0)
	{
		*read_chars = read(fd, buffer, BUFFER_SIZE);
		if (*read_chars == -1)
		{
			free_mallocs(buffer, stash);
			return (NULL);
		}
		buffer[*read_chars] = '\0';
//		printf("%s|", buffer);
		stash = ft_strjoin(stash, buffer);
		if (stash == NULL)
			return (NULL);
	}
	free(buffer);
	return (stash);
}

char	*make_temp(char *temp, char *stash)
{
	size_t	pos;

	pos = pos_newline(stash);
	temp = NULL;
	temp = ft_strjoin(temp, stash + pos + 1);
	if (temp == NULL)
		return (NULL);
	return (temp);
}

char	*make_line(char *line, char *stash)
{
	size_t	pos;

	pos = pos_newline(stash);
	line = NULL;
	stash[pos + 1] = '\0';
	line = ft_strjoin(line, stash);
	if (line == NULL)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*temp = NULL;
	char		*line = NULL;
	ssize_t		read_chars;

//	printf("stash begin = %s|", stash);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) < 0)
		return (NULL);
	stash = stash_until_newline(fd, stash, &read_chars);
	if (read_chars == 0 && stash[pos_newline(stash)] != '\n')
		return (free(stash), NULL);
//	printf("stash = %s|", stash);
	if (stash == NULL)
		return (NULL);
	temp = make_temp(temp, stash);
	if (temp == NULL)
		return (free(stash), NULL);
//	printf("temp = %s|", temp);
	line = make_line(line, stash);
	if (line == NULL)
		return (free(stash), NULL);
	free(stash);
	stash = NULL;
	stash = ft_strjoin(stash, temp);
	if (stash == NULL)
		return (free(line), NULL);
	free(temp);
//	printf("line = %s|", line);
//	printf("stash end = %s|", stash);
	return (line);
}
/*
int	main(void)
{
	int	fd;
	char	*line;
	
	fd = open("test1.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("LINE FROM GNL = %s|", line);
		free(line);
		line = get_next_line(fd);
	}
	printf("%s", line);
	free(line);
	close(fd);
	return (0);
}*/
