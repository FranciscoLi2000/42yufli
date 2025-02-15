#include "libft.h"

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int	i;
	void			*ptr;

	if (size != 0 && nmemb > (unsigned int)(-1) / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while ((unsigned int)i < nmemb * size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
