/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: sreerink <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/18 02:16:18 by sreerink      #+#    #+#                 */
/*   Updated: 2022/12/20 23:32:58 by sreerink      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include	"get_next_line.h"
#include	<stdio.h>

char	*get_next_line(int fd)
{

}

int	main(void)
{
	int	fd;
	int	i;
	
	i = 0;
	fd = open("test.txt", O_RDONLY);
	if (!fd)
		return (1);
	get_next_line(fd);
	return (0);
}
