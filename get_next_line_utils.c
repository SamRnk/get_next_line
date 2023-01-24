#include	"get_next_line.h"

int	has_newline(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	if (size != 0 && dstlen < size)
		ft_strlcpy(dst + dstlen, src, size - dstlen);
}
