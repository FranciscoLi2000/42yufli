#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	unsigned int	i;
	char			*substr;

	if (start >= (unsigned int)ft_strlen(s))
	{
		substr = malloc(sizeof(char));
		if (substr == NULL)
			return (NULL);
		substr[0] = '\0';
		return (substr);
	}
	if (len > (unsigned int)ft_strlen(s) - start)
		len = (unsigned int)ft_strlen(s) - start;
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL || s == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
