#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (((char *)str1)[i] != ((char *)str2)[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	return (0);
}
