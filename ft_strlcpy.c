#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	len;

	len = 0;
	while (src[len] != '\0')
		len++;
	if (siz == 0)
		return (len);
	i = 0;
	while (src[i] != '\0' && i < siz - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
