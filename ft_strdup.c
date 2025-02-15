#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	int		i;
	int		len;

	len = ft_strlen(s);
	if (s == 0)
		return (0);
	dst = malloc((len + 1) * sizeof(char));
	if (dst == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
