/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: sreerink <sreerink@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/15 03:39:34 by sreerink      #+#    #+#                 */
/*   Updated: 2023/02/15 03:39:36 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line_bonus.h"

// returns index of '\n' + 1

size_t	pos_newline(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

size_t	gnl_strlen(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	copy_str(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*gnl_strjoin(char *dst, char *src)
{
	size_t	dst_len;
	size_t	src_len;
	char	*new_str;

	dst_len = gnl_strlen(dst);
	src_len = gnl_strlen(src);
	new_str = malloc(sizeof(char) * (dst_len + src_len + 1));
	if (!new_str)
		return (free(dst), NULL);
	copy_str(new_str, dst, dst_len);
	free(dst);
	copy_str(new_str + dst_len, src, src_len);
	return (new_str);
}
