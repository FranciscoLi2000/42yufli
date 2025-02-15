#include "libft.h"

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;

	if (dest == src)
		return (dest);
	if (((char *)dest > (const char *)src) && ((char *)dest < ((const char *)src + n)))
	{
		i = n;
		while (i > 0)
		{
			i--;
			((char *)dest)[i] = ((const char *)src)[i];
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char *)dest)[i] = ((const char *)src)[i];
			i++;
		}
	}
	return (dest);
}
