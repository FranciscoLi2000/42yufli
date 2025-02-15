#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	write(fd, s, len);
}
