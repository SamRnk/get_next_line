#include	"get_next_line_bonus.h"
//#include	<stdio.h>

void	afternwl_to_line(char **line, char **after_nwl)
{
	*line = gnl_strjoin(*line, *after_nwl);
	free(*after_nwl);
	*after_nwl = NULL;
	return ;
}

void	read_and_stack(char **line, int fd, ssize_t *chars_read)
{
	char	buffer[BUFFER_SIZE + 1];

	while (!pos_newline(*line))
	{
		*chars_read = read(fd, buffer, BUFFER_SIZE);
		if ((*chars_read == -1) || (*chars_read == 0 && *line == NULL))
		{
			free(*line);
			*line = NULL;
			return ;
		}
		if (*chars_read == 0)
			return ;
		buffer[*chars_read] = '\0';
		*line = gnl_strjoin(*line, buffer);
		if (*line == NULL)
			return ;
	}
}

void	make_line_and_afternwl(char **line, char **after_nwl, size_t pos)
{
	char	*temp;

	*after_nwl = gnl_strjoin(*after_nwl, *line + pos);
	if (*after_nwl == NULL)
	{
		free(*line);
		*line = NULL;
		return ;
	}
	temp = malloc(sizeof(char) * (pos + 1));
	if (!temp)
	{
		free(*line);
		free(*after_nwl);
		*line = NULL;
		*after_nwl = NULL;
		return ;
	}
	copy_str(temp, *line, pos);
	free(*line);
	*line = temp;
}

char	*get_next_line(int fd)
{
	ssize_t		chars_read;
	size_t		pos;
	char		*line;
	static char	*after_nwl[FOPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	line = NULL;
	chars_read = 1;
	if (after_nwl[fd] != NULL)
	{
		afternwl_to_line(&line, &after_nwl[fd]);
		if (line == NULL)
			return (NULL);
	}
	read_and_stack(&line, fd, &chars_read);
	if (line == NULL)
		return (free(after_nwl[fd]), NULL);
	pos = pos_newline(line);
	if (chars_read == 0 || line[pos] == '\0')
		return (line);
	make_line_and_afternwl(&line, &after_nwl[fd], pos);
	return (line);
}
/*
int	main(void)
{
	int	fd[2];
	size_t	i;
	size_t	j;
	char	*str = "!";

	i = 0;
	j = 1;
	fd[1] = open("txt_files/test1.txt", O_RDONLY);
	fd[2] = open("txt_files/justnwl.txt", O_RDONLY);
	while (str != NULL)
	{
		str = get_next_line(fd[j]);
		printf("line from gnl =|%s|\n", str);
		free(str);
		i++;
		if (j == 1)
			j++;
		else
			j--;
	}
	close(fd[1]);
	close(fd[2]);
	printf("Total of printed lines: %lu (inlcuding (null) as a line)\n", i);
	return (0);
}*/
