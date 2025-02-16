#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	dst_len = 0;
	while (dst[dst_len] != '\0' && dst_len < siz)
		dst_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dst_len >= siz)
		return (siz + src_len);
	while (src[i] != '\0' && (dst_len + i + 1) < siz)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
